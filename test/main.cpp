// #include "lib.h"
#include "Use_SDL2.hpp"
#include "Object.hpp"

int main(int argc, char const *argv[])
{
	int					*button = new int;
	Use_SDL2			SDL_obj(600, 600, button);
	std::vector<Object> objs;
	Object				body1(s1_Body, 4 , 4);

	objs.push_back(body1);
	*button = 1;
	while (*button != eTypeButton::quit) {
		SDL_obj.drawMapWhithObj(objs);	
	}
	system("leaks zalupa");
	return 0;
}