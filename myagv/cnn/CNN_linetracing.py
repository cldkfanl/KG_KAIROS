import cv2
import numpy as np
from keras.models import load_model
from pymycobot.myagv import MyAgv
import threading
import time

# 전역 변수로 현재 방향을 저장할 변수 정의
current_direction = "STOP"

# 모델 불러오기
model = load_model('woo/keras_agv_model.h5')

# 카메라 프레임 처리 함수
def process_frame(frame):
    global current_direction
    
    # 이미지 크기 조정
    resized_frame = cv2.resize(frame, (160, 120))
    
    # 모델 입력 형식에 맞게 변경
    input_image = np.expand_dims(resized_frame, axis=0)
    
    # 모델 예측
    prediction = model.predict(input_image)
    
    # 예측 결과에 따라 이동 방향 결정
    if np.argmax(prediction) == 0:  # forward
        direction = "FORWARD"
    elif np.argmax(prediction) == 1:  # right
        direction = "RIGHT"
    elif np.argmax(prediction) == 2:  # left
        direction = "LEFT"
    else:
        direction = "STOP"
    
    # 현재 방향을 전역 변수에 저장
    current_direction = direction

# AGV 제어 함수
def control_agv():
    MA = MyAgv('/dev/ttyAMA2', 115200)

    while True:
        # 현재 방향에 따라 AGV 제어
        if current_direction == "LEFT":
            MA.counterclockwise_rotation(1,1/4)
            print('left')
        elif current_direction == "RIGHT":
            MA.clockwise_rotation(1,1/4)
            print('right')
        elif current_direction == "FORWARD":
            MA.go_ahead(10,1)
            print('forward')
        elif current_direction == "STOP":
            MA.stop()
            print('stop')
            time.sleep(1)

# 카메라 스레드 함수
def camera_thread():
    cap = cv2.VideoCapture(0)
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Camera error")
            break

        # 프레임 처리하여 방향 결정
        process_frame(frame)

        cv2.imshow("Frame", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

# 메인 스레드에서 카메라 스레드 실행
camera_thread2 = threading.Thread(target=camera_thread)
camera_thread2.start()

# AGV 제어 스레드 실행
agv_thread = threading.Thread(target=control_agv)
agv_thread.start()

# 카메라 스레드와 AGV 제어 스레드가 종료될 때까지 대기
camera_thread2.join()
agv_thread.join()
