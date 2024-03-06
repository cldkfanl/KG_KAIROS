print("파이썬 기본 문법 시작")
#문자열 출력 옵션
print('큰따옴표, 작은 따옴표 사용 가능')
print(""" 여러줄 출력하고 싶을 때
      여러줄 따옴표 3개
      사용 가능""")
print('''이렇게도
      사용
      가능''')

print("'낮말은' 새가 듣고 '밥말은'라면 먹고 싶다")
print('"hello"')
print("'hello'")
#여러개의 값 출력하기
print(1,2,3)
print(1+2, 1+3, 2+3)
print('1 + 2 =', 1+2)
#print(, sep = , end =  사용해보기)
print(1,2,3, sep = ':' , end=')')

#자기소개, 변수
name = "최지웅"
age = 27
hobby = "여행"
print("저는 " ,name, "입니다. 반갑습니다.\n 파이썬 과정을 함께 해봅시다.")
print("저는" ,age , "살이구요 취미는" ,hobby,"입니다.")

print(type(name), type(age), type(hobby))

#f-string 사용법
print(1, "1")
print(f"어쩌구 {name} 어쩌구")
print(f"저는 {age}살 이구요 취미는 {hobby}입니다")

#인덱스, 슬라이싱
a = "Life is too short, You need Python"
print(a[0])
print(a[12])
print(a[0:4])

#날짜와 날씨 분리하기
b = "20240102Sunny"
date = b[:8]
weather = b[8:]
print(date, "is", weather)
print(f"오늘 날씨 {weather}")

#사칙연산
x = -1
y = 3
tmp = (-y)**3 + 2 *(x**2) * y
print(tmp)
# 복합연산자
a = 15
a += 3
print("+= 결과", a)
a -= 7
print("-= 결과", a)
a *= 2
print("*= 결과", a)
a /= 2
print("/= 결과", a)
a **= 3
print("**= 결과", a)
a //= 2
print(a)


print('---------------------')
#연산 - 문자열 *, +
a = 'good'
b = 'morning'
print(a + b)
print(a * 5)

#문자와 숫자열 과의 연산은 할 수 없다

x, y = 10, '20'
print(x + int(y))
print(x + float(y))
print(str(x) + y)

#입력 input()
name = input("이름을 입력해주세요 :")
age = input("나이를 입력해주세요 :")
hobby = input("취미를 입력해주세요 :")
print(f"당신이 입력한 이름은 {name}, 나이는 {age}, 취미은 {hobby}입니다.")

#input을 통한 간단한 계산식
num1 = input("첫번째 수 : ")
num2 = input("두번째 수 : ")

output = int(num1) + int(num2)

print(output)


#점수 입력받아 합계, 평균 구하기
math = input("수학 점수 : ")
eng = input("영어 점수 : ")
nlan = input("국어 점수 : ")
sum = int(math) + int(eng) + int(nlan)
avg = sum / 3
print(f"당신의 점수는 {sum}점 , 평균은 {avg}점입니다.")

