#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char **argv)
{
	int r, flags;

	setenv("SDL_VIDEO_ALLOW_SCREENSAVER", "1", 0);
	setenv("SDL_VIDEODRIVER", "x11", 0);
	setenv("SDL_DISABLE_LOCK_KEYS", "1", 1);

	flags = SDL_INIT_VIDEO |
		SDL_INIT_TIMER |
		SDL_INIT_NOPARACHUTE;

	r = SDL_Init(flags);
	if (r) {
		fprintf(stderr, "Could not initialize SDL(%s) - exiting\n",
			SDL_GetError());
		exit(r);
	}

	return 0;
}
