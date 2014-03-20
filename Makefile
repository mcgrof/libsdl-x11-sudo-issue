all: sdl1 sdl2

sdl2: sdl.c
	g++ -lSDL -o sdl2 sdl.c

sdl1: sdl.c
	g++ -lSDL -o sdl1 sdl.c

clean:
	rm -f sdl1 sdl2
