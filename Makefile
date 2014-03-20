all: sdl1 sdl2

sdl2: sdl.c
	gcc -lSDL -o sdl2 sdl.c

sdl1: sdl.c
	gcc -lSDL -o sdl1 sdl.c

clean:
	rm -f sdl1 sdl2
