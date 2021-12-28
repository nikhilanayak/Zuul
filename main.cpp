#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


#include "Room.h"
#include "Item.h"
#include "Game.h"
#include "Commands.h"

int main(){
	// Initialize items and rooms
	Item motorcycle = Item("Motorcycle", false);
	Item deadBody = Item("DeadBody", false);
	Item parentlessSuperhero = Item("Batman", false);
	Item rottenFood = Item("RottenFood", false);
	Item dog = Item("Dog", false);
	Item floatie = Item("Floatie", false);
	Item brokenSword = Item("BrokenSword", false);
	Item dirtyLaundry = Item("DirtyLaundry", false);
	Item Nothing = Item("Air", false);
	Item soap = Item("Soap", true);
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

	// link rooms to eachother and adds items
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

	// run the game
	play(&game);
		

}
