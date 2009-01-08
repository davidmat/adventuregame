#include "Playfield.h"

Playfield* Playfield::pinstance = 0;// initialize pointer
Playfield* Playfield::Instance () 
{
    if (pinstance == 0)  // is it the first call?
    {  
      pinstance = new Playfield; // create sole instance
    }
    return pinstance; // address of sole instance
}

Playfield::Playfield() 
{ 
    create();
}

void Playfield::create()
{
	// create player
	setPlayer("ceiling cat");
	
	// create rooms;
	
	//first floor
	Room * frontyard = addRoom("front yard", "outside the main house, where the trees are", "img/frontyard.png");
	Room * backyard = addRoom("back yard", "outside, behind the house. There is pond out here", "img/backyard.png");
	Room * gardenhouse = addRoom("garden house", "the small wooden building in the back yard", "img/gardenshed.png");
	Room * garage = addRoom("garage", "where the car sleeps", "img/garage.png");
	Room * hallway = addRoom("hallway", "where you enter the house", "img/hallway.png");
	Room * livingroom = addRoom("living room", "where we live", "img/livingroom.png");
	Room * kitchen = addRoom("kitchen", "where the munchies are made", "img/kitchen.png");
	Room * storage = addRoom("storage room", "where the munchies are stored", "img/storage.png");
	Room * veranda = addRoom("veranda", "between the kitchen and the back yard", "img/veranda.png");
	
	//second floor
	Room * bathroom = addRoom("bath room", "where the girls spent most of their time", "img/bathroom.png");
	Room * landing = addRoom("landing", "the space to go from one room to the other", "img/landing.png");
	Room * guestroom = addRoom("guest room", "where the guests sleep", "img/guestroom.png");
	Room * bedroom = addRoom("bed room", "where you sleep", "img/bedroom.png");
	Room * balcony = addRoom("balcony", "where you go get some air", "img/balcony.png");
	
	//attic
	Room * frontattic = addRoom("front side of the attic", "where they keep the garbage", "img/frontattic.png");
	Room * backattic = addRoom("hidden back side of the attic", "where they hide stuff", "img/backattic.png");
	Room * vault = addRoom("vault", "where you win", "img/vault.png");
	
	//add stuff to rooms
	Item * kitchenkey = addItemToRoom("kitchen key", balcony);
	Item * garagekey = addItemToRoom("garage key", vault);
	Item * bedroomkey = addItemToRoom("bedroom key", vault);
	Item * elevatorbutton = addItemToRoom("elevator button", garage);
	Item * bathroomkey = addItemToRoom("key to the bathroom", guestroom);
	Item * ladder = addItemToRoom("strong ladder", storage);
	Item * drill = addItemToRoom("heavy looking drill", garage);
	Item * mainkey = addItemToRoom("key to the house", gardenhouse);
	Item * table = addItemToRoom("table", frontyard);
	Item * rubiks_cube = addItemToRoom("rubiks cube", garage);
	Item * horse = addItemToRoom("horse", hallway);
	
	
	//create door
	Door * fence = addDoor("fence", frontyard, backyard, false, NULL);
	Door * gate = addDoor("gate", frontyard, garage, false, NULL);
	Door * gardenhousedoor = addDoor("garden house door", backyard, gardenhouse, false, NULL);
	Door * verandadoor = addDoor("veranda door", backyard, veranda, false, NULL);
	Door * kitchendoor = addDoor("kitchen door", veranda, kitchen, true, kitchenkey);
	Door * mainentrance = addDoor("main entrance", frontyard, hallway, true, mainkey);
	Door * garagedoor = addDoor("garage door", garage, hallway, true, garagekey);
	Door * elevator = addDoor("elevator", hallway, landing, true, elevatorbutton);
	Door * livingdoor = addDoor("living/hallway door", hallway, livingroom, false, NULL);
	Door * kitchenlivingdoor = addDoor("living/kitchen door", livingroom, kitchen, false, NULL);
	Door * storagedoor = addDoor("storage door", kitchen, storage, false, NULL);
	
	Door * bathroomdoor = addDoor("bath room door", landing, bathroom, true, bathroomkey);
	Door * bedroomdoor = addDoor("bedroom door", landing, bedroom, true, bedroomkey);
	Door * guestroomdoor = addDoor("landing/guestroom door", landing, guestroom, false, NULL);
	Door * balcony1 = addDoor("balcony/guestroom door", guestroom, balcony, false, NULL);
	Door * balcony2 = addDoor("balcony/bedroom door", bedroom, balcony, false, NULL);
	Door * hatch = addDoor("attic hatch", bedroom, frontattic, true, ladder);
	Door * curtain = addDoor("curtain", frontattic, backattic, false, NULL);
	Door * vaultdoor = addDoor("vault door", backattic, vault, true, drill);
	
	// set player location
	player->setCurrentRoom(frontyard);
	
	// add something to inventory;
	Item * chair = addItemToInventory("a plain chair");
	
}

Player * Playfield::getPlayer()
{
	return player;
}

Room* Playfield::getRoom(string description)
{
	vector<Room* >::iterator iter;
	for (iter = rooms.begin(); iter!=rooms.end(); iter++) 
	{
		if((*iter)->getDescription()==description)
		{
			return *iter;
		} 
	}
	return NULL;
}

Door* Playfield::getDoor(string description)
{
	vector<Door* >::iterator iter;
	for (iter = doors.begin(); iter!=doors.end(); iter++) 
	{
		if((*iter)->getDescription()==description)
		{
			return *iter;
		} 
	}
	return NULL;
}

Item* Playfield::getItem(string description)
{
	vector<Item* >::iterator iter;
	for (iter = items.begin(); iter!=items.end(); iter++) 
	{
		if((*iter)->getDescription()==description)
		{
			return *iter;
		} 
	}
	return NULL;
}

void Playfield::setPlayer(string name)
{
	player  = new Player();
	player->setDescription("me");
	player->setName(name);
}

Room * Playfield::addRoom(string description, string extendedDescription, string image)
{
	Room * room = new Room();
	room->setDescription(description);
	room->setExtendedDescription(extendedDescription);
	room->setImage(image);
	
	rooms.push_back(room);
	
	return room;
}

Door * Playfield::addDoor(string description, Room * roomOne, Room * roomTwo, bool locked, Item * key)
{
	Door * door = new Door();
	door->setDescription(description);
	door->setRoomOne(roomOne);
	roomOne->addDoor(door);
	door->setRoomTwo(roomTwo);
	roomTwo->addDoor(door);
	if(locked)
	{
		door->lock(key);
	}
	doors.push_back(door);
	
	return door;
}

Item* Playfield::addItemToRoom(string description, Room* room)
{
	Item * item = new Item();
	item->setDescription(description);
	room->addItem(item);
	items.push_back(item);
	
	return item;
}

Item* Playfield::addItemToInventory(string description)
{
	Item * item = new Item();
	item->setDescription(description);
	player->addItem(item);
	items.push_back(item);
	
	return item;
}


