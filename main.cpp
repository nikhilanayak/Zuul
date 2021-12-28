#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


#include "Room.h"
#include "Item.h"

struct cmp_str
// https://stackoverflow.com/questions/4157687/using-char-as-a-key-in-stdmap
{
   bool operator()(char const *a, char const *b) const
   {
      return strcmp(a, b) < 0;
   }
};


class Game{
public:
	Room* current_room;
	std::map<char*, Item> items;

	Game(Room* starting_room){
		current_room = starting_room;	
	}

	void move_to(Room* room){
		current_room = room;
		this->printRoom();
	}
	void pick_up(Item* item){
		std::pair<char*, Item> pair = std::make_pair(item->name, *item);
		items.insert(pair);
		if(item->is_win_cond){
			std::cout << "Congratulations, You Win!!!\n";
			exit(0);
		}
	}

	void drop(char name[256]){
		std::map<char*, Item>::iterator iter = items.find((char*)name);
		items.erase(iter);
	}

	void play(){
		this->printRoom();
		while(true){
			char input[256];
			std::cout << "Select A Command (p=pickup, m=move, d=drop): ";
			std::cin >> input;
			if(input[0] == 'p'){
				char itemName[256];
				std::cout << "Choose an item name: ";
				std::cin >> itemName;
				//auto it = this->current_room->items.begin();
				//bool found = false;

				auto it = this->current_room->items.find(itemName);
				if(it == this->current_room->items.end()){
					std::cout << "No Item Found\n";
				}
				else{
					//std::cout
					Item i = this->current_room->items.at(itemName);		
					std::cout <<

				}

				/*(for(int i = 0; i < this->current_room->items.size(); i++){ 
					// iterating over hashmap kinda defeats purpose, but I couldn't find out how to index if the key is a char*
					std::advance(it, i);
					if(strcmp(it->first, itemName) == 0){
						std::cout << it->first << "\n";
						this->items.insert(std::pair<char*, Item>(it->first, it->second));
						// TODO: remove from current room items
						
						std::cout << "found\n";
						found = true;
					}
				}

				if(!found){
					std::cout << "No Item Found\n";
				}*/




				/*if(this->items.find(itemName) != this->items.end()){
					Item item = this->items.at(itemName);
					std::cout << item.name << "\n";
				}
				else{
					std::cout << "No Item Found\n";
				}*/
			}
			else if(input[0] == 'm'){
				char roomName[256];
				std::cout << "Choose a room name: ";
				std::cin >> roomName;
				if(this->current_room->north != NULL && strcmp(this->current_room->north->name, roomName) == 0){
					this->move_to((Room*)this->current_room->north);
				}
				else if(this->current_room->east != NULL && strcmp(this->current_room->east->name, roomName) == 0){
					this->move_to((Room*)this->current_room->east);
				}
				else if(this->current_room->south != NULL && strcmp(this->current_room->south->name, roomName) == 0){
					this->move_to((Room*)this->current_room->south);
				}
				else if(this->current_room->west != NULL && strcmp(this->current_room->west->name, roomName) == 0){
					this->move_to((Room*)this->current_room->west);
				}
				else{
					std::cout << "No room found\n";
				}
			
			}
			else if(input[0] == 'd'){
				char itemName[256];
				std::cout << "Choose an item name: ";
				std::cin >> itemName;
				if(this->items.find(itemName) != this->items.end()){
					Item item = this->items.at(itemName);
					std::cout << item.name << "\n";
				}
				else{
					std::cout << "No Item Found\n";
				}

			}
		}
	}

	void printRoom(){
		std::cout << "\n\n\n";
		std::cout << "===================\n";
		std::cout << "You are in: " << this->current_room->name << "\n";
		std::cout << "Items in room are: \n";

		std::map<char*, Item>::iterator iter = this->current_room->items.begin();
		while(iter != this->current_room->items.end()){
			char* name = iter->first;
			Item i = iter->second;
			std::cout << name << "\n";
			iter++;
		}

		std::cout << "\n";
		std::cout << "Exits are: \n";
		std::cout << "North: " << ((this->current_room->north == NULL) ? "None" : this->current_room->north->name) << "\n";
		std::cout << "East: " << ((this->current_room->east == NULL) ? "None" : this->current_room->east->name) << "\n";
		std::cout << "South: " << ((this->current_room->south == NULL) ? "None" : this->current_room->south->name) << "\n";
		std::cout << "West: " << ((this->current_room->west == NULL) ? "None" : this->current_room->west->name) << "\n";
	}

};



int main(){
	Item motorcycle = Item("Motorcycle", false);
	Item deadBody = Item("DeadBody", false);
	Item parentlessSuperhero = Item("Batman", false);
	Item rottenFood = Item("RottenFood", false);
	Item dog = Item("Dog", false);
	Item floatie = Item("Floatie", false);
	Item brokenSword = Item("BrokenSword", false);
	Item dirtyLaundry = Item("DirtyLaundry", false);
	Item Nothing = Item("Air", false);
	Item soap = Item("Soap", false);
	Item cereal = Item("Cereal", false);

	Room garage = Room("Garage");
	Room entry = Room("Entry");
	Room kitchen = Room("Kitchen");
	Room diningHall = Room("DiningHall");
	Room backyard = Room("Backyard");
	Room garden = Room("Garden");
	Room batcave = Room("Batcave");
	Room dungeon = Room("Dungeon");
	Room pantry = Room("Pantry");
	Room pool = Room("Pool");
	Room smithy = Room("Smithy");
	Room armory = Room("Armory");
	Room bedroom = Room("Bedroom");
	Room balcony = Room("Balcony");
	Room bathroom = Room("Bathroom");

	garage.east = &entry;
	garage.south = &batcave;
	garage.items.insert(std::make_pair(motorcycle.name, motorcycle));
	garage.items.insert(std::make_pair(deadBody.name, deadBody));

	entry.west = &garage;
	entry.east = &kitchen;
	entry.south = &dungeon;

	kitchen.west = &entry;
	kitchen.east = &diningHall;
	kitchen.south = &pantry;
	kitchen.items.insert(std::make_pair(rottenFood.name, rottenFood));

	diningHall.east = &backyard;
	diningHall.west = &kitchen;
	
	backyard.east = &garden;
	backyard.east = &pool;
	backyard.west = &diningHall;
	backyard.items.insert(std::make_pair(dog.name, dog));

	batcave.north = &garage;
	batcave.east = &dungeon;
	batcave.items.insert(std::make_pair(parentlessSuperhero.name, parentlessSuperhero));

	dungeon.west = &batcave;
	dungeon.east = &bedroom;
	dungeon.items.insert(std::make_pair(soap.name, soap));

	pantry.north = &kitchen;
	pantry.items.insert(std::make_pair(cereal.name, cereal));

	pool.north = &backyard;
	pool.items.insert(std::make_pair(floatie.name, floatie));
	
	smithy.east = &armory;
	
	armory.east = &bedroom;
	armory.west = &smithy;
	armory.items.insert(std::make_pair(brokenSword.name, brokenSword));

	bedroom.north = &dungeon;
	bedroom.south = &balcony;
	bedroom.east = &bathroom;
	bedroom.items.insert(std::make_pair(dirtyLaundry.name, dirtyLaundry));

	bathroom.west = &bedroom;
	bathroom.items.insert(std::make_pair(Nothing.name, Nothing));
	
	Game game = Game(&entry);
	game.play();

}
