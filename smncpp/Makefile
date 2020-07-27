

asio_server.o: asio_server.cpp .//.//socket_itf.h .//base_asio_socket.h asio_server.h
	g++ -Wall -c asio_server.cpp
base_asio_socket.o: base_asio_socket.cpp .//socket_itf.h base_asio_socket.h
	g++ -Wall -c base_asio_socket.cpp
muti-service.o: muti-service.cpp .//.//.//socket_itf.h .//.//base_asio_socket.h .//.//lockm.h .//asio_server.h .//channel.h muti-service.h socket_mtd.h
	g++ -Wall -c muti-service.cpp
socket_itf.o: socket_itf.cpp socket_itf.h
	g++ -Wall -c socket_itf.cpp
socket_mtd.o: socket_mtd.cpp .//socket_itf.h socket_mtd.h
	g++ -Wall -c socket_mtd.cpp
sm_build: asio_server.o base_asio_socket.o muti-service.o socket_itf.o socket_mtd.o


sm_build_all: asio_server.o base_asio_socket.o muti-service.o socket_itf.o socket_mtd.o


sm_clean_o:
	rm -rf ./*.o


##Tail
test:

clean:
	rm -rf *.o
build:clean
	g++  -Wall -c *.cpp 

