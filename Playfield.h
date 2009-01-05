#ifndef Playfield_H_
#define Playfield_H_

#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Item.h"
#include "Door.h"
#include "Player.h"

using namespace std;

class Playfield 
{
public:
      static Playfield* Instance();
      void create();
      Player * getPlayer();
      Room* getRoom(string description);
      Door* getDoor(string description);
      Item* getItem(string description);

protected:
      Playfield();
      Playfield(const Playfield&);
      Playfield& operator= (const Playfield&);

private:
	  void setPlayer(string name);
	  Room * addRoom(string description, string extendedDefinition, string image);
	  Door * addDoor(string description, Room * roomOne, Room * roomTwo, bool locked, Item * key);
	  Item* addItemToRoom(string description, Room* room);
	  Item* addItemToInventory(string description);  	

      vector <Room *> rooms;
      vector <Door *> doors;
      vector <Item *> items;
      Player * player;
      static Playfield* pinstance;

};

#endif /*Playfield_H_*/
