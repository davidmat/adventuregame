#include "Item.h"

Item::Item() : GameObject("item")
{
	weight=0;
	usable=false;
	description="default item";
}
Item::Item(int weight, bool usable, string description) : GameObject("item")
{
	this->weight=weight;
	this->usable=usable;
	this->description=description;
}

int Item::getWeight()
{
	return weight;
}

void Item::setWeight(int weight)
{
	this->weight=weight;
}

bool Item::isUsable()
{
	return usable;
}

void Item::setUsable(bool usable)
{
	this->usable=usable;
}

string Item::getDescription()
{
	return description;
}

void Item::setDescription(string description)
{
	this->description=description;
}

string Item::chucknorris()
{
	return "If Chuck Norris has a "+ description +" and you have a "
		+ description +", Chuck Norris has more "+ description +"s than you.";  
}

Item::~Item()
{
}
