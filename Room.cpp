#include "Room.h"

Room::Room() : GameObject("room")
{
    this->description = "";
    this->imagePath="";
}

Room::~Room()
{
}

void Room::setDescription(string description)
{
    this->description = description;
}

string Room::getDescription()
{
    return this->description;
}

void Room::setExtendedDescription(string description)
{
    this->extendedDescription = description;
}

string Room::getExtendedDescription()
{
    return this->extendedDescription;
}

void Room::addDoor(Door * door)
{
    doors.push_back(door);
}


void Room::addItem(Item * item)
{
    items.push_back(item);
}

vector <Door *> Room::getDoors()
{
    return this->doors;
}

vector <Item *> Room::getItems()
{
    return this->items;
}

bool Room::takeItem(Item *item)
{
	vector<Item *>::iterator iter;
	for (iter = items.begin(); iter!=items.end(); iter++)
	{
		if(*iter==item)
		{
			items.erase(iter);
			return true;
		
		}
	}
	return false;	
}

void Room::setImage(string path)
{
	imagePath= path;
}

string Room::getImage()
{
	return imagePath;
} 


