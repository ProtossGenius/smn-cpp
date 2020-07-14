
sm_build_all: 
	cd pb && make sm_build_all
sm_clean_o:
	rm -rf ./*.o
##Tail
build:
	g++ pb/*.o *.o  -o testproto -lprotobuf `pkg-config --cflags --libs protobuf` 

qrun: build
	./testproto 

clean: 
	rm -f ./testproto ./*.o

