#include <iostream>
# include <SDL2/SDL.h>
// # include <SDL2_image.h>
// # include <SDL2_mixer.h>

int main(int argc, char const *argv[])
{
	SDL_DisplayMode displayMode;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	int request = SDL_GetDesktopDisplayMode(0,&displayMode);
	SDL_Window *win = SDL_CreateWindow(
		"Hello World!",
		0,
		0,
		displayMode.w / 2,
		displayMode.h / 2,
		SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Rect player_RECT;
		player_RECT.x = 0;   //Смещение полотна по Х
		player_RECT.y = 0;   //Смещение полотна по Y
		player_RECT.w = 333; //Ширина полотна
		player_RECT.h = 227; //Высота полотна

	SDL_Rect background_RECT;
		background_RECT.x = 0;
		background_RECT.y = 0;
		background_RECT.w = displayMode.w;
		background_RECT.h = displayMode.h;
	const int player_WIGHT = 333;   //Ширина исходнго изображения
	const int player_HEIGH = 227;   //Высота исходного изображения
	double TESTtexture_SCALE = 1.0; //Множетель для зумирования

	while (1);
	return 0;
}