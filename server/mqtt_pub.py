import paho.mqtt.publish as publish
import time

while True:
    message = input("전송할 메시지를 입력하세요 (종료하려면 'quit' 입력): ")
    if message == 'quit':
        break
    publish.single("3choi/topic", message, hostname="172.30.1.20")  # 브로커 주소로 변경하세요.
    print("메시지를 발행했습니다.")
    time.sleep(1)  # 1초 대기