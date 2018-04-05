from socket import socket,AF_INET,SOCK_STREAM
from pickle import dumps,loads
def client_handler():
    client=socket(AF_INET,SOCK_STREAM)
    client.connect(('127.0.0.1',8058))
    handshake=client.recv(1024).decode()
    name=raw_input(handshake)
    client.send(name.encode())
    while True:
          code=raw_input('enter 0 for seeing online list\n1 for sending message\n2 for viewing message\n')
          if code=='0':
             print('*** refreshing ***')
             message=['0','whos online?']
             client.send(dumps(message))
             print('**refreshing**')
             online=loads(client.recv(1024))
             for person in online:
                 print('(.)'+person)
             print('\n')
          if code=='1':
             
             message=raw_input('enter  message:')
             print('**refreshing**')
             for person in online:
              message=dumps([1,person,message])
              client.send(message)
             error=client.recv(1024).decode()
             if error=='1':
                print('*message sent*')
          if code=='2':
               new=client.recv(1024).decode()
               print(new)
if __name__ == '__main__':
     client_handler()
