from pymycobot.myagv import MyAgv
import threading
import cv2
import numpy as np
import time
cap = cv2.VideoCapture(0)
agv = MyAgv('/dev/ttyAMA2', 115200)

move_dir = "stop"

def decide_direction(yellow_indices):
    if not yellow_indices.any():
        print("No yellow line detected. Stopping AGV.")
        return "stop"

    weights = np.arange(1, 9)
    
    agv_pos_sum_0 = np.mean(weights * yellow_indices[0])
    agv_pos_sum_2 = np.mean(weights * yellow_indices[2])

    if(agv_pos_sum_0 * 1.2 < agv_pos_sum_2):
        print("Go left")
        return "left"
    elif(agv_pos_sum_0 > agv_pos_sum_2 * 1.2):
        print("Go right")
        return "right"
    else:
        print("Go straight")
        return "forward"

def trace_line2(frame):
    lower_yellow = np.array([20, 100, 100])
    upper_yellow = np.array([30, 255, 255])

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask = cv2.inRange(hsv, lower_yellow, upper_yellow)
    result_0_array = np.zeros((1, 8), dtype=np.uint8)
    result_2_array = np.zeros((1, 8), dtype=np.uint8)

    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if contours:
        # Find the yellow regions and mark them in the result arrays
        for contour in contours:
            x, y, w, h = cv2.boundingRect(contour)
            # Determine the row corresponding to the center of the region
            center_row = 0 if (y + h // 2) < mask.shape[0] // 3 else 2
            # Skip processing if center_row is 1
            if center_row == 1:
                continue
            # Determine the column corresponding to the center of the region
            center_col = int((x + w // 2) / (mask.shape[1] // 8))
            # Assign value to the appropriate result array based on center_row
            if center_row == 0:
                result_0_array[0, center_col] = 1
            elif center_row == 2:
                result_2_array[0, center_col] = 1

    move_dir = decide_direction(np.concatenate((result_0_array, result_2_array)))

    return move_dir

def process_frame2(frame):
    height, width, _ = frame.shape
    roi_height = int(height / 3)
    roi_tmp = frame[height -roi_height:height, 0:width]
    control_thread = threading.Thread(target=trace_line2, args=(roi_tmp,))
    control_thread.start()

def moter_move() :
    if move_dir == "forward":
        agv.forward(2, 1/2)
    elif move_dir == "left":
        agv.left(2, 1/2)
    elif move_dir == "right":
        agv.right(2, 1/2)
    elif move_dir == "stop":
        agv.stop()

def camera_thread():
    while True:
        ret, frame = cap.read()

        moter_move()

        if not ret:
            print("Camera Error")
            break

        process_frame2(frame)

        cv2.imshow('Frame', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


        time.sleep(0.1)

camera_thread = threading.Thread(target=camera_thread)
camera_thread.start()

camera_thread.join()

cap.release()
cv2.destroyAllWindows()
