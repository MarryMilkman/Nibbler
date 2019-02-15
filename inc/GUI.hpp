#ifndef GUI_HPP
# define GUI_HPP

# include "lib.h"

class Object;

class GUI
{
public:
	virtual ~GUI() {}

	virtual void	drawMapWhithObj(std::vector<Object> & objects) = 0;
};

#endif