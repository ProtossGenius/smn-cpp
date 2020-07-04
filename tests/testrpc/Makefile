debug:
test:

install:

build:
	g++  -Wall -c *.cpp 
	g++  ./client.o ./rpc_nitf/*.o ./pb/*.o ./smncpp/*.o  -o run.main -lprotobuf -lpthread `pkg-config --cflags --libs protobuf` 

qrun:  build
	./run.main

clean: 
	rm -f ./run.* ./*.o
