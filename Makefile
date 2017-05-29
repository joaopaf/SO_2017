CC = gcc-4.9
CFLAGS = -O2 -std=c99

all: build/main build/const

build/main: bin/main.o bin/controller.o bin/utils.o
	$(CC) $(CFLAGS) bin/main.o bin/controller.o bin/utils.o -o build/main


bin/main.o: src/controller/main.c
	$(CC) $(CFLAGS) -c src/controller/main.c -o bin/main.o

bin/controller.o: src/controller/*
	$(CC) $(CFLAGS) -c src/controller/controller.c -o bin/controller.o


build/const: bin/const.o bin/utils.o
	$(CC) $(CFLAGS) bin/const.o bin/utils.o -o build/const

bin/const.o: src/components/main_const.c
	$(CC) $(CFLAGS) -c src/components/main_const.c -o bin/const.o


bin/utils.o: src/utils/readln.c src/utils/readln.h
	$(CC) $(CFLAGS) -c src/utils/readln.c -o bin/utils.o


clean:
	rm -fr build/* bin/* output/*
