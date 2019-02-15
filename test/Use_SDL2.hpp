#ifndef USE_SDL_HPP
# define USE_SDL_HPP

# include "lib.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

// MARK: define for texture in resurses
# define PATH_tSector "./resurses/defaultSector.png"
# define PATH_tBodySnake1 "./resurses/diam.jpg"

# define SIZE_H_HEDER 40

// # define MIN_WINDOW_H = 500
// # define MIN_WINDOW_W = 500
// # define MAX_WINDOW_H = 1600
// # define MAX_WINdow_W = 1600

// typedef struct		s_texture
// {
// 	SDL_Texture		*texture;
// 	eTypeObj		type;
// }					t_texture;

class	Object;


typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

class Use_SDL2
{
public:
	Use_SDL2(int size_h, int size_w, int *press_button);
	Use_SDL2(Use_SDL2 const & ref);
	~Use_SDL2();

	Use_SDL2		&operator=(Use_SDL2 const & ref);

	int				*press_button; // override

	void			drawMapWhithObj(std::vector<Object> & objects); // override

protected:
	SDL_Window					*_win;
	SDL_Renderer				*_renderer;
	SDL_DisplayMode				_displayMode;
	SDL_Event					_event;
	Uint8 						*_keyboardState;
	// std::vector<t_texture>		textures;

	int							_realSizeH;
	int							_realSizeW;

	t_coord						_beginPlayZone;
	t_coord						_endPlayZone;

	int							_sizePlayZone;
	int							_sizeSector;
	int							_step;

	t_coord						_getRealCoord(int sectorX, int sectorY);
	SDL_Rect					_getRectForSector(int sectorX, int sectorY);

	void						_initGeometricParams(int size_h, int size_w);
	int							_initSDL();
	int							_initTextures();
	void						_destroyTextures();

	SDL_Texture					*_getTexture(eTypeObj);

	void						_add_MapToRenderer();
	void						_add_ObjectsToRenderer(std::vector<Object> & objects);

	void						_hendelEvent();

	// MARK: - Textures
	SDL_Texture					*_tDefaultSector;
	SDL_Texture					*_tBodySnake1;
};

#endif