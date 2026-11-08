CC = gcc
FILE = main.c
OUTPUT = k-shell
NAME = knight
SRCS = main.c $(wildcard src/*.c) $(wildcard src/**/**/*.c)

build:
	$(CC) $(SRCS) -o $(OUTPUT) -lreadline
	./$(OUTPUT)

production:
	$(CC) $(SRCS) -o $(NAME) -lreadline
	sudo rm /usr/bin/knight
	sudo mv $(NAME) /usr/bin/

clear:
	rm -rf ./k-shell
