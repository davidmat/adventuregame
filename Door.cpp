#include "Door.h"


Door::Door() : GameObject("door")
{
	locked=false;
}
Door::Door(Room *r1, Room *r2) : GameObject("door")
{
	locked=false;
	room1 = r1;
	room2 = r2;	
}

void Door::lock(Item * key)
{
	this->key=key;
	locked =true;
	
}

bool Door::unlock(Item * key)
{
	if (this->key == key)
	{
		locked = false;
	}
	
	return locked;
}

bool Door::isLocked()
{
	return locked;
}

void Door::setRoomOne(Room * room)
{
	room1 = room;
}

void Door::setRoomTwo(Room * room)
{
	room2 = room;
}

Room * Door::getRoomOne()
{
	return room1;
}
		
Room * Door::getRoomTwo()
{
	return room2;
	
}

Item * Door::getKey()
{
	return key;
}

Door::~Door()
{
}
