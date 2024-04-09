

import cv2
from cv_class import ImgProcesser

imgEditor = ImgProcesser()

# #원본함수 모두 실행
# imgEditor.run_editing()

#필요한 함수만 실행하기qq
while True:
    ret, frame = imgEditor.cap.read()
    
    
    
    # 좌우로 뒤집은 이미지 생성
    flipped_frame = cv2.flip(frame, 1)
    cv2.imshow("Flipped", flipped_frame)

    bigger = flipped_frame.set_size(frame, 3)
    cv2.imshow("Biggg", bigger)
    
    # 좌우로 뒤집은 이미지 출력
    

    if cv2.waitKey(1) == ord('q'):
        break

imgEditor.cap.release()
cv2.destroyAllWindows()