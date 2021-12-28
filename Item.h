#ifndef ITEM_H
#define ITEM_H
#include <cstring>

class Item{
public:
	char name[256];
	bool is_win_cond;

	Item(const char name[256], bool is_win_cond);
};

#endif
