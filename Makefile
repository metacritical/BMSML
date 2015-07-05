#
# BMSML Makefile
#

print-%: ; @echo $*=$($*)
CC=clang
CFLAGS=-Wall -O2
#CFLAGS+=-ansi -pedantic -std=c++11
INC=-I/usr/local/include
LIBS=-lreadline
#LIBS+=-L/usr/local/lib
OUTPUT=bmsml

grab: main.c
	$(CC) $< $(CFLAGS) $(LIBS)  -o $(OUTPUT)
run: main.c
	$(CC) $< $(LIBS)  -o $(OUTPUT)
	./$(OUTPUT)
