CC=gcc
CFLAGS=-fdiagnostics-color=always -g 
SRC=$(wildcard *.c)

all:
	$(CC) $(CFLAGS) $(wildcard *.c) -o main.exe