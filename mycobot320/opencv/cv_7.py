# 영상 조정 코드(색상, 밝기, 대비, 사이즈)
import cv2
import numpy as np
#1. 색상 변경 함수
def color_filter(img, color, scale): # 이미지, 색상, 비율
    dst = np.array(img, np.uint8) # 입력 영상 np로 복제
    if color == 'blue' or color == 0: # 파란색 비율 변경
        # ([가로 모든열, 세로 모든행, 0=파란색]) * 비율
        dst[:, :, 0] = cv2.multiply(dst[:, :, 0], scale)
    elif color == 'green' or color == 1: #초록색
        dst[:, :, 1] = cv2.multiply(dst[:, :, 1], scale)
    elif color == 'red' or color == 2: # 빨간색
        dst[:, :, 2] = cv2.multiply(dst[:, :, 2], scale)
    return dst # 이미지 편집된 np 배열값
#2. 밝기 변환 함수
def set_brightness(img, scale): #(이미지, 밝기 변환값)
    return cv2.add(img, scale)
#3. 대비 변경 함수
def set_contrast(img, scale):
    return np.uint8(np.clip((1+scale)*img - 128*scale, 0, 255))
#4. 이미지 사이즈 변경 함수
def set_size(img, scale):
    return cv2.resize(img, dsize=(int(img.shape[1]*scale), int(img.shape[0]*scale)), interpolation=cv2.INTER_AREA)
# 화면으로 보기
cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
while True:
    ret, frame = cap.read()
    # 원본 이미지
    cv2.imshow("Original", frame)
    # # 빨간색 강조 이미지 구현
    # redFilter = color_filter(frame, 'red', 1.2)
    # cv2.imshow("Redder", redFilter)
    # # 20픽셀 밝아진 이미지 구현
    # brightness = set_brightness(frame, 20)
    # cv2.imshow("Brighter", brightness)
    # # 대비를 0.9로 변경한 이미지 구현
    # contra = set_contrast(frame, 0.9)
    # cv2.imshow("Contrast", contra)
    # 사이즈 2배로
    bigger = set_size(frame, 2)
    cv2.imshow("Bigger", bigger)
    if cv2.waitKey(1) == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()