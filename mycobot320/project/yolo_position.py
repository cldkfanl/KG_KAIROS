from ultralytics import YOLO
import cv2
import threading
import time
from pymycobot.mycobot import MyCobot

# lock = threading.Lock()
# cap = None
# YOLO 모델 로드
# model = YOLO("best_ver4.pt")
camera_cor = [171, 35, 330, 180, 0, 0]
# test_cor = [40, 140, 180, 180, 0, 90] 찾은값
test_cor = [40, 220, 180, 180, 0, 90]
joint_cor = [92,0,-74,11,100,0]
grap_cor = [200, 43, 315, 180, 0, 0]
def main() :
# 로봇암 연결 & 시작 자세로 이동

    global mc
    port = 'COM3'
    baudrate = 115200
    mc = MyCobot(port, baudrate)
    # mc.send_angles(joint_cor, 20)
    mc.send_coords(grap_cor, 40, 1)
    # time.sleep(2)
    # mc.send_coords([200, 70, 330, 180, 0, 0], 40, 1)
    # time.sleep(2)
    # mc.send_coords([test_cor[0], test_cor[1], 330, test_cor[3], test_cor[4], test_cor[5]], 40, 1)
    # time.sleep(5)
    # mc.send_coords(test_cor, 40, 1)
    # time.sleep(2)
    # mc.send_coords([test_cor[0], test_cor[1], 330, test_cor[3], test_cor[4], test_cor[5]], 40, 1)
    # time.sleep(3)
    # mc.send_coords(camera_cor, 40, 1)


# 스레드 생성 및 시작
    # detection_thread = threading.Thread(target=detection_task)

    # detection_thread.start()
    # detection_thread.join()

if __name__ == '__main__':
    main()