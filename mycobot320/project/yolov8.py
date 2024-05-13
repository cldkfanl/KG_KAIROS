from ultralytics import YOLO
import cv2
from pymycobot.mycobot import MyCobot

# YOLO 모델 로드
model = YOLO("mycobot320/project/best_ver4.pt")
mc = MyCobot('COM3',115200)

# 웹캠 캡처 시작
cap = cv2.VideoCapture(0)
camera_cor = [140, 43, 330, 180, 0, 0]
mc.send_coords(camera_cor, 40, 1)
while cap.isOpened():
    ret, frame = cap.read()
    
    if ret:
        # 이미지에 대한 예측 수행
        results = model.predict(frame)

        # 검출된 객체가 있는지 확인
        if len(results) > 0:
            for result in results:
                for tmp in result.boxes:
                    boxes = tmp.cpu().numpy()
                    conf = boxes.conf[0]
                    class_id = int(boxes.cls[0])  # 첫 번째 박스의 클래스 ID 추출
                    class_center = (int(boxes.xyxy[0][0] + (boxes.xyxy[0][2] - boxes.xyxy[0][0])/2), int(boxes.xyxy[0][1] + (boxes.xyxy[0][3] - boxes.xyxy[0][1])/2))
                    class_size = int(boxes.xyxy[0][2] - boxes.xyxy[0][0]) * int(boxes.xyxy[0][3] - boxes.xyxy[0][1])
                    if conf > 0.7 :
                        print(conf)
                        print(class_center)
                        print(class_size)      
            # 결과 이미지를 얻기 위해 plot 메서드 사용
                        plotted_image = results[0].plot()
                        cv2.imshow("Results", plotted_image)
                    else :
                        cv2.imshow("Results", frame)
        else:
            # 검출된 객체가 없을 경우 원본 이미지 출력
            cv2.imshow("Results", frame)

    else:
        print("Failed to grab frame")

    # 'q'를 누르면 루프 탈출
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 자원 해제
cap.release()
cv2.destroyAllWindows()
