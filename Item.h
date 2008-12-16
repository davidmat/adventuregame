#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "GameObject.h"

using namespace std;

class Item : public GameObject
{
public:
	Item();
	Item(int weight, bool usable, string description);
	int getWeight();
	void setWeight(int);
	string getDescription();
	void setDescription(string);
	bool isUsable();
	void setUsable(bool);
	void use();
	void pickup();
	void drop();
	string chucknorris();
	string getObjectType(){ return "item";};
	virtual ~Item();
private:
	int weight;
	bool usable;
	string description;	
};

#endif /*ITEM_H_*/
