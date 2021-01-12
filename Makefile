CC=g++
CFLAGS=--std=c++17 -Wall `pkg-config --cflags --libs sdl2 SDL2_image SDL2_ttf SDL2_mixer`
SRC=src/*.cpp
OUT=dist/game.exe

buildall:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)
clean:
	rm -fv $(OUT)
run:
	$(OUT)
