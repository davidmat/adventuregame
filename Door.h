#ifndef DOOR_H_
#define DOOR_H_

#include "Item.h"
#include "Room.h"
#include "GameObject.h"

using namespace std;

class Room;
class Door : public GameObject
{
public:
	Door();
	Door(Room *r1, Room *r2);
	void lock(Item  * key);
	bool unlock(Item * key);
	bool isLocked();
	void setRoomOne(Room * room);
	void setRoomTwo(Room * room);
	Room * getRoomOne();
	Room * getRoomTwo();
	Item * getKey();
	string getObjectType(){ return "door";};
	virtual ~Door();

private:
	bool locked;
	Item * key;
	Room * room1;
	Room * room2;
};

#endif /*DOOR_H_*/
