
import cv2
import sys
import serial
import time

py_serial = serial.Serial(
    port = 'COM4',
    baudrate = 115200,
)

# 비디오 파일 열기
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print('Video open failed!')
    sys.exit()

# 배경 영상 등록
ret, back = cap.read()

if not ret:
    print('Background image registration failed!')
    sys.exit()
    
# 연산 속도를 높이기 위해 그레이스케일 영상으로 변환
back = cv2.cvtColor(back, cv2.COLOR_BGR2GRAY)

# 가우시안 블러로 노이즈 제거 (모폴로지, 열기, 닫기 연산도 가능)
back = cv2.GaussianBlur(back, (0, 0), 1.0)

# 비디오 매 프레임 처리
while True:
    ret, frame = cap.read()
    
    if not ret:
        break
    
    # 현재 프레임 영상 그레이스케일 변환
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # 노이즈 제거
    gray = cv2.GaussianBlur(gray, (0, 0), 1.0)
    
    # 차영상 구하기 $ 이진화
    # absdiff는 차 영상에 절대값
    diff = cv2.absdiff(gray, back)
    # 차이가 30이상 255(흰색), 30보다 작으면 0(검정색)
    _, diff = cv2.threshold(diff, 255/2, 255, cv2.THRESH_BINARY)
    
    # 레이브링을 이용하여 바운딩 박스 표시
    cnt, _, stats, _ = cv2.connectedComponentsWithStats(diff)
    for i in range(1, cnt):
        x, y, w, h, s = stats[i]
        
        if s < 100:
            continue
        elif s >= 100 :
            print("detect")
            py_serial.write(b'1')
            
        cv2.rectangle(frame, (x, y, w, h), (0, 0, 255), 2)
  
    
    cv2.imshow('frame', frame)
    cv2.imshow('diff', diff)

    key = cv2.waitKey(30)
    if key == 27: # ESC 키를 눌러 종료
        break
    elif key == ord('q') or key == ord('Q'): # q 키를 눌러 종료
        break
    
    back = gray.copy()

cap.release()
cv2.destroyAllWindows()