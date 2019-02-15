// #include "lib.h"
#include "Use_SDL2.hpp"
#include "Object.hpp"

int main(int argc, char const *argv[])
{
	int					*button = new int;
	GUI					*gui = Use_SDL2::getInstance(1300, 1300, button);
	std::vector<Object> objs;
	Object				body1(s1_Body, 4 , 4);

	objs.push_back(body1);
	*button = 1;
	while (*button != eTypeButton::quit) {
		gui->drawMapWhithObj(objs);	
	}
	system("leaks zalupa");
	return 0;
}