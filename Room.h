#ifndef ROOM_H_
#define ROOM_H_

#include "Door.h"
#include "Item.h"
#include "GameObject.h"
#include <string>
#include <vector>

using namespace std;

class Door;
class Room : public GameObject
{
public:
	Room();
	virtual ~Room();
	string getDescription();
	void setDescription(string);
	void addDoor(Door * door);
	void addItem(Item * item);
	vector <Door *> getDoors();
	vector <Item *> getItems();
	
	string getObjectType(){ return "room";};
	
private:
	string description;
	vector <Door *> doors;
	vector <Item *> items;	
};

#endif /*ROOM_H_*/
