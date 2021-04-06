import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 5000))
client.send('hello world'.encode())
response = client.recv(4096)
print(response)
