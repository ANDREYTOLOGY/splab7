from socket import *

udp_socket = socket(AF_INET, SOCK_DGRAM)
data = 'hello world udp'
udp_socket.sendto(data.encode(), ('localhost', 8080))
data, tmp = udp_socket.recvfrom(1024)
print(data.decode())
udp_socket.close()

