CC=gcc
CFLAGS=-O -Wall

all: mdkir

mdkir: mdkir.c mdkir.h
	$(CC) $(CFLAGS) -o mdkir mdkir.c -lncurses

clean:
	rm -f mdkir
