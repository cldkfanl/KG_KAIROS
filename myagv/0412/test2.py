from pymycobot.myagv import MyAgv
import threading
import cv2
import numpy as np

agv = MyAgv('/dev/ttyAMA2', 115200)

def trace_line(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower_yellow = np.array([20, 100, 50])
    upper_yellow = np.array([40, 255, 255])
    mask = cv2.inRange(hsv, lower_yellow, upper_yellow)
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    return bool(contours)


def camera_thread() :
    cap = cv2.VideoCapture(0)
    while True :

        ret, frame = cap.read()
        if not ret:
            print("Camera Error")
            break

        height, width, _ = frame.shape
        roi_height = int(height / 8)

        roi_start_width_right = int(width * 16 / 20)
        roi_end_width_right = int(width * 19 / 20)
        roi_right = frame[7 * roi_height:height, roi_start_width_right:roi_end_width_right]

        roi_start_width_middle = int(width * 4 / 20)
        roi_end_width_middle = int(width * 16 / 20)
        roi_middle = frame[7 * roi_height:height, roi_start_width_middle:roi_end_width_middle]

        roi_start_width_left = int(width * 1 / 20)
        roi_end_width_left = int(width * 4 / 20)
        roi_left = frame[7 * roi_height:height, roi_start_width_left:roi_end_width_left]

        result_right = trace_line(roi_right)
        result_middle = trace_line(roi_middle)
        result_left = trace_line(roi_left)

        if result_right:
            # cv2.imshow('Right ROI', roi_right)
            print("Right")
            agv.clockwise_rotation(15)



        if result_middle:
            # cv2.imshow('Middle ROI', roi_middle)
            print("Middle")
            agv.go_ahead(13)


        if result_left:
            # cv2.imshow('Left ROI', roi_left)
            print("Left")
            agv.counterclockwise_rotation(15)

        cv2.imshow('Frame', frame)

        if cv2.waitKey(2000) & 0xFF == ord('q'):
            break

    cap.release( )
    cv2.destroyAllWindows()

camera_thread = threading.Thread(target=camera_thread)
camera_thread.start()

camera_thread.join()



