#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "GameObject.h"

using namespace std;

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();
	void setName(string);
	string getName();
	int move(Door *d);
	Room * getCurrentRoom();
	void setCurrentRoom(Room *r);
	int getMaxWeight();
	void setMaxWeight(int);
	vector <Item *> getInventory();
	void addItem(Item * item);
	bool takeItem(Item *item);
	string getObjectType(){ return "player";};
	
private:
	Room* currentRoom;
	string name;
	vector <Item *> inventory;
	int maxWeight;	
};

#endif /*PLAYER_H_*/
