#include <iostream>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>


int main(int argc, char const *argv[])
{
	SDL_DisplayMode displayMode;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	int request = SDL_GetDesktopDisplayMode(0,&displayMode);
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, displayMode.w / 2,
		displayMode.h / 2, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Rect player_RECT;
		player_RECT.x = 120;   //Смещение полотна по Х
		player_RECT.y = 120;   //Смещение полотна по Y
		player_RECT.w = 90; //Ширина полотна
		player_RECT.h = 90; //Высота полотна


	SDL_Texture *player =  IMG_LoadTexture(ren,"./resurses/diam.jpg");
	if (player == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_SetRenderDrawColor(ren, 25, 170, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, player, NULL, &player_RECT); //Копируем в рендер персонажа
	SDL_RenderPresent(ren);


	SDL_Event event;
	bool quit = false;

	int		x[2] = {-1, -1};
	int		y[2] = {-1, -1};
	int		i = 0;	
	while(!quit) {
		std::cout << "start\n";
		while(SDL_PollEvent(&event))
		{
			SDL_PumpEvents(); // обработчик событий.
			if(event.type == SDL_QUIT)
				quit = true;
			// if (x[1] != -1 && y[1] != -1) {
				
			// 	                // SDL_RenderClear(ren);

			// 	SDL_SetRenderDrawColor(ren, 25, 170, 255, SDL_ALPHA_OPAQUE);
                


			// 	SDL_RenderDrawLine(ren, x[0], y[0], x[1], y[1]);

			// 	SDL_RenderPresent(ren);
			// 					SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);

			// 	// SDL_RenderPresent(ren);
			// 	x[0] = -1;
			// 	x[1] = -1;
			// 	y[0] = -1;
			// 	y[1] = -1;
			// 	std::cout << "?????\n";
			// }
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				// if (x[0] == -1) {
				// 	x[0] = event.button.x;
				// 	y[0] = event.button.y;
				// }
				// else {
				// 	x[1] = event.button.x;
				// 	y[1] = event.button.y;
				// }
				player_RECT.x = event.button.x;
				player_RECT.y = event.button.y;
				SDL_RenderClear(ren);
				SDL_RenderCopy(ren, player, NULL, &player_RECT);
				SDL_RenderPresent(ren);
				std::cout << event.button.x << " : " << event.button.y << "\n";
				// if(event.button.button == SDL_BUTTON_RIGHT)
				// 	ARRAY_texturesState[1] = 1;
				// if((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= player_RECT.x) &&
				// 	(event.button.y >= player_RECT.y) &&
				// 	(event.button.x <= player_RECT.w + player_RECT.x) &&
				// 	(event.button.y <= player_RECT.h + player_RECT.y))
				// 	ARRAY_texturesState[1] = 0;
			}
			i++;
			
		}
		int z = 0;
		while (z <= 600000000)
			z++;
		std::cout << "end\n";
	}
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	std::cout << "Cout !\n\n\n\n\n\n";
	system("leaks zalupa");
	return 0;
}


// apt install libsdl2-image-dev
// brew install sdl2
//brew install sdl2_image

// g++ main.cpp -o zalupa -I ~/.brew/include -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf