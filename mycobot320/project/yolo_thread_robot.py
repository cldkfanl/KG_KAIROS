from ultralytics import YOLO
import cv2
import threading
from pymycobot.mycobot import MyCobot
import time

lock = threading.Lock()
mc = None
cap = None
# YOLO 모델 로드
model = YOLO("best_ver4.pt")
joint_cor = [92,0,-74,11,100,0]
camera_cor = [140, 80, 330, 180, 0, 0]
grap_cor = [140, 43, 315, 180, 0, 0]
block_height = 25
default_height = 330
block_max_height = 280

#block_name = 'Blue', 'Green, 'Orange', 'Purple', 'Yellow' 순서
block_cor = [[0,0,0,0,0,0], #Blue -> 버림
             [0,0,0,0,0,0], #Green -> 버림
             [40, 158, 178, 180, 0, 90],  #Orange -> 적재
             [40, 205, 181, 180, 0, 90],  #Purple -> 적재
             [40, 252, 184, 180, 0, 90]]  #Yellow -> 적재
block_state = [0, 0, 0, 0, 0]

# 카메라 캡처 객체 초기화

# 탐지 상태 설정
detect_box_state = False
detect_box_color = None
detect_box_y_value = None
shutdown_flag = False


def move_robot_arm(xyz, replace_mode, angle_num, angle_val) :
    tmp_angle = xyz[:]
    if replace_mode == 0 :
        tmp_angle[angle_num-1] = angle_val
    else :
        tmp_angle[angle_num-1] += angle_val

    mc.send_coords(tmp_angle, 70, 1)


def gripper_use2():

    gripper_use(80)
    state = mc.get_coords()
    move_robot_arm(state, 0, 3, block_max_height)
    time.sleep(0.9)
    print("Moved to default height.")
    gripper_use(50)
    mc.send_angles(joint_cor, 70)
    time.sleep(1.3)

def gripper_use(value):
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(0.5)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(value,60)
    time.sleep(0.8)

def handle_detection() :
    return True

def detection_task():
    global cap, detect_box_state, detect_box_color, shutdown_flag, detect_box_y_value
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("camera isnt open")
        return
    
    timer = None

    while cap.isOpened() and not shutdown_flag:
        ret, frame = cap.read()
        if ret:
            results = model.predict(frame)
            plotted_image = frame
            high_conf_detected = False

            if len(results) > 0 and results[0] is not None:
                for result in results:
                    for box in result.boxes:
                        boxes = box.cpu().numpy()
                        class_id = int(boxes.cls[0])
                        class_conf = boxes.conf
                        class_x = int((boxes.xyxy[0][0] + (boxes.xyxy[0][2] - boxes.xyxy[0][0])/2))
                        class_y = 170 + int((410 -(boxes.xyxy[0][1] + (boxes.xyxy[0][3] - boxes.xyxy[0][1])/2)) / 3.4)
                        if class_conf > 0.80 and class_id >= 2 and class_x > 200 and class_y > 170 and class_y < 250:
                            # 고신뢰도 결과가 있는 경우 결과를 표시
                            plotted_image = results[0].plot()
                            high_conf_detected = True
                            break  # 하나의 객체만 처리
                    if high_conf_detected and detect_box_state is False:
                        if timer is None:
                            timer = False
                            timer = threading.Timer(0.5, handle_detection)
                            timer.start()
                        elif timer :
                            detect_box_state = True
                            detect_box_color = class_id
                            detect_box_y_value = class_y
                            timer = None
                    
            cv2.imshow('YOLO', plotted_image)

            # 'q'를 누르면 루프 탈출
            if cv2.waitKey(1) & 0xFF == ord('q'):
                if timer:
                    timer.cancel()
                shutdown_flag = True
                break
    # 카메라 끄기
    cap.release()
    cv2.destroyAllWindows()

def robot_control_task():
    global block_state, detect_box_state, detect_box_color, detect_box_y_value ,shutdown_flag

    while not shutdown_flag:
        if detect_box_state and detect_box_color is not None:

            # 객체 잡기
            cor = block_cor[detect_box_color]
            state = block_state[detect_box_color]
            mc.send_coords(grap_cor, 70, 1)
            time.sleep(0.9)
            move_robot_arm(grap_cor,0,1,detect_box_y_value)
            time.sleep(0.9)
            gripper_use(10)
            time.sleep(0.9)
            tmp_arr = mc.get_coords()
            mc.send_coords([tmp_arr[0], tmp_arr[1], 330, tmp_arr[3], tmp_arr[4], tmp_arr[5]], 70, 1)
            time.sleep(0.9)
            mc.send_angles(joint_cor, 70)
            time.sleep(1.5)
            # 놓을 곳으로 이동하기
            move_robot_arm(cor, 0, 3, block_max_height)
            time.sleep(0.9)

            
            move_robot_arm(cor, 1, 3, block_height * state)
            time.sleep(1.2)
            gripper_use2()

            
            #상태 업데이트 후 원상 복귀
            block_state[detect_box_color] += 1

            mc.send_coords(camera_cor, 70, 1)
            time.sleep(1.3)
            detect_box_state = False
            detect_box_color = None

def main() :
# 로봇암 연결 & 시작 자세로 이동
    global mc
    port = 'COM3'
    baudrate = 115200
    mc = MyCobot(port, baudrate)
    mc.send_coords(camera_cor, 70, 1)
    time.sleep(1)   

# 스레드 생성 및 시작
    detection_thread = threading.Thread(target=detection_task)
    robot_thread = threading.Thread(target=robot_control_task)

    detection_thread.start()
    robot_thread.start()

    detection_thread.join()
    robot_thread.join()

if __name__ == '__main__':
    main()