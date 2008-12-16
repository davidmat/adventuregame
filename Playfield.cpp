#include "Playfield.h"

Playfield* Playfield::pinstance = 0;// initialize pointer
Playfield* Playfield::Instance () 
{
    if (pinstance == 0)  // is it the first call?
    {  
      pinstance = new Playfield; // create sole instance
    }
    return pinstance; // address of sole instance
}

Playfield::Playfield() 
{ 
    create();
}

void Playfield::create()
{
	// create player
	player = new Player();
	player->setName("You");
	
	// create rooms;
	Room * outside = new Room();
	outside->setDescription("outside");
	rooms.push_back(outside);
	
	Room * inside = new Room();
	inside->setDescription("inside");
	rooms.push_back(inside);
	
	//add stuff to rooms
	Item * key = new Item();
	key->setDescription("useful key");
	inside->addItem(key);
	
	Item * table = new Item();
	table->setDescription("plain table");
	outside->addItem(table);
	
	//create door
	Door * door = new Door(outside, inside);
	door->setDescription("north emergency exit");
	
	inside->addDoor(door);
	outside->addDoor(door);
	
	
	// set player location
	player->setCurrentRoom(outside);
	
	// add something to inventory;
	Item * chair = new Item();
	chair->setDescription("a plain chair");
	//player->addItem(chair);

	
}


vector <Room *> Playfield::getRooms()
{
	return rooms;
}

Player * Playfield::getPlayer()
{
	return player;
}



