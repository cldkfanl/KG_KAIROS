import cv2

import numpy as np
from sensor_msgs.msg import CompressedImage

from cv_bridge import CvBridge



# 모델 불러오기

# model = load_model('keras_agv_model.h5')



# 이미지 콜백 함수

def image_callback(ros_image):

    # CvBridge 초기화

    # bridge = CvBridge()

    

    # cv2.imshow("Frame", ros_image.data)

    

    # CompressedImage를 OpenCV 이미지로 변환

    # image = bridge.compressed_imgmsg_to_cv2(ros_image)

    

    # 이미지 크기 조정

    # resized_frame = cv2.resize(image, (160, 120))

    

    # 모델 입력 형식에 맞게 변경

    # input_image = np.expand_dims(resized_frame, axis=0)

    

    # 모델 예측

    # prediction = model.predict(input_image)

    # 예측 결과 출력
    # print(np.argmax(prediction))

    print("ok")


# 메인 함수

def main():

    rospy.init_node('image_subscriber', anonymous=True) # ROS 노드 초기화

    # 마스터 URI 설정

    rospy.set_param('/master_uri', 'http://172.30.1.52:11311')

    image_topic = "camera/image/compressed"

    rospy.Subscriber(image_topic, CompressedImage, image_callback)



    # ROS 노드가 종료될 때까지 대기

    rospy.spin()



if __name__ == '__main__':

    main()

