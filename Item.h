#ifndef ITEM_H
#define ITEM_H
#include <cstring>

class Item{
public:
	char name[256];
	bool is_win_cond; // if this is true, when you pick it up, you win

	Item(const char name[256], bool is_win_cond);
};

#endif
