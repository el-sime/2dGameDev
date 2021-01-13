CC=g++
CFLAGS=--std=c++17 -Wall 
LFLAGS = `sdl2-config --libs`
SRC=src/*.cpp
OUT=dist/game.exe

buildall:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LFLAGS)
clean:
	rm -fv $(OUT)
run:
	$(OUT)
