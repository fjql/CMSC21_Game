CC = clang++
CFLAGS = -std=c++2b -Wall -Wextra -O1

SRC = ./src/*.cpp
OUT = ./bin/Game

make:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

g++:
	g++ $(SRC) -o $(OUT) $(CFLAGS)

run:
	./bin/Game
