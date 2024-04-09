import cv2

img = cv2.imread("opencv/images.png")
cv2.imshow('opencv/images.png', img)
cv2.waitKey(0)
cv2.imwrite('ball2.png', img)

img_grey = cv2.cvtColor(img , cv2.COLOR_BGR2GRAY)
cv2.imshow("Gray", img_grey)
cv2.waitKey(0)
cv2.imwrite('ball2_grey.png', img_grey)