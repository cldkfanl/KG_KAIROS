import cv2
import numpy as np
import threading
from pymycobot.myagv import MyAgv

# 카메라 캡처 객체 생성
cap = cv2.VideoCapture(0)
# agv = MyAgv("/dev/ttyAMA2", 115200)


# 프레임 처리 함수
def process_frame(frame):
    height, width, _ = frame.shape
    roi_height = int(height / 4)
    roi_width = int(width / 5)
    lower_yellow = np.array([20, 100, 100], dtype=np.uint8)
    upper_yellow = np.array([30, 255, 255], dtype=np.uint8)

    roi = frame[height - roi_height * 2:, :]
    hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
    # 색상 변화 및 이진화
    fir, sec = -1, -1
    yellow_mask = cv2.inRange(hsv, lower_yellow, upper_yellow)
    
    for i in range(2) :
        for j in range(5) :
            roi_range = yellow_mask[yellow_mask.shape[0] * i : yellow_mask.shape[0] * (i+1) , roi_width * j:roi_width * (j + 1)]
            contours, _ = cv2.findContours(roi_range, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            if contours :
                if i == 0 :
                    fir = j
                else :
                    sec = j

    print(fir, sec)
    if fir == -1 and sec == -1 :
        return "Stop"
    elif fir == sec :
        return "Center"
    elif fir < sec :
        return "Left"
    elif fir > sec :
        return "Right"


# def control_robot(action):
#     if action == "Left":
#         print("Moving left")
#         agv.counterclockwise_rotation(10)
#     elif action == "Right":
#         print("Moving right")
#         agv.clockwise_rotation(10)
#     elif action == "Middle":
#         print("Moving forward")
#         agv.go_ahead(10)
#     elif action == "Stop":
#         print("Stopping")
#         agv.stop(10)


# 쓰레드 함수
def camera_thread():
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Camera error")
            break

        result = process_frame(frame)

        if result:
            print(result)
            # 로봇 제어 함수를 호출하는 쓰레드 생성
            # control_thread = threading.Thread(target=control_robot, args=(result,))
            # control_thread.start()
            
        cv2.imshow("Frame", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

# 메인 쓰레드에서 카메라 쓰레드 실행
camera_thread = threading.Thread(target=camera_thread)
camera_thread.start()

# 카메라 쓰레드가 종료될 때까지 대기
camera_thread.join()

# 캡처 객체 해제 및 윈도우 닫기
cap.release()
cv2.destroyAllWindows()