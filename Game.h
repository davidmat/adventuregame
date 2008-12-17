#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include <string>
#include <iostream>

#include "Parser.h"
#include "Room.h"
#include "Player.h"
#include "Door.h"
#include "OutputHandler.h"
#include "Playfield.h"


using namespace std;


class Game
{
public:
	Game();
	void play();
	virtual ~Game();
private:
	void processCommand(vector <string> s);
	void initCommands();
	bool isCommandValid(string command);
/*	bool isCommandValidForObject(string command, string objectType);
	vector <string> getCommandsForObject(string objectType);
*/	
	bool running;
	vector <string> commandWords;
	vector <vector <string> >	commandHistory;
	Parser *parser;
	OutputHandler *o;
	Playfield *p;

};

#endif /*GAME_H_*/
