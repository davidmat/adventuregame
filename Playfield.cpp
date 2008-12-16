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
	player->setName("Ceiling cat");
	// create rooms;
	Room * outside = new Room();
	outside->setDescription("outside");
	rooms.push_back(outside);
	Room * inside = new Room();
	inside->setDescription("inside");
	rooms.push_back(inside);
	//create door
	Door * door = new Door(outside, inside);
	
	inside->addDoor(door);
	outside->addDoor(door);
	
	// set player location
	player->setCurrentRoom(outside);
	
}


vector <Room *> Playfield::getRooms()
{
	return rooms;
}

Player * Playfield::getPlayer()
{
	return player;
}



