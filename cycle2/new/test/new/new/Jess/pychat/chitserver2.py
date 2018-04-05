from socket import socket,AF_INET,SOCK_STREAM
from threading import Thread
from pickle import dumps,loads
threads=[]
connections={}
def server_handler(client):
    client.send('enter your name'.encode())
    name=client.recv(1024).decode()
    connections[name]=client
    print('*** user{0} has entered the application ***'.format(name))
    while True:
          command=loads(client.recv(1024))
          code=str(command[0])
          print('code{0} recieved from {1}'.format(code,name))
          if code=='0':
             online=list(connections.keys())
             client.send(dumps(online))
          elif code=='1':
               print('*** entered sender ***')
               print('sending {0} to {1}'.format(command[2],command[1]))
               text=name+':'+ command[2]
               message=text.encode()
               reciever=connections[command[1]]
               reciever.send(message)
               client.send('1'.encode())
if __name__ =='__main__':
 server=socket(AF_INET,SOCK_STREAM)
 server.bind(('127.0.0.1',8058))
 server.listen(6)
 while True:
       client,addr=server.accept()
       t=Thread(target=server_handler,args=(client,))
       threads.append(t)
       t.start()
