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
	string getExtendedDescription();
	void setExtendedDescription(string description);
	void addDoor(Door * door);
	void addItem(Item * item);
	vector <Door *> getDoors();
	vector <Item *> getItems();
	bool takeItem(Item * item);
	string getObjectType(){ return "room";};
	
private:
	string description;
	string extendedDescription;
	vector <Door *> doors;
	vector <Item *> items;	
};

#endif /*ROOM_H_*/
