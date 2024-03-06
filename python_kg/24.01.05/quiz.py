#1 정수 n을 입력받아 n + nn + nnn 의 결과값을 출력
n = int(input("정수를 입력하세요. : "))
print(n + n*11 + n*111)


#2 금액을 입력받아 교환할 동전 개수 구하기, 그리디

num = int(input("금액을 입력하세요. : "))
arr = [500, 100, 50, 10, 1]
for coin in arr :
    print(f"{coin}원짜리 ==> {num // coin}개")
    num = num % coin

#3 앱의 평점을 출력하고 평균값 구하기
app1 = ['Facebook', 0.0, 'USD', 2974676, 3.5]
app2 = ['Instagram', 0.0, 'USD', 2161558, 4.5]
app3 = ['Clash of Clans', 0.0, 'USD', 2130805, 4.0]
rating_sum = 0

print(f"Facebook rating: {app1[4]}")
print(f"Instagram rating: {app2[4]}")
print(f"Clash of Clans rating: {app3[4]}")
print(f"rating average: {(app1[4] + app2[4] + app3[4])/3}")

#4 조건에 다라 놀이기구 탈 수 있는지 확인




age = int(input("나이를 입력하세요. : "))
height = int(input("키를 입력하세요. : "))
if age >=10 & height >= 110 :
    print("놀이기구를 탈 수 있습니다.")
else :
    print("놀이기구를 탈 수 없습니다.")




#5 국립공원입장권 발급 프로그램
age = int(input("나이를 입력하세요. : "))
if age >=65 or age <= 7 :
    print("무료입니다.")
elif 8 <= age <= 18 :
    print("1000원입니다.")
else :
    print("3000원입니다.")


#6 구매가를 입력하고 금액에 따른 할인율을 계산
    
price = int(input("구매가를 입력하세요. : "))
discount = 0
if 10000 <= price < 50000 :
    discount = 5
elif 50000<= price < 100000 :
    discount = 7.5
elif price >= 100000 :
    discount = 10
print(f"구매가 : {price}원")
print(f"할인율 : {discount}%")
print(f"할인금액 : {int(price * (discount * 0.01))}원")
print(f"지불금액 : {int(price * (100 - discount) * 0.01)}원")


#7 이름 키 몸무게 입력, 출력예시와 같이 비만도분류 , 적정체중 출력

name = input("이름를 입력하세요. : ")
height = input("키를 입력하세요. : ")
weight = input("몸무게를 입력하세요. : ")
BMI = round(int(weight) / ((int(height) / 100) ** 2),1)
Bweight = round(21 * (int(height) / 100) ** 2, 1)
state = ""
if BMI < 18.5 :
    state = "저체중"
elif 18.5 <= BMI < 23 :
    state = "정상"
elif 23 <= BMI < 25 :
    state = "과체중"
elif 25 <= BMI < 30 :
    state = "비만1단계"
elif 30 <= BMI < 40 :
    state = "비만2단계"
else :
    state = "비만3단계"
print(f"{name}님의 신체질량지수(BMI)는 {BMI}이며, {state}입니다.")
print(f"{name}님의 적정체중은 {Bweight}kg입니다.")

#8 학생의 점수가 60점 이상이면 합격, 이하면 불합격

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

count = 0
for i in range(len(arr)) :
    if arr[i] >= 60 :
        count += 1
        print(f"{i}번 학생은 합격입니다.")
    else :
        print(f"{i}번 학생은 불합격입니다.")
print(f"합격인원은 {count}개입니다.")
print(f"불합격인원은 {len(arr) - count}개입니다.")

#continue

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

count = 0
for i in range(len(arr)
) :
    if arr[i] >= 60 :
        count += 1
        print(f"{i}번 학생은 합격입니다.")
    else :
        continue
print(f"합격인원은 {count}개입니다.")
print(f"불합격인원은 {len(arr) - count}개입니다.")

add = 0
for i in range(1,11) :
    add += i
print(add)

#369게임
num = int(input("숫자를 입력하세요. : "))
for i in range(1, num + 1) :
    div = i % 10
    if (div % 3 == 0) and (div != 0) :
        print("짝!")
    else :
        print(i)

#별 찍기
num = int(input("숫자를 입력하세요. : "))
for i in range(1, num+ 1) :
    for j in range(1, i+1) :
        print('*' , end = ' ')
    print()
print('---------------------------------')
for i in range(num , 0, -1) :
    for j in range(1, i + 1) :
        print('*' , end= ' ')
    print()
print('---------------------------------')
for i in range(1, num + 1) :
    for j in range(num - i + 1, 1, -1) :
        print(' ' , end= ' ')
    for j in range(1, i+1) :
        print('*', end= ' ')
    print()
print('---------------------------------')
for i in range(1, num + 1) :
    for j in range(num - i + 1, 1, -1) :
        print(' ' , end= ' ')
    for j in range(1 , i * 2) :
        print('*', end= ' ')
    print()
print('---------------------------------')
for i in range(1, num + 1) :
    for j in range(num - i + 1, 1, -1) :
        print(' ' , end= ' ')
    for j in range(1 , i * 2) :
        print('*', end= ' ')
    print()
for i in range(num-1 , 0 , -1) :
    for j in range(num - i + 1, 1, -1) :
        print(' ' , end= ' ')
    for j in range(1 , i * 2) :
        print('*', end= ' ')
    print()


#updown게임
from random import *
num = randint(1, 100)
state = True
cnt = 0
while state :
    input_num = int(input("숫자를 입력하세요. : "))
    cnt += 1
    if num == input_num :
        print("정답입니다!")
        print(f"{cnt}번만에 맞췄습니다.")
        state = False
    elif num > input_num :
        print("up!")
    else :
        print("down!")

#예외처리
try :
    while True :
        print("hello")
except KeyboardInterrupt :
    print("프로그램 탈출!")

#미션: 타이머 작성하기
#아두이노의 세븐세그먼트 프로그램과 연관되는 내용
#time 모듈 사용
#while 반복문, 숫자연산 사용
#Ipython 설치해야함(pip install Ipython)
#sevenSegment 모듈 같은 경로로 옮겨야 함


import time
from IPython.display import clear_output
from sevenSegment import getSevSegStr

# (!) Change this to any number of seconds:
secondsLeft = 25

try:
    while secondsLeft >= 0:
        # Clear the output cell
        clear_output(wait=True)

        # 남은 시간/분/초 형식으로 기록하기
        hours = str(secondsLeft // 3600)
        minutes = str((secondsLeft % 3600) // 60)
        seconds = str(secondsLeft % 60)

        # sevenSegments 모듈 사용하기
        hDigits = getSevSegStr(hours, 2)
        hTopRow, hMiddleRow, hBottomRow = hDigits.splitlines()

        mDigits = getSevSegStr(minutes, 2)
        mTopRow, mMiddleRow, mBottomRow = mDigits.splitlines()

        sDigits = getSevSegStr(seconds, 2)
        sTopRow, sMiddleRow, sBottomRow = sDigits.splitlines()

        # 남은 시간 표시하기
        print(hTopRow + '     ' + mTopRow + '     ' + sTopRow)
        print(hMiddleRow + '  *  ' + mMiddleRow + '  *  ' + sMiddleRow)
        print(hBottomRow + '  *  ' + mBottomRow + '  *  ' + sBottomRow)

        if secondsLeft == 0:
            print()
            print('    * * * * 완료! * * * *')
            break

        print('\nPress Ctrl-C to quit.')

        time.sleep(1)  # 1초 단위로 카운트 다운하기
        secondsLeft -= 1
except KeyboardInterrupt:
    pass  # Ctrl-C 를 누르면 끝내기