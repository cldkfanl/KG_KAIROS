# 동영상 저장하기 (코덱 주의)
import cv2
cap = cv2.VideoCapture(0)
fourcc = cv2.VideoWriter_fourcc(*'XVID')
# (동영상파일명, 코덱 객체, 초당 프레임 수, (캡쳐된 이미지 크기))
writer = cv2.VideoWriter('output.avi', fourcc, 30.0, (640, 400))
while(True):
    ret, img_color = cap.read()
    if ret == False:
        continue
    # Gray Scale 이미지로 변환
    img_gray = cv2.cvtColor(img_color, cv2.COLOR_BGR2GRAY)
    cv2.imshow("Color", img_color)
    cv2.imshow('Gray', img_gray)
    if cv2.waitKey(1)&0xFF == 27:
        break
cap.release()
cv2.destroyAllWindows()