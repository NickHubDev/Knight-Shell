CC = gcc
MAIN = main.c
OUTPUT = dev_version
NAME = knight
SRCS = main.c $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)

build:
	$(CC) $(SRCS) -o $(OUTPUT)
	clear
	./$(OUTPUT)

production:
	$(CC) $(SRCS) -o $(NAME) 
	sudo rm /usr/bin/knight
	sudo mv $(NAME) /usr/bin/
	clear

clear:
	rm -rf ./$(OUTPUT)
