import paho.mqtt.client as mqtt

# 브로커에 연결되었을 때 호출되는 콜백 함수
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    # 연결이 성공적으로 수립되면 구독할 주제를 설정합니다.
    client.subscribe("3choi/topic")

# 메시지가 도착했을 때 호출되는 콜백 함수
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

# MQTT 클라이언트 생성
client1 = mqtt.Client("client1", protocol=mqtt.MQTTv311)

# 연결 이벤트에 대한 콜백 함수 등록
client1.on_connect = on_connect

# 메시지 도착 이벤트에 대한 콜백 함수 등록
client1.on_message = on_message

# 브로커에 연결
client1.connect("172.30.1.20", 1883, 60)  # 브로커 주소로 변경하세요.

# 루프 시작 (메시지를 수신 대기)
client1.loop_forever()