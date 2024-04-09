# 각종 필터 비교
import cv2
import numpy as np
# 기본 틀
cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 400)
# 동영상 (무한루프)
while True:
    ret, frame = cap.read()
    if not ret:
        print("Capture Failure")
        break
    # frame에 salt & papper 노이즈 생성
    noise = np.uit8(np.random.normal(loc=0, scale=0.4, size=frame.shape))
    noised_img = cv2.add(frame, noise) #노이즈 적용
    # Blur 필터 적용 영상 (커널 마스크 크기 5x5 행렬. 주변 24개 픽셀과의 평균값으로 Blur 적용함)
    blur = cv2.blur(noised_img, (5, 5))
    # 가우시안 Blur: 그냥 blur보다는 외곽선이 살아남. 표준편자 0: 좁고 선명. 크면 넓고 흐릿.
    gaussian = cv2.GaussianBlur(noised_img, (5,5), 0)
    # bilateral 필터: 가우시안 필터보다 외곽선이 더 살아남. 공간적 거리와 픽셀값의 차이를 모두 고려하여 필터링을 해줌.
    bilateral = cv2.bilateralFilter(noised_img, 9, 75, 75)
    # Median Blur: salt & papper 노이즈 제거에 탁월. 외곽선도 좋은 편. (중앙값을 적용해줌)
    median = cv2.medianBlur(noised_img, 5)
    # 원본 영상(비교용)
    cv2.imshow("Original", frame)
    # 노이즈 적용 영상
    cv2.imshow("Noised", noised_img)
    # Blur 필터 적용 영상
    cv2.imshow("Blur", blur)
    # gaussian blur 적용 영상
    cv2.imshow("Gaussian", gaussian)
    # bilatera 적용 영상
    cv2.imshow("Bilateral", bilateral)
    # Median blur 적용 영상
    cv2.imshow("Median", median)
    # 여러 영상을 하나로 합쳐 보기
    row1 = cv2.hconcat([frame, noised_img, blur])
    row2 = cv2.hconcat([gaussian, bilateral, median])
    total1 = cv2.vconcat([row1, row2])
    cv2.imshow("All", total1)
    if cv2.waitKey(1) == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()