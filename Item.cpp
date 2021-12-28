#include <cstring>
#include <iostream>
#include "Item.h"
Item::Item(const char name[256], bool is_win_cond){
	memcpy(this->name, name, 256);
	//std::cout << this->name << "\n";
	this->is_win_cond = is_win_cond;
}

