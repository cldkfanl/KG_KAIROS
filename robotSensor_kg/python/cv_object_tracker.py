import cv2

tracker = cv2.TrackerKCF_create()
# 비디오 읽기
# cap = cv2.VideoCapture('vtest.avi')
cap = cv2.VideoCapture(0)
ret, frame = cap.read()

bbox = cv2.selectROI(frame, False)
while bbox == (0, 0, 0, 0):
    bbox = cv2.selectROI(frame, False)

# 추적기 초기화
ok = tracker.init(frame, bbox)

# 비디오 프레임을 불러와서 추적 실행
while True:
    ret, frame = cap.read()
    if not ret:
        cv2.destroyAllWindows()
        break

    # 추적 실행
    ret_tracker, bbox = tracker.update(frame)
    # 추적 결과 표시
    if ret_tracker:
        p1 = (int(bbox[0]), int(bbox[1]))
        p2 = (int(bbox[0] + bbox[2]), int(bbox[1] + bbox[3]))
        cv2.rectangle(frame, p1, p2, (0, 0, 255), 2, 1)
    else:
        cv2.putText(frame, 'Tracking failure', (10, 70), \
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

    # 추적 정보 표시
    cv2.putText(frame, 'CSRT Tracker', (10, 30), \
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
    cv2.imshow('Tracking', frame)
    k = cv2.waitKey(30)
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()