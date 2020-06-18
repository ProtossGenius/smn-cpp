debug:
test:

install:

build:
	cd smncpp && make build
	g++  -Wall -c *.cpp 
	g++ ./pb/*.o ./smncpp/*.o ./rpc_nitf/*.o  *.o  -o run.main -lprotobuf -lpthread `pkg-config --cflags --libs protobuf` 

qrun:  build
	./run.main

clean: 
	rm -f ./run.* ./*.o
