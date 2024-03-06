#문자열 인덱싱, 슬라이싱, 함수 => count(), upper(), lower(), strip()

a = '   hello world!   '
print(a.count('l')) # 특정 문자 찾기
print(len(a))       # 문자열 길이
print(a.upper())    # 대문자화
print(a.lower())    # 소문자화
print(a.lstrip())   #좌측 공백 제거
print(a.rstrip())   #우측 공백 제거
print(a.strip())    #좌우측 공백 제거

#replace()
b = "Lise is too short"
print(b.replace('Lise', 'Life'))

#split()
c = "a:b:c:d"
print(c.split(':'))
