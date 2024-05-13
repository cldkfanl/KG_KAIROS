import cv2

# 카메라 객체 생성
cap = cv2.VideoCapture(0)  # 0은 기본 카메라를 의미합니다. 여러 카메라가 연결되어 있을 경우 인덱스를 조절하여 선택할 수 있습니다.

# 카메라가 오픈되었는지 확인
if not cap.isOpened():
    print("카메라를 열 수 없습니다.")
    exit()

# 카메라 프레임 읽기
while True:
    ret, frame = cap.read()  # ret은 프레임 읽기 성공 여부를 나타냅니다.

    # 프레임 읽기가 실패하면 루프를 종료합니다.
    if not ret:
        print("프레임을 읽을 수 없습니다.")
        break

    # 프레임 화면에 표시
    cv2.imshow('Camera', frame)

    # 'q' 키를 누르면 종료합니다.
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 작업이 끝나면 카메라 객체와 창을 닫습니다.
cap.release()
cv2.destroyAllWindows()
