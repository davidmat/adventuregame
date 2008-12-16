#include "Game.h"

Game::Game()
{
	parser  = Parser::Instance();
	o  = OutputHandler::Instance();
	p = Playfield::Instance();
	
	initCommands();
	
}

void Game::play()
{
	running = true;
	
	o->print("welcome");
	
	
	while(running)
	{
		processCommand(parser->getInput());
	}
	
	o->print("goodbye");
		
	
	/*
	cout << "Your name is "<< p->getPlayer()->getName() <<"." << endl;

	cout << "You are now "<<p->getPlayer()->getCurrentRoom()->getDescription() << endl;
	
	cout << "Type continue" <<endl;
	commandHistory.push_back(parser->getInput());
	if(commandHistory.back().front() == "continue")
	{
		cout << "understood" <<endl;
		p->getPlayer()->move(p->getPlayer()->getCurrentRoom()->getDoors().back());
		
	}
	cout << "You are now "<<p->getPlayer()->getCurrentRoom()->getDescription() << endl;
	cout << "This is a " << p->getPlayer()->getCurrentRoom()->getObjectType() <<endl;
	
	Item chair(10, true, "chair");
	Item iphone(10, true, "pink iPhone");
	cout << chair.chucknorris() << endl;
	cout << m->getMessage("lol") << endl;
	Room a;
	Room b;
	Door door(&a, &b);
	Room c=*(door.getRoomOne());
	cout << door.getRoomOne()->getObjectType() <<endl;
	cout << iphone.chucknorris();
	*/
}

void Game::processCommand(vector <string> command)
{
	string first = command.front();
	
	// INVALID COMMAND
	if(!isCommandValid(first))
	{
		o->print("invalid");
		return; 
	}
	// HELP
	if(first=="help")
	{
		o->print("help");
	}
	// QUIT, EXIT (NOW)
	else if(first=="exit" || first=="quit")
	{
		if(command.size()>1){
			if(command[1]=="now"){
				running = false;
				return;
			}
		}
		string answer;
		do
		{
			o->print("sure");
			answer=parser->getInput().front();
		}
		while(answer!="yes"&&answer!="no"&&answer!="y"&&answer!="n");
		if(answer=="yes"||answer=="y")
		{
			running = false;
		}	
	}
	// LOOK
	else if(first=="look")
	{
		if(command.size()<3)
		{
			o->print("look_error");
		}
	}
		
}

void Game::initCommands()
{
	commandWords.push_back("exit");
	commandWords.push_back("help");
	commandWords.push_back("quit"); 
	commandWords.push_back("look");
	commandWords.push_back("pick");
	commandWords.push_back("use");
	commandWords.push_back("open");
	commandWords.push_back("go");
	commandWords.push_back("unlock");
	commandWords.push_back("drop");
	commandWords.push_back("lock");
	commandWords.push_back("chuck");
	commandWords.push_back("win");
	commandWords.push_back("inventory");	
}

bool Game::isCommandValid(string command)
{
	bool match = false;
	vector<string>::iterator iter;
	for (iter = commandWords.begin(); iter!=commandWords.end(); iter++) 
	{
    	if(*iter == command){
    		match = true;
    	}
	}
	return match;
}

bool Game::isCommandValidForObject(string command, string objectType)
{
		return true;
}

vector <string> Game::getCommandsForObject(string objectType)
{
	vector <string> s;
	return s;
}

Game::~Game()
{
}