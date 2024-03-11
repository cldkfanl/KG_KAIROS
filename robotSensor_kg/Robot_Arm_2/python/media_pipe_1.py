import cv2

cap = cv2.VideoCapture(0)
cap.set(3,640)
cap.set(4,480)

while cap.isOpened():
    ret, image = cap.read()
    cv2.imshow("My cam",image)

    key = cv2.waitKey(1)
    if(key == ord('q') or key == 27):
        break
cap.release()

cv2.destroyAllWindows()
