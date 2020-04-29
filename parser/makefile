CFLAGS = -Wall -g -std=c11
BIN = bin/
INC = include/
SRC = src/
XML_PATH = /usr/include/libxml2
ROOT = ../

all: main

# Standard common makefile
parser: $(ROOT)libsvgparse.so

$(ROOT)libsvgparse.so: $(BIN)SVGParser.o $(BIN)LinkedListAPI.o
	gcc -shared -o $(ROOT)libsvgparse.so $(BIN)SVGParser.o $(BIN)LinkedListAPI.o -lxml2 -lm

$(BIN)SVGParser.o: $(SRC)SVGParser.c $(INC)LinkedListAPI.h $(INC)SVGParser.h $(INC)head.h
	gcc -c -fpic $(CFLAGS) -I$(XML_PATH) -I$(INC) $(SRC)SVGParser.c -o $(BIN)SVGParser.o

$(BIN)LinkedListAPI.o: $(SRC)LinkedListAPI.c $(INC)LinkedListAPI.h
	gcc -c -fpic $(CFLAGS) -I$(INC) $(SRC)LinkedListAPI.c -o $(BIN)LinkedListAPI.o

main: $(ROOT)libsvgparse.so
	gcc $(CFLAGS) -I$(INC) -I$(XML_PATH) -L$(BIN) -o $(BIN)main $(SRC)main.c -lsvgparse -lxml2

clean:
	rm -rf $(BIN)*.o $(BIN)*.so $(BIN)main
