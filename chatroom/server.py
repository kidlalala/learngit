#/usr/bin/env python3
#-*- coding:utf-8 -*-
import socket,threading,time
clients=[]
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('127.0.0.1',9000))
s.listen(5)
print('waiting for new client...')
def tcplink(sock,addr):
        while True:
                data=sock.recv(1024)
                time.sleep(1)
                if not data or data.decode('utf-8')=='exit':
                        break
                for c in clients:
                    if c!=sock:
                        c.send(data)
                data=b''
while True:
    sock,addr=s.accept()
    t=threading.Thread(target=tcplink,args=(sock,addr))
    t.start()
    clients.append(sock)
    buf=''
    for c in clients:
            c.send(('new client from %s:%s connect' % addr).encode('utf-8'))

