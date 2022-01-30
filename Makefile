# set the compiler
CC = g++
# set the cpu bits
ARCH = -m64
# set the compiler options
OPTS = -Wall -std=c++11 -fpic -march=core-avx2 -O4
# include java directory
JAVADIR= /usr/lib/jvm/jdk1.8.0_321/include
# include java's OS specific directory
JAVAOSDIR= /usr/lib/jvm/jdk1.8.0_321/include/linux
.DEFAULT_GOAL := all

all: generate

generate:
	mkdir -p obj/Release/FastNoiseSIMD
	mkdir -p bin/Release
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_avx2.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx2.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_internal.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_internal.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_sse2.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse2.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD/FastNoiseSIMD_sse41.cpp -o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse41.o
	${CC} ${OPTS} ${ARCH} -I${JAVAOSDIR} -I${JAVADIR} -c FastNoiseSIMD_JNI.cpp -o obj/Release/FastNoiseSIMD_JNI.o
	${CC} -shared  obj/Release/FastNoiseSIMD/FastNoiseSIMD.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_avx2.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_internal.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse2.o obj/Release/FastNoiseSIMD/FastNoiseSIMD_sse41.o obj/Release/FastNoiseSIMD_JNI.o  -o bin/Release/libStarMadeNative64.so ${ARCH} -s
	@echo "Built all files successfully."
	@echo "libStarMadeNative64.so can be found in bin/Release"
clean:
	rm -r ./bin ./obj
	@echo "Cleaned."
