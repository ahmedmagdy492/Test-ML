CC=gcc

all:
	$(CC) -o main -lstdc++ -lm main.cpp

clean:
	rm -rf main
