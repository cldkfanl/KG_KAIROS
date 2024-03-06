#변수

num1 = 3
num2 = 4
result = num1 + num2

#연산자 종류 추가
a = 10
b = a // 3 #몫
c = 10 > 3 #비교연산자 True
d = 10 < 3 #비교연산자 False
e = 1 != 5 #비교연산자 False
f = not(1 != 3) #비교연산자 False
g = (3 > 0) & (3 < 5) #and 연산자 True
h = (3 > 0) | (3 > 5) #or 연산자 True
i = 5 > 4 > 3 #True
j = 5 > 4 > 7 #False

#수학 함수 종류
a = abs(-5) #절대값
b = pow(4, 2) #제곱
c = max(5, 12) #최대값
d = min(5, 12) #최소값
e = round(3.14) #반올림
f = round(4.9934, 2) #원하는 자리수 까지 반올림
from math import *
f = floor(3.14) #버림
g = ceil(3.14) #올림
h = sqrt(16) #제곱근

from random import *
i = random() #0 ~ 1.0 사이의 임의의 값
j = int(random() * 10) #0 ~ 9 사이의 임의의 값
k = int(random() * 45) + 1 #1 ~ 45 사이의 임의의 값
l = randint(1, 45) #1 이상 45 이하의 임의의 값
m = randrange(1, 46) #1 이상 46 미만의 임의의 값

#리스트
movie = ["어벤져스" , "럭키", "스파이더맨"]
print(movie)
movie.append("배트맨") #리스트 끝에 붙이기
print(movie)
movie.insert(1, "범죄도시") #리스트의 특정 위치에 붙이기
print(movie)
del movie[1] #리스트의 특정 위치 값 삭제하기
print(movie)

movie2 = ["아이언맨", "슈퍼맨"]

movie3 = movie + movie2 # 리스트 합치기
print(movie3)


min = min(movie3) #리스트의 작은 값, 문자열은 알파벳을 기준으로
max = max(movie3) #리스트의 최대값 , 숫자는 크기를 기준으로

print(len(movie3)) #리스트의 크기

num = [1,2,3,4,5,6,7,8,9,10]
print(num[0::2]) #홀수 리스트 출력
print(num[1::2]) #짝수 리스트 출력
print(num[::-1]) #리스트 뒤집기

corp = ["KG" , "삼성", "LG", "SK하이닉스", "미래에셋"]
print(" / ".join(corp))

print("\n".join(corp)) #join 매서드

a = [2,6,3,8,9,10]
b = a.sort() #리스트를 정렬
print(b)
c = sorted(a) #리스트를 정렬
print(c)
d = a.reverse() #리스트를 뒤집기
print(d)


sub = ["12" , "23" , "34" , "45"]
sub.append("56")        #리스트에 특정 값 추가 
print(sub)
sub.insert(1, "67")     #리스트의 특정 위치에 특정 값 추가
print(sub)
sub.pop()               #리스트의 마지막 값 삭제
print(sub)
sub.append("45")
print(sub.count("45"))  #리스트에 특정 값의 개수

mix_list = ["조세호" , 30 , True]
num_list = [1,2,3,4,5,6,7,8,9,10]
num_list.extend(mix_list)           #리스트 확장
print(num_list)


#딕셔너리 , 중복 불가능, 키-값 쌍으로 구성된다.
cabinet = {3 : "아이언맨", 100 : "배트맨"}
print(cabinet[3])
print(cabinet.get(3))
print(cabinet.get(3, "사용가능"))
del cabinet[3]
print(cabinet)
cabinet[10] = "앤트맨"
cabinet[5] = "캡틴아메리카"
print(cabinet)
print(cabinet.keys())
print(cabinet.values())
print(cabinet.items())
cabinet.clear()
print(cabinet)

#조건문

result = 10 > 4
if result :
    print("this is test")
result = 10 - 4
if result :
    print("hello world")

result1 = 10 > 4
result2 = False
result3 = result1 & result2
if result3 :
    print("This is AND")
result3 = result1 | result2
if result3 :
    print("This is OR")

