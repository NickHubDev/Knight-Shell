CC = gcc -g
FILE = main.c
OUTPUT = k-shell
NAME = knight
SRCS = main.c $(wildcard src/*.c) $(wildcard src/**/**/*.c)
KSHS = dev/proof/kshFiles/source-code/charger.c $(wildcard dev/proof/kshFiles/source-code/**/*.c)

build:
	$(CC) main.c $(shell find src -name "*.c") -o $(OUTPUT)
	clear
	./$(OUTPUT)

production:
	$(CC) $(SRCS) -o $(NAME) 
	sudo rm /usr/bin/knight
	sudo mv $(NAME) /usr/bin/

ksh:
	$(CC) $(KSHS) -o kshFiles
	./kshFiles

clear:
	rm -rf ./k-shell
