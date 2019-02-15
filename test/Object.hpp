#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "lib.h"

class Object
{
public:
	Object(eTypeObj type, int sectorX, int sectorY);
	Object(Object const & ref);
	~Object();
	
	Object		&operator=(Object const & ref);

	eTypeObj		type;
	int				sectorX;
	int				sectorY;
};

#endif