from socket import *
import time

clientSock = socket(AF_INET, SOCK_STREAM)
clientSock.connect(('192.168.137.90', 8084))

print('연결 확인 됐습니다.')

while True:
    message = input("전송할 메시지를 입력하세요 (종료하려면 'quit' 입력): ")
    
    if message == 'quit':
        break

    clientSock.send(message.encode('utf-8'))
    print('메시지를 전송했습니다.')

    data = clientSock.recv(1024)
    print('받은 데이터 : ', data.decode('utf-8'))

    time.sleep(1)  # 1초 대기

clientSock.close()