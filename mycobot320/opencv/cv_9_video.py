import cv2
import datetime
import numpy as np
from PIL import ImageFont, ImageDraw, Image


cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

font = ImageFont.truetype("SCDream6.otf", 30)
fourcc = cv2.VideoWriter_fourcc(*'XVID')
is_record = False
while True:
    ret, frame = cap.read()

    t_now = datetime.datetime.now()
    t_str = t_now.strftime('%Y/%m/%d %H:%M:%S')
    t_str_path = t_now.strftime('%Y %m %d %H %M %S')


    cv2.rectangle(img = frame, pt1 = (10,15), pt2 = (350,35), color=(0,0,0), thickness = -1)

    

    flipped_frame = cv2.flip(frame, 1)
    flipped_frame = Image.fromarray(flipped_frame)
    draw = ImageDraw.Draw(flipped_frame)
    draw.text (xy=(10,15), text = "I see you" + t_str, font = font, fill = (255, 255, 255))

    flipped_frame = np.array(flipped_frame)

    cv2.imshow("CCTV", flipped_frame)
    
    key = cv2.waitKey(30)


    if key == ord('r') and is_record == False:
        is_record = True

        cv2.circle(img=flipped_frame, center = (620.15), radius= 5, color=(0,0,255), thickness= -1)
        video_ = cv2.VideoWriter("cap" + t_str_path + ".avi", fourcc, 15, (frame.shape[1], frame.shape[0]))
        cv2.imshow("CCTV", flipped_frame)
    elif key == ord('r') and is_record == True:
        is_record = False
        video_.release()
    elif key == ord('c') :
        cv2.imwrite("pic " + t_str_path + ".jpg", flipped_frame)
    elif key == ord('q'):
        break