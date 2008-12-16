#include "Room.h"

Room::Room() : GameObject("room")
{
    this->description = "";
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




