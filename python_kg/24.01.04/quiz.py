#1. 변수를 이용하여 다음 문장을 출력하시오.
#변수 : 사당,신도림,인천공항

station = {"사당", "신도림", "인천공항"}

for i in station:
    print(f"{i} 행 열차가 들어오고 있습니다.")


#2. 코딩 스터디 모임 날짜를 정하시오
#월별 날짜는 28일 이내로 정하고, 매월 1~3일은 제외한다.

from random import *

day = randrange(4, 29)
print(f"오프라인 스터디 모임은 매월 {day}일로 선정되었습니다.")


#3. 리스트에서 최대 최소값 출력
num = [1,4,5,5,7,98, 12]

print(f"max : {max(num)}")
print(f"min : {min(num)}")

#4 리스트의 평균을 구하시오
avg = sum(num) / len(num)
print(f"{avg}")


#5  슬라이싱 하시오
jumin = "990120-1234567"
print(f"성별 : {jumin[7]}")
print(f"연 : {jumin[0:2]}")
print(f"월 : {jumin[2:4]}")
print(f"일 : {jumin[4:6]}")
print(f"뒤 7자리 : {jumin[7:]}")
print(f"뒤 7자리 : {jumin[-7:]}")

#6 날짜 정보를 제외하고 숫자만을 출력하기

price = ['20180728', 100, 130, 140, 150, 160, 170]

print(price[1:])

#7 사이트별 비밀번호를 만들어주는 프로그램 작성
#규칙 1 : http:// 제외
#규칙 2 : .com 부분은 제외
#규칙 3 : 남은글자 중 처음 세자리 + 글자 갯수 + 글자 내 'e'갯수 + "!"

String = input("사이트를 입력해주세요 : ")
String2 = String.replace("http://", "")
String3 = String2[:String2.index(".")]
pw = String2[0:3] + str(len(String3)) + str(String3.count("e")) + "!"
print(pw)


#8 홀수 짝수 구분하기

num = int(input("숫자를 입력하세요 : "))
result = num / 2
if result :
    print("홀수")
else :
    print("짝수")

#9 3~8사이의 숫자를 입력받아 해당숫자를 꼭짓점으로 갖는 다각형 그리기


import turtle
N = int(input("숫자를 입력하세요"))
t = turtle.Turtle()

if N >= 3 & N <= 8 :
    for i in range(N) :
        t.forward(100)
        t.left(360/N)
else :
    print("숫자를 다시 입력하세요")

#10 날씨 정보를 입력받고, 그에 따른 값 출력

weather = input("날씨 정보를 입력하세요 : ")

if weather == "비" :
    print("우산을 챙기세요.")
elif weather == "미세먼지" :
    print("마스크를 챙기세요.")
else :
    print("준비물 필요 없어요,")
