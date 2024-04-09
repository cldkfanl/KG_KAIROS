import cv2
import datetime
import numpy as np
from PIL import ImageFont, ImageDraw, Image


cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

font = ImageFont.truetype("SCDream6.otf", 30)

while True:
    ret, frame = cap.read()

    t_now = datetime.datetime.now()

    t_now_show = t_now.strftime('%Y/%m/%d %H:%M:%S')

    cv2.rectangle(img = frame, pt1 = (10,15), pt2 = (350,35), color=(0,0,0), thickness = -1)

    

    flipped_frame = cv2.flip(frame, 1)
    

    flipped_frame = Image.fromarray(flipped_frame)
    draw = ImageDraw.Draw(flipped_frame)
    draw.text (xy=(10,15), text = "I see you" + t_now_show, font = font, fill = (255, 255, 255))

    flipped_frame = np.array(flipped_frame)

    cv2.imshow("CCTV", flipped_frame)

    if(cv2.waitKey(1) == ord('q')):
        break