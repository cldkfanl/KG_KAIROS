from pymycobot.mycobot import MyCobot
import time
import cv2

def main():
    global mc
    # MyCobot 로봇과의 연결 설정
    port = 'COM3'  # MyCobot이 연결된 포트 (Linux 기준, Windows는 'COM#' 형식)
    baudrate = 115200      # 통신 속도
    # MyCobot 객체 생성
    mc = MyCobot(port, baudrate)


    next_coords = [40, -200, 330, 180, 0, 90]

    mc.send_coords(next_coords, 30, 1)
    # # 엔드이펙터 좌표 출력
    # print("Current end effector coordinates:", current_coords)

    # 프로그램 종료 전에 잠시 대기
    time.sleep(1)

if __name__ == '__main__':
    main()
