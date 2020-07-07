
asio_server.o: asio_server.cpp 
	cc -Wall -c asio_server.cpp
base_asio_socket.o: base_asio_socket.cpp 
	cc -Wall -c base_asio_socket.cpp
socket_mtd.o: socket_mtd.cpp 
	cc -Wall -c socket_mtd.cpp
sm_build_all: asio_server.o base_asio_socket.o socket_mtd.o
sm_clean_o:
	rm -rf ./*.o
##Tail
test:

clean:
	rm -rf *.o
build:clean
	g++  -Wall -c *.cpp 












