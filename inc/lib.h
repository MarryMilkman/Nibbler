#ifndef LIB_H
#define LIB_H

# include <iostream>
# include <vector>

# define MAP_SIZE_X 30
# define MAP_SIZE_Y 30

enum eTypeButton
{
	quit = 100,
	button_w,
	button_s,
	button_d,
	button_a,
	button_esc,
	button_enter,
	button_space,
	button_1,
	button_2,
	button_3
};

enum eTypeObj
{
	s1_Head = 0,
	s1_Body,
	s1_Tail,
	s2_Head,
	s2_Body,
	s2_Tail,
	Obstacle,
	Food1,
	Food2,
	Food3,
	BonusFood,
	defaultSector
};

enum eDirection
{
	left = 50,
	right,
	up,
	down
}


// class Coord
// {
// public:
// 	Coord(int x, int y);
// 	Coord(Coord const & ref);
// 	~Coord();
	
// 	int	x;
// 	int	y;

// 	Coord	&operator=(Coord const & ref);
// 	bool	operator==(Coord const & ref);
// };

/////////////

// class	GameObj 
// {
// public:

// 	GameObj(Coord coordObj, eTypeObj typeObj);
// 	~GameObj();

// }

#endif