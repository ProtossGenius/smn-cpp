

asio_server.o: asio_server.cpp ./base_asio_socket.h ./socket_itf.h asio_server.h
	g++ -Wall -c asio_server.cpp
base_asio_socket.o: base_asio_socket.cpp ./socket_itf.h base_asio_socket.h
	g++ -Wall -c base_asio_socket.cpp
muti-service.o: muti-service.cpp ./asio_server.h ./base_asio_socket.h ./channel.h ./lockm.h ./socket_itf.h muti-service.h socket_mtd.h
	g++ -Wall -c muti-service.cpp
socket_itf.o: socket_itf.cpp socket_itf.h
	g++ -Wall -c socket_itf.cpp
socket_mtd.o: socket_mtd.cpp ./socket_itf.h socket_mtd.h
	g++ -Wall -c socket_mtd.cpp
ticker.o: ticker.cpp ./channel.h ./lockm.h ticker.h
	g++ -Wall -c ticker.cpp
sm_build: asio_server.o base_asio_socket.o muti-service.o socket_itf.o socket_mtd.o ticker.o


sm_build_all: asio_server.o base_asio_socket.o muti-service.o socket_itf.o socket_mtd.o ticker.o


sm_clean_o:
	rm -rf ./*.o


##Tail
test:

clean:
	rm -rf *.o
build:clean
	g++  -Wall -c *.cpp 

