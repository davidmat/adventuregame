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

int Player::move(Door * door)
{
    //returns:
    // i = -1  ->  door is locked and you don't have correct key
    // i = 0   ->  you opened door and moved on to next room
    // i = 1   ->  this door isn't situated in the room you are currently in
    // i = 9   ->  shouldn't happen ^_^
    int i = 9;
    if(door->isLocked())
    {
        Item * key = door->getKey();
        // loop through inventory and check wether you got the correct key
        for (int j=0;j<inventory.size();j++)
        {
            if(key == inventory[j])
            {
                door->unlock(key);
                // echo you unlock the door with the correct key
                break;
            }
        }
        // you looped through inventory without finding the correct key...
        i = -1;
    }
    if(!door->isLocked())
    {
        Room * r1 = door->getRoomOne();
        Room * r2 = door->getRoomTwo();
        if(currentRoom == r1)
        {
            this->currentRoom = r2;
            i = 1;
        }
        else if (this->currentRoom == r2)
        {
            this->currentRoom = r1;
            i = 1;
        } else
        {
            i = 0;
        }
    }

    return i;

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
	
	
