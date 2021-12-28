#include "Room.h"

Room::Room(const char* name){
	memcpy(this->name, name, strlen(name));
	this->name[strlen(name)] = 0;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

