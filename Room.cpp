#include "Room.h"

Room::Room(const char* name){
	memcpy(this->name, name, strlen(name));
	this->name[strlen(name)] = 0;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

bool Room::itemExists(const char* name){
	return this->items.find((char*)name) != this->items.end();
}

Item Room::getItem(const char* name){
	return this->items.at((char*)name);
}

