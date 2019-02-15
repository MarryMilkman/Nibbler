#include "Object.hpp"

Object::Object(eTypeObj type, int sectorX, int sectorY) : type(type), sectorX(sectorX),
			sectorY(sectorY)
{
}

Object::Object(Object const & ref) {
	*this = ref;
}

Object::~Object() {}

Object		&Object::operator=(Object const & ref) {
	this->type = ref.type;
	this->sectorY = ref.sectorY;
	this->sectorX = ref.sectorX;
	return *this;
}