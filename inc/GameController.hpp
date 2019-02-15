#ifndef GAME_CONTROLLER_HPP
# define GAME_CONTROLLER_HPP

# include "lib.h"
# include "GUI.hpp"

class GameController
{
public:
	GameController();
	~GameController();



private:


	int						_countPlayer;
	std::vector<iSnake *>	_players;

	int						*_input;
};

#endif