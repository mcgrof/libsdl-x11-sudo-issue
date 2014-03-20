#include <exception>
#include <string>
#include <SDL/SDL.h>
#include <stdlib.h>

class InitError:public std::exception {
public:
	InitError();
	InitError(const std::string &);
	virtual ~ InitError() throw();
	virtual const char *what() const throw();
private:
	std::string msg;
};

InitError::InitError():
exception(), msg(SDL_GetError())
{
}

InitError::InitError(const std::string & m):exception(), msg(m)
{
}

InitError::~InitError()throw()
{
}

const char *InitError::what() const throw()
{
	return msg.c_str();
}

class SDL {
public:
	SDL(Uint32 flags = 0) throw(InitError);
	virtual ~ SDL();
};

SDL::SDL(Uint32 flags) throw(InitError)
{
	if (SDL_Init(flags) != 0)
		throw InitError();
}

SDL::~SDL()
{
	SDL_Quit();
}

/* ... */

#include <iostream>

int main(int argc, char **argv)
{
	setenv("SDL_VIDEO_ALLOW_SCREENSAVER", "1", 0);
	setenv("SDL_VIDEODRIVER", "x11", 0);
	setenv("SDL_DISABLE_LOCK_KEYS", "1", 1);
	try {
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_TIMER |
			SDL_INIT_NOPARACHUTE);

		/* ... */

		return 0;
	}

	catch(const InitError & err) {
		std::cerr << "Error while initializing SDL:  " << err.
		    what() << std::endl;
	}

	return 1;
}
