from ultralytics import YOLO
import cv2
from pymycobot.mycobot import MyCobot
import time

red_state = 0
yellow_state = 0
blue_state = 0
block_height = 23
default_height = 330
block_name = ['Blue', 'Orange', 'Purple', 'Yellow']
red_cor = [40, 160, 180, 180, 0, 90]
yellow_cor = [40, 210, 180, 180, 0, 90]
blue_cor = [40, -200, 180, 180, 0, 90]
camera_cor = [160, 80, 330, 180, 0, 0]
grap_cor = [200, 80, 330, 180, 0, 0]
mc = None

def gripper_use2():
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(1)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(80, 50)
    print("Gripper activated.")
    time.sleep(1)
    state = mc.get_coords()
    mc.send_coords([state[0], state[1], default_height, state[3], state[4], state[5]], 40, 1)
    time.sleep(2)
    print("Moved to default height.")
    gripper_use()



def gripper_use() :
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(1)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(50,50)
    time.sleep(1)
    
    mc.send_coords(camera_cor, 40, 1) # Initial positioning to camera_cor
    time.sleep(2)


def gripper_close():
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(1)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(10,50)
    time.sleep(1)


def move_block(block_color):
    global red_state, yellow_state, blue_state
    coords_map = {'Orange': red_cor, 'Yellow': yellow_cor, 'Blue': blue_cor}
    state_map = {'Orange': red_state, 'Yellow': yellow_state, 'Blue': blue_state}
    
    cor = coords_map[block_color]
    state = state_map[block_color]
    mc.send_coords(grap_cor, 40, 1)
    time.sleep(2)
    mc.send_coords([grap_cor[0], grap_cor[1], grap_cor[2] - 35, grap_cor[3], grap_cor[4], grap_cor[5]], 40, 1)
    time.sleep(2)
    gripper_close()
    time.sleep(2)
    mc.send_coords(grap_cor, 40, 1)
    time.sleep(2)

    mc.send_coords([cor[0], cor[1], default_height, cor[3], cor[4], cor[5]], 40, 1)
    time.sleep(5)
    mc.send_coords([cor[0], cor[1], cor[2] + block_height * state, cor[3], cor[4], cor[5]], 40, 1)
    time.sleep(3)
    gripper_use2()
    
    if block_color == 'Red':
        red_state += 1
        print(f"{block_color.capitalize()} block moved.")
    elif block_color == 'Yellow':
        yellow_state += 1
        print(f"{block_color.capitalize()} block moved.")
    elif block_color == 'Blue':
        blue_state += 1
        print(f"{block_color.capitalize()} block moved.")

    print("red_state:", red_state, "yellow_state:", yellow_state, "blue_state:", blue_state)

    mc.send_coords(camera_cor, 40, 1)

class VideoObjectDetection:
    def __init__(self, model_path):
        # YOLO 모델 초기화
        self.model = YOLO(model_path)
        # 카메라 초기화
        self.cap = cv2.VideoCapture(0)  # 0은 기본 웹캠, 1은 외부 카메라 등 번호 조정

    def start_detection(self):
        # 카메라가 오픈 되었는지 확인
        if not self.cap.isOpened():
            print("Cannot open camera")
            return
        
        
        while self.cap.isOpened():
            ret, frame = self.cap.read()
            if ret:
                # 모델을 사용한 객체 감지
                results = self.model(frame)
                top_rate_object = None
                if len(results) > 0:
                    for result in results:
                        for box in result.boxes:
                            boxes = box.cpu().numpy()
                            conf = boxes.conf
                            class_id = int(boxes.cls[0])
                            if conf > 0.7:
                                top_rate_object = class_id
                                plotted_image = results[0].plot()
                                cv2.imshow("Results", plotted_image)
                                displayed = True
                                break
                        if displayed:
                            break
                if not displayed:
                    # 고신뢰도 객체가 없을 경우 원본 이미지 출력
                    cv2.imshow("Results", frame)
                move_block(block_name[((int)(top_rate_object))])


                # 'q'를 눌러 감지 종료
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            else:
                print("Failed to grab frame")
                break

        self.stop_detection()

    def stop_detection(self):
        # 자원 해제
        self.cap.release()
        cv2.destroyAllWindows()

def main() :
    global mc
    port = 'COM3'
    baudrate = 115200
    mc = MyCobot(port, baudrate)
    mc.send_coords(camera_cor, 40, 1)
    detector = VideoObjectDetection("best_ver3.pt")
    detector.start_detection()




# 사용 예
if __name__ == '__main__':
    main()

