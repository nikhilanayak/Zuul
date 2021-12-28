#ifndef COMMANDS_H
#define COMMANDS_H

#include "Room.h"
#include "Item.h"
#include "Game.h"

void move(Game *g)
{ // takes input and moves the player accordingly
    std::cout << "Where do you want to move to: ";
    char roomName[256];
    memset(roomName, 0, 256);
    std::cin >> roomName;
    if (g->current_room->north != NULL && strcmp(g->current_room->north->name, roomName) == 0)
    {
        g->move_to((Room *)g->current_room->north);
    }
    else if (g->current_room->east != NULL && strcmp(g->current_room->east->name, roomName) == 0)
    {
        g->move_to((Room *)g->current_room->east);
    }
    else if (g->current_room->south != NULL && strcmp(g->current_room->south->name, roomName) == 0)
    {
        g->move_to((Room *)g->current_room->south);
    }
    else if (g->current_room->west != NULL && strcmp(g->current_room->west->name, roomName) == 0)
    {
        g->move_to((Room *)g->current_room->west);
    }
    else
    {
        std::cout << "No room found\n";
    }
}


void drop(Game* g){ // move an item from player's inventory to room
    char* itemName = new char[256];
    memset(itemName, 0, 256);
    std::cout << "What item: ";
    std::cin >> itemName;

    if(g->itemExists(itemName)){
        Item i = g->items.at(itemName);
        g->items.erase(itemName);
        g->current_room->items.insert(std::make_pair<char*, Item>((char*)itemName, (Item)i));
    }
    else{
        std::cout << "No Item Found\n";
    }
}

void pickup(Game* g){ // moves item from room to player's inventory
    char* itemName = new char[256];
    memset(itemName, 0, 256);
    std::cout << "What item: ";
    std::cin >> itemName;

    if(g->current_room->itemExists(itemName)){
        Item i = g->current_room->items.at(itemName);

        if(i.is_win_cond){
            std::cout << "You Picked Up The Secret Item! You Win The Game!\n";
            exit(0);
        }

        g->current_room->items.erase(itemName);
        g->items.insert(std::make_pair<char*, Item>((char*)itemName, (Item)i));
    }
    else{
        std::cout << "No Item Found\n";
    }

}


void parse(Game *g, char *input)
{ // parses input and runs one of the functions above if applicable
    if(input[0] == 'q'){
        std::cout << "Thanks for playing, maybe you'll finish next time!\n";
        exit(0);
    }
    else if (input[0] == 'm')
    {
        move(g);
    }
    else if (input[0] == 'd')
    {
        drop(g);
    }
    else if (input[0] == 'p')
    {
        pickup(g);
    }
}


void play(Game *g)
{ // runs the main loop
    while (true)
    {
        g->printRoom();

        std::cout << "Enter a command (m=move, d=drop, p=pickup, q=quit): ";
        char command[256];
        memset(command, 0, 256);
        std::cin >> command;
        parse(g, command);


    }
}

#endif