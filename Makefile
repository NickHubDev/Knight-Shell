CC = gcc
FILE = main.c
OUTPUT = k-shell
SRC = src

build:
	$(CC) $(FILE) $(SRC)/* -o $(OUTPUT)
	./$(OUTPUT)

clear:
	rm -rf ./k-shell