
asio_server.o: asio_server.cpp asio_server.h
	g++ -Wall -c asio_server.cpp
base_asio_socket.o: base_asio_socket.cpp base_asio_socket.h
	g++ -Wall -c base_asio_socket.cpp
muti-service.o: muti-service.cpp muti-service.h socket_itf.h socket_mtd.h
	g++ -Wall -c muti-service.cpp
socket_mtd.o: socket_mtd.cpp socket_mtd.h socket_itf.h
	g++ -Wall -c socket_mtd.cpp
sm_build_all: asio_server.o base_asio_socket.o muti-service.o socket_mtd.o
sm_clean_o: 
	rm -rf ./*.o
##Tail
test:

clean:
	rm -rf *.o
build:clean
	g++  -Wall -c *.cpp 

