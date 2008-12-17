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
	setPlayer("ceiling cat");
	
	// create rooms;
	Room* outside = addRoom("outside", "You are outside, where the trees are");
	
	Room * inside = addRoom("inside", "You are inside. There are no more trees here");
	
	//add stuff to rooms
	Item * key = addItemToRoom("useful key", inside);
	Item * table = addItemToRoom("table", outside);
	
	//create door
	Door * door = addDoor("an entrance", outside, inside, true, key);
	
	// set player location
	player->setCurrentRoom(inside);
	
	// add something to inventory;
	Item * chair = addItemToInventory("a plain chair");
	
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
	door->setRoomOne(roomOne);
	roomOne->addDoor(door);
	door->setRoomTwo(roomTwo);
	roomTwo->addDoor(door);
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

Item* Playfield::addItemToInventory(string description)
{
	Item * item = new Item();
	item->setDescription(description);
	player->addItem(item);
	items.push_back(item);
	
	return item;
}



/*	  Room * addRoom(string description);
	  Door * addDoor(string description, Room * roomOne, Room * roomTwo, bool locked, Item * key);
	  Item* addItemToRoom(string description, Room* room);
	  Item* addItemToInventory(string description);  
*/