import cv2
import datetime
from PIL import ImageFont, ImageDraw, Image
import numpy as np
# 프레임 비교 함수
def get_diff_img(frame_a, frame_b, frame_c, threshold):
    # 비교용 흑백 프레임
    frame_a_gray = cv2.cvtColor(frame_a, cv2.COLOR_BGR2GRAY)
    frame_b_gray = cv2.cvtColor(frame_b, cv2.COLOR_BGR2GRAY)
    frame_c_gray = cv2.cvtColor(frame_c, cv2.COLOR_BGR2GRAY)

    #프레임 비교
    diff_ab = cv2.absdiff(frame_a_gray, frame_b_gray)
    diff_bc = cv2.absdiff(frame_b_gray, frame_c_gray)

    #이진화 : diff가 threshold 이상이면 값을 255로 변환함
    ret, diff_ab_t = cv2.threshol(diff_ab, threshold, 255, cv2.THRESH_BINARY)
    ret, diff_bc_t = cv2.threshol(diff_bc, threshold, 255, cv2.THRESH_BINARY)

    #b에서도 변하고 c에서도 변한 부분은 AND 연산 > 1로 변환
    diff = cv2.bitwise_and(diff_ab_t, diff_bc_t)

    #영상에서 모폴로지로 빈 공간을 채워넣어줌
    k = cv2.getStructuringElement(cv2.MORPH_CROSS, (3, 3)) # 3*3 교차형 필터 생성
    diff = cv2.morphologyEx(diff, cv2.MORPH_OPEN, k) #diff에 대해 MORPH_OPEN 방식으로 필터를 적용, 노이즈 제거 후 빈 픽셀 채우기

    #영상에서 1인 부분을 count
    diff_cnt = cv2.countNonZero(diff)


cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 640)
codex = cv2.VideoWriter_fourcc(*'XVID')
font_ = ImageFont.truetype(r'fonts\SCDream6.otf',20)
is_record = False
on_record = False
cnt_record = 0 # 녹화 시간 변수
min_cnt_record = 50 # 최소 촬영 시간
threshod = 40 # 영상 차이 판별 기준값(임계치)
diff_min = 10 # 영상 차이 '픽셀'의 수(이 이상이면 움직였음)

ret, frame_a = cap.read()
ret, frame_b = cap.read()


while True:
    # 현재 영상
    ret, frame_c = cap.read()
    frame = np.array(frame_c)
    # 현재 시각 문자열로 넣기
    t_now = datetime.datetime.now()
    t_str = t_now.strftime('%Y/%m/%d %H:%M:%S')
    t_str_path = t_now.strftime('%Y_%m_%d %H_%M_%S')
    cv2.rectangle(img=frame, pt1 = (10, 15), pt2=(340, 35), color=(0,0,0), thickness= -1)


    # 움직임 감지
    diff,diff_cnt = get_diff_img(frame_a = frame_a , frame_b = frame_b, frame_c = frame_c, threshold = threshod)

    #움직임이 일정 이상인가?
    if diff_cnt > diff_min:
        cv2.imwrite("Capture/captured" + t_str_path + ".png", frame)
        #바뀐 frame을 이 파일명으로 저장. 

    #영상 차이를 출력(테스트용. 실제 CCTV 작동 시엔 꺼도 무관)
    cv2.imshow("diff", diff)

    frame = Image.fromarray(frame) #Pillow 배열로 변환해서 이미지 편집

    draw = ImageDraw.Draw(frame)
    draw.text (xy=(10,15), text = "I see you" + t_str, font = font_, fill = (255, 255, 255))
    frame = np.array(frame)

    frame_a = np.array(frame_b)
    frame_b = np.array(frame_c)

    key = cv2.waitKey(30)
    if key == ord('q') :
        break
    cv2.imshow("Original", frame)

cap.release()
cv2.destroyAllWindows()
