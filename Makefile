CC = gcc
FILE = main.c
OUTPUT = k-shell
SRCS = main.c $(wildcard src/*.c) $(wildcard src/**/*.c)

build:
	$(CC) $(SRCS) -o $(OUTPUT) -lreadline
	./$(OUTPUT)

clear:
	rm -rf ./k-shell