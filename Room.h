#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <map>
#include "Item.h"

struct cmp_str
// https://stackoverflow.com/questions/4157687/using-char-as-a-key-in-stdmap
{
   bool operator()(char const *a, char const *b) const
   {
      return strcmp(a, b) < 0;
   }
};


class Room{
public:
	std::map<char*, Item, cmp_str> items;
	const Room* north;
	const Room* east;
	const Room* south;
	const Room* west;
	char name[256];

	Room(const char* name);

	bool itemExists(const char*);
	Item getItem(const char*);



};

#endif
