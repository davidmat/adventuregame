#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>

using namespace std;

class GameObject
{
public:
	GameObject(string);
//	GameObject(string,string);
	void setDescription(string);
	string getDescription();
	string getObjectType();
	virtual ~GameObject();

private:
	string description;
	string objectType;
};



#endif /*GAMEOBJECT_H_*/
