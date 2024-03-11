import cv2
import mediapipe as mp

mp_pose = mp.solutions.pose

for lndmrk in mp_pose.PoseLandmark:
    print(lndmrk)
    print(lndmrk.value)
