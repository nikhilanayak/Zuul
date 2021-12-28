#ifndef GAME_H
#define GAME_H


class Game{
public:
	Room* current_room;
	std::map<char*, Item, cmp_str> items; // items in your inventory

	Game(Room* starting_room){
		current_room = starting_room;	
	}

	void move_to(Room* room){
		current_room = room;
	}
	void drop(char name[256]){
		std::map<char*, Item>::iterator iter = items.find((char*)name);
		items.erase(iter);
	}

	
	void printRoom(){
		std::cout << "\n";
		std::cout << "===================\n";
		std::cout << "You are in: " << this->current_room->name << "\n";
		std::cout << "Items in room are: ";

		std::map<char*, Item>::iterator iter = this->current_room->items.begin();
		while(iter != this->current_room->items.end()){
			char* name = iter->first;
			std::cout << name << ", ";
			iter++;
		}
		std::cout << "\n";


		std::cout << "You are holding: ";
		iter = this->items.begin();
		while(iter != this->items.end()){
			char* name = iter->first;
			std::cout << name << ", ";
			iter++;
		}
		std::cout << "\n";



		std::cout << "\n";
		std::cout << "Exits are: \n";
		std::cout << "North: " << ((this->current_room->north == NULL) ? "None" : this->current_room->north->name) << "\n";
		std::cout << "East: " << ((this->current_room->east == NULL) ? "None" : this->current_room->east->name) << "\n";
		std::cout << "South: " << ((this->current_room->south == NULL) ? "None" : this->current_room->south->name) << "\n";
		std::cout << "West: " << ((this->current_room->west == NULL) ? "None" : this->current_room->west->name) << "\n";
	}

	bool itemExists(const char* name){
		return this->items.find((char*)name) != this->items.end();
	}

	Item getItem(const char* name){
		return this->items.at((char*)name);
	}

};


#endif