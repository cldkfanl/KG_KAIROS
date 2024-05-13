import time
from pymycobot.mycobot import MyCobot

# 전역 변수 설정
grap_cor = [200, 40, 330, 180, 0, 0]
camera_cor = [160, 80, 330, 180, 0, 0]


def main():
    global mc
    port = 'COM3'  # MyCobot이 연결된 포트 (Windows 기준)
    baudrate = 115200  # 통신 속도
    mc = MyCobot(port, baudrate)
    mc.send_coords(grap_cor, 20, 1)
    time.sleep(3)
    mc.send_coords([200,40,300,180,0,0],20,1)

if __name__ == '__main__':
    main()
