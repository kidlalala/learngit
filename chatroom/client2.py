#/usr/bin/env python3
#-*- coding:utf-8-*-
import socket,time,threading
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(('127.0.0.1',9000))
print('login successfully')
def lis(sock):
    while True:
        d=sock.recv(1024)
        if not d:
            break
        else:
            buf=d.decode('utf-8')
        print(buf)
def sendmes(sock):
    while True:
        a=input()
        sock.send(a.encode('utf-8'))
l=threading.Thread(target=lis,args=(s,))
se=threading.Thread(target=sendmes,args=(s,))
l.start()
se.start()
