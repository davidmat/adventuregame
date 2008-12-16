#include "GameObject.h"

GameObject::GameObject(string o)
{
	objectType = o;
}

/*GameObject::GameObject(string o, string d)
{
	objectType = o;
	description = d;
}*/

GameObject::~GameObject()
{
}

string GameObject::getDescription()
{
	return description;	
}

string GameObject::getObjectType()
{
	return objectType;	
}

void GameObject::setDescription(string d)
{
	description = d;
}

