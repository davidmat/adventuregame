#include "Player.h"

Player::Player() : GameObject("player")
{
}

Player::~Player()
{
}

void Player::setName(string name)
{
    this->name = name;
}

string Player::getName()
{
    return this->name;
}


Room * Player::getCurrentRoom()
{
    return currentRoom;
}

void Player::setCurrentRoom(Room * room)
{
    currentRoom = room;
}

int Player::getMaxWeight()
{
    return this->maxWeight;
}

void Player::setMaxWeight(int maxW)
{
    this->maxWeight = maxW;
}

vector <Item *> Player::getInventory()
{
	return inventory;
}

void Player::addItem(Item * item)
{
	inventory.push_back(item);
}

bool Player::takeItem(Item *item)
{
	vector<Item *>::iterator iter;
	for (iter = inventory.begin(); iter!=inventory.end(); iter++)
	{
		if(*iter==item)
		{
			inventory.erase(iter);
			return true;
		
		}
	}
	return false;	
} 
	
	
