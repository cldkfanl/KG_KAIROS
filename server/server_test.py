from socket import *

serverSock = socket(AF_INET, SOCK_STREAM)
serverSock.bind(('', 8080))
serverSock.listen(1)

print("server complete.")

while True:
    connectionSock, addr = serverSock.accept()
    print(str(addr), 'find.')

    try:
        while True:
            data = connectionSock.recv(1024)
            if not data:
                print("disconnect client.")
                break
            print('sub data : ', data.decode('utf-8'))

            connectionSock.send('I am a server.'.encode('utf-8'))
            print('send msg.')

    except ConnectionResetError:
        print("client disconnect server.")
        connectionSock.close()

serverSock.close()