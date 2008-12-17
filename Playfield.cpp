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

Player * Playfield::getPlayer()
{
	return player;
}

Room* Playfield::getRoom(string description)
{
	vector<Room* >::iterator iter;
	for (iter = rooms.begin(); iter!=rooms.end(); iter++) 
	{
		if((*iter)->getDescription()==description)
		{
			return *iter;
		} 
	}
	return NULL;
}

Door* Playfield::getDoor(string description)
{
	vector<Door* >::iterator iter;
	for (iter = doors.begin(); iter!=doors.end(); iter++) 
	{
		if((*iter)->getDescription()==description)
		{
			return *iter;
		} 
	}
	return NULL;
}

Item* Playfield::getItem(string description)
{
	vector<Item* >::iterator iter;
	for (iter = items.begin(); iter!=items.end(); iter++) 
	{
		if((*iter)->getDescription()==description)
		{
			return *iter;
		} 
	}
	return NULL;
}

void Playfield::setPlayer(string name)
{
	player  = new Player();
	player->setDescription("me");
	player->setName(name);
}

Room * Playfield::addRoom(string description, string extendedDescription)
{
	Room * room = new Room();
	room->setDescription(description);
	room->setExtendedDescription(extendedDescription);
	
	rooms.push_back(room);
	
	return room;
}

Door * Playfield::addDoor(string description, Room * roomOne, Room * roomTwo, bool locked, Item * key)
{
	Door * door = new Door();
	door->setDescription(description);
	door->setRoomOne(roomOne):
	door->setRoomTwo(roomTwo);
	if(locked)
	{
		door->lock(key);
	}
	doors.push_back(door);
	
	return door;
}

Item* Playfield::addItemToRoom(string description, Room* room)
{
	Item * item = new Item();
	item->setDescription(description);
	room->addItem(item);
	items.push_back(item);
	
	return item;
}


/*	  Room * addRoom(string description);
	  Door * addDoor(string description, Room * roomOne, Room * roomTwo, bool locked, Item * key);
	  Item* addItemToRoom(string description, Room* room);
	  Item* addItemToInventory(string description);  
*/