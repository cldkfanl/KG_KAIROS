import mediapipe as mp
import cv2

cap = cv2.VideoCapture(0)
cap.set(3,640)
cap.set(4,480)

mp_pose = mp.solutions.pose

# pose = mp_pose.Pose()

with mp_pose.Pose(min_detection_confidence=0.5, min_tracking_confidence=0.5) as pose:
    while cap.isOpened():
        ret, image = cap.read()
        image_h, image_w, _ = image.shape
        results = pose.process(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))

        if results.pose_landmarks :
            left_shoulder = results.pose_landmarks.landmark[mp_pose.PoseLandmark.LEFT_SHOULDER]
            left_wrist = results.pose_landmarks.landmark[mp_pose.PoseLandmark.LEFT_WRIST]
            left_elbow = results.pose_landmarks.landmark[mp_pose.PoseLandmark.LEFT_ELBOW]
            right_shoulder = results.pose_landmarks.landmark[mp_pose.PoseLandmark.RIGHT_SHOULDER]
            right_wrist = results.pose_landmarks.landmark[mp_pose.PoseLandmark.RIGHT_WRIST]
            right_elbow = results.pose_landmarks.landmark[mp_pose.PoseLandmark.RIGHT_ELBOW]

            shoulderl_pos = (int(left_shoulder.x * image_w), int(left_shoulder.y * image_h))
            handl_pos = (int(left_wrist.x * image_w), int(left_wrist.y * image_h))
            elbowl_pos = (int(left_elbow.x * image_w), int(left_elbow.y * image_h))
            shoulderr_pos = (int(right_shoulder.x * image_w), int(right_shoulder.y * image_h))
            handr_pos = (int(right_wrist.x * image_w), int(right_wrist.y * image_h))
            elbowr_pos = (int(right_elbow.x * image_w), int(right_elbow.y * image_h))


            cv2.circle(image,shoulderl_pos, 20, (255,0,0),-1)
            cv2.circle(image,handl_pos, 20, (0,255,0),-1)
            cv2.circle(image,elbowl_pos, 20, (0,0,255),-1)
            cv2.circle(image,shoulderr_pos, 20, (255,0,0),-1)
            cv2.circle(image,handr_pos, 20, (0,255,0),-1)
            cv2.circle(image,elbowr_pos, 20, (0,0,255),-1)
            cv2.imshow("my cam", image)

            key = cv2.waitKey(1)
            if(key == ord('q') or key == 27):
                break