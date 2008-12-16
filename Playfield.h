#ifndef Playfield_H_
#define Playfield_H_

#include <string>
#include <vector>
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
      vector <Room *> getRooms();
      Player * getPlayer();
protected:
      Playfield();
      Playfield(const Playfield&);
      Playfield& operator= (const Playfield&);
private:
      vector <Room *> rooms;
      Player * player;
      static Playfield* pinstance;

};

#endif /*Playfield_H_*/
