#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <map>
#include "Item.h"

struct cmp_str
// https://stackoverflow.com/questions/4157687/using-char-as-a-key-in-stdmap
{ // char*s can't be compared by pointer, so you have to strcmp for the hashmap
   bool operator()(char const *a, char const *b) const
   {
      return strcmp(a, b) < 0;
   }
};


class Room{
public:
	std::map<char*, Item, cmp_str> items; // stores items in the room
	const Room* north; // stores pointers to the rooms
	const Room* east;
	const Room* south;
	const Room* west;
	char name[256]; // name of the room

	Room(const char* name);

	bool itemExists(const char*); // checks if item is in the room
	Item getItem(const char*); // gets an item by name



};

#endif
