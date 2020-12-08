import socket
import threading


HOST = '192.168.100.5'
PORT = 8000
NUM_LISTEN = 5
SIZE = 1024 * 1024
FORMAT = 'utf-8'


def createSocket(port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, port))
    s.listen(5)
    return s


def accept(s):
    return s.accept()


def receive(client):
    return client.recv(SIZE).decode(FORMAT)


def createHeader():
    file_header = open('header.txt')
    header = file_header.read()
    file_header.close()
    return header


def isGetRequest(packet):
    return 'GET' in packet


def isPostRequest(packet):
    return 'POST' in packet


def isVideo(path):
    return '.png' in path or '.jpg' in path or '.ico' in path or '.mp4' in path


def isDocument(path):
    return '.docx' in path or '.pptx' in path or '.xlsx' in path or '.pdf' in path or '.txt' in path \
            or '.pub' in path


def response(path, client):
    header = createHeader()
    if isVideo(path) or isDocument(path):
        file_data = open(path, 'rb')
        data = file_data.read()
        send = bytes(header, FORMAT) + data
        client.sendall(send)
    else:
        file_data = open(path)
        data = file_data.read()
        send = header + data
        client.sendall(bytes(send, FORMAT))


def handleGetRequest(packet, client):
    path = receive_packet.split('\n')[0].split(' ')[1]
    if path == '/':
        path = './index.html'
    else:
        path = '.' + path
    response(path, client)


def handlePostRequest(packet, client):
    if 'POST / HTTP/1.1' not in packet or "Username=admin&Password=admin" not in packet:
        response('./fail.html', client)
    else:
        response('./home.html', client)


def handleLogin():
    while True:
        check = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        check.bind((HOST, 10000))
        check.listen(NUM_LISTEN)

        client, address = check.accept()
        receive_packet = receive(client)
        print('receive_packet =', receive_packet)

        if isGetRequest(receive_packet):
            handleGetRequest(receive_packet, client)
        elif isPostRequest(receive_packet):
            handlePostRequest(receive_packet, client)

        client.close()
        check.close()


print('Waiting...')
# login = threading.Thread(target=handleLogin)
#
# login.start()

while True:
    s = createSocket(PORT)
    client, address = accept(s)
    receive_packet = receive(client)
    print('receive_packet =', receive_packet)

    if receive_packet != '':
        if isGetRequest(receive_packet):
            handleGetRequest(receive_packet, client)
        else:
            handlePostRequest(receive_packet, client)

    client.close()
    s.close()
