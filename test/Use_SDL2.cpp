#include "Use_SDL2.hpp"
#include "Object.hpp"

Use_SDL2::Use_SDL2(int size_h, int size_w, int *press_button) {
	this->press_button = press_button;
	this->_initGeometricParams(size_h, size_w);
	this->_initSDL();
	this->_initTextures();
	
}

Use_SDL2::Use_SDL2(Use_SDL2 const & ref) {
	*this = ref;
}

Use_SDL2::~Use_SDL2() {
	int				i;
	int				size;
	SDL_Texture		*texture;

	i = 0;
	this->_destroyTextures();
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_win);
	SDL_Quit();
}


Use_SDL2		&Use_SDL2::operator=(Use_SDL2 const & ref) {
	return *this;
}

// MARK: - drawMapWhithObj - override function

void			Use_SDL2::drawMapWhithObj(std::vector<Object> & objects) {
	SDL_RenderClear(this->_renderer);
	this->_add_MapToRenderer();
	this->_add_ObjectsToRenderer(objects);
	SDL_RenderPresent(this->_renderer);
	if (SDL_PollEvent(&this->_event))
		this->_hendelEvent();
}

	// add Map to renderer
void			Use_SDL2::_add_MapToRenderer() {
	int			sectorX;
	int			sectorY;
	SDL_Rect	sector_RECT;
	SDL_Texture	*texture;

	texture = this->_getTexture(defaultSector);
	sectorX = 0;
	while (sectorX < MAP_SIZE_X) {
		sectorY = 0;
		while (sectorY < MAP_SIZE_X) {
			sector_RECT = this->_getRectForSector(sectorX, sectorY);
			SDL_RenderCopy(this->_renderer, texture, 0, &sector_RECT);
			sectorY++;
		}
		sectorX++;
	}
}

	// add Objects to Renderer
void			Use_SDL2::_add_ObjectsToRenderer(std::vector<Object> & objects) {
	int			size;
	SDL_Rect	obj_RECT;
	SDL_Texture	*texture;

	size = objects.size();
	for (int i = 0; i < size; ++i)
	{
		Object		obj(objects[i]);
		obj_RECT = this->_getRectForSector(obj.sectorX, obj.sectorY);
		texture = this->_getTexture(obj.type);
		SDL_RenderCopy(this->_renderer, texture, 0, &obj_RECT);
	}
}


// MARK: - hendel event

void			Use_SDL2::_hendelEvent() {
	SDL_PumpEvents();
	if (this->_event.type == SDL_MOUSEBUTTONDOWN) {
		std::cout << "Hop\n";
	}
	if (this->_keyboardState[SDL_SCANCODE_W])
		*this->press_button = eTypeButton::button_w;
	if (this->_event.type == SDL_QUIT)
		*this->press_button = eTypeButton::quit;
}


// Changes is coming........................

SDL_Texture		*Use_SDL2::_getTexture(eTypeObj typeObj) {
	if (typeObj == eTypeObj::s1_Body)
		return this->_tBodySnake1;
	if (typeObj == eTypeObj::defaultSector)
		return this->_tDefaultSector;
	std::cout << "Miss texture " << typeObj << std::endl;
	return 0;
}

SDL_Rect		Use_SDL2::_getRectForSector(int sectorX, int sectorY) {
	SDL_Rect	Rect;
	int			offset = (this->_step - this->_sizeSector) / 2;
	t_coord		realCoord = _getRealCoord(sectorX, sectorY);

	Rect.w = this->_sizeSector;
	Rect.h = this->_sizeSector;
	Rect.x = realCoord.x + offset;
	Rect.y = realCoord.y + offset;
	return (Rect);
}

t_coord			Use_SDL2::_getRealCoord(int sectorX, int sectorY) {
	int			beginX = this->_beginPlayZone.x;
	int			beginY = this->_beginPlayZone.y;
	t_coord		coord;

	coord.x = beginX + this->_step * sectorX;
	coord.y = beginY + this->_step * sectorY;
	return coord;
}


// MARK: - init geometryc params, SDL, textures + destroy textures

void			Use_SDL2::_initGeometricParams(int size_h, int size_w) {
	this->_sizePlayZone = size_h <= size_w ? size_h - SIZE_H_HEDER : size_w - SIZE_H_HEDER;

	this->_sizePlayZone -= this->_sizePlayZone % MAP_SIZE_X;
	// Changes is coming.......................................
	this->_beginPlayZone.x = 0;
	this->_beginPlayZone.y = 0 + SIZE_H_HEDER;

	this->_endPlayZone.x = this->_beginPlayZone.x + this->_sizePlayZone;
	this->_endPlayZone.y = this->_beginPlayZone.y + this->_sizePlayZone;
	
	this->_step = this->_sizePlayZone / MAP_SIZE_X;
	this->_sizeSector = this->_step - this->_step / 10;

	this->_realSizeH = this->_sizePlayZone + SIZE_H_HEDER;
	this->_realSizeW = this->_sizePlayZone;
}

int				Use_SDL2::_initSDL() {
	this->_displayMode = SDL_DisplayMode();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	std::cout << SDL_GetDesktopDisplayMode(0, &(this->_displayMode)) << "\n";
	this->_win = SDL_CreateWindow("SDL2", 0, 0, this->_realSizeW, this->_realSizeH, SDL_WINDOW_SHOWN);
	if (_win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	this->_renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(this->_renderer, 25, 170, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(this->_renderer);
	SDL_RenderPresent(this->_renderer);
	this->_event = SDL_Event();
	this->_keyboardState = (Uint8 *)SDL_GetKeyboardState(0);
	return 0;
}

// Changes is coming.........................


int				Use_SDL2::_initTextures() {
	std::string		err;
	this->_tDefaultSector = IMG_LoadTexture(this->_renderer, PATH_tSector);
	this->_tBodySnake1 = IMG_LoadTexture(this->_renderer, PATH_tBodySnake1);
	return 0;
}

void			Use_SDL2::_destroyTextures() {
	SDL_DestroyTexture(this->_tDefaultSector);
	SDL_DestroyTexture(this->_tBodySnake1);
}