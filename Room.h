#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <map>
#include "Item.h"

class Room{
public:
	std::map<char*, Item> items;
	const Room* north;
	const Room* east;
	const Room* south;
	const Room* west;
	char name[256];

	Room(const char* name);



};

#endif
