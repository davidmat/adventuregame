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
		if(command.size()<2)
		{
			o->print("invalid");
		} 
		else
		{
			if(command[1]=="around")
			{
				o->print("look");
				// describe the room
				string description = p->getPlayer()->getCurrentRoom()->getDescription();
				string extended = p->getPlayer()->getCurrentRoom()->getExtendedDescription();
				o->print("look_room", description.c_str(), extended.c_str());
				// describe the items you see
				vector <Item*> items = p->getPlayer()->getCurrentRoom()->getItems();
				if(items.size()>0)
				{
					string contents;					
					vector<Item *>::iterator iter;
					for (iter = items.begin(); iter!=items.end(); iter++)
					{
						contents += " * ";
						contents += (*iter)->getDescription(); 
						contents += "\n";
					}
					o->print("look_contents", contents.c_str()); 
				}
				// describe the doors
				vector <Door *> doors = p->getPlayer()->getCurrentRoom()->getDoors();
				if(doors.size()>0)
				{
					string doorz;
					vector<Door *>::iterator iter;
					for (iter = doors.begin(); iter!=doors.end(); iter++)
					{
						doorz += " * ";
						doorz += (*iter)->getDescription(); 
						doorz += "\n";
					}
					o->print("look_doors", doorz.c_str()); 
				}
				
			}
			else
			{
				o->print("look_error");
			}
		}
	}
	// INVENTORY
	else if(first=="inventory")
	{
		vector <Item * > inv = p->getPlayer()->getInventory();
		
		if(inv.size()==0)
		{
			o->print("inventory_empty");
		}
		else
		{
			string contents;
			vector<Item *>::iterator iter;
			for (iter = inv.begin(); iter!=inv.end(); iter++)
			{
				contents += " * ";
				contents += (*iter)->getDescription();
				contents += "\n";
			}
			const char *buf = contents.c_str();
			
			o->print("inventory", buf); 
		}
	}
	// DROP
	else if(first=="drop")
	{		
		if(command.size()<2)
		{
			o->print("invalid");
		}
		else
		{
			//get itemlist from the playfield..
			Item * item = p->getItem(command[1]);
			if(item == NULL)
			{
				o->print("invalid");
			}
			else
			{
				if(p->getPlayer()->takeItem(item))
				{
					string desc = item->getDescription();
					p->getPlayer()->getCurrentRoom()->addItem(item);
					o->print("drop", desc.c_str());
				}
			}
		}
		
	}
	// TAKE	
	else if(first=="take")
	{		
		if(command.size()<2)
		{
			o->print("invalid");
		}
		else
		{
			//get itemlist from the playfield..
			Item * item = p->getItem(command[1]);
			if(item == NULL)
			{
				o->print("invalid");
			}
			else
			{
				if(p->getPlayer()->getCurrentRoom()->takeItem(item))
				{
					string desc = item->getDescription();
					p->getPlayer()->addItem(item);
					o->print("take", desc.c_str());
				}
			}
		}
	}
	// WIN
	else if(first =="win")
	{
		o->print("win");
	}
	// CHUCK NORRIS
	else if((first == "chuck") && (command.size()>1))
	{
		if(command[1]=="norris")
		{
			o->print("chucknorris");
			running = false;
		}
		else
		{
			o->print("chuckwho");
			
		}

	}
	// OPEN
	else if (first == "open")
	{
		if(command.size()<2)
		{
			o->print("invalid");
		}
		else
		{
			vector <Item * > inv = p->getPlayer()->getInventory();
			Room * currentRoom = p->getPlayer()->getCurrentRoom();
			
			//get doors from the playfield..
			
			Door * door = p->getDoor(command[1]);
			if(door == NULL)
			{
				// door does not exist
				o->print("invalid");
			}
			else
			{
				// door exists, is it locked?   
    			string roomdesc = door->getDescription();
    			
    			if(door->isLocked())
    			{
    				Item * key = door->getKey();
    				string keydesc = key->getDescription();
    				
    				bool found = false; 
        			o->print("open_locked", roomdesc.c_str());
        			// check inventory for key
        			vector<Item *>::iterator iter;
					for (iter = inv.begin(); iter!=inv.end(); iter++)
					{
						if((*iter) == key)
						{
							found = true;
						}
					}
					if(found)
					{
						
						o->print("open_key", roomdesc.c_str(), keydesc.c_str());
						door->unlock(key);
					}
					else
					{
						o->print("open_nokey", keydesc.c_str());
					} 
        			
       		        
    			}
    			if(!door->isLocked())
				{
					o->print("open_unlocked", roomdesc.c_str());
					Room * r1 = door->getRoomOne();
        			Room * r2 = door->getRoomTwo();
        			if(currentRoom == r1)
        			{
            			p->getPlayer()->setCurrentRoom(r2);
        			}
        			else if (currentRoom == r2)
        			{
            			p->getPlayer()->setCurrentRoom(r1);
            		}
				}
					
			}
		}
	}
	// INVALID
	else
	{
		o->print("invalid");
	}
	
	// END OF COMMAND LIST	
}		


void Game::initCommands()
{
	commandWords.push_back("exit");
	commandWords.push_back("help");
	commandWords.push_back("quit"); 
	commandWords.push_back("look");
	commandWords.push_back("take");
	commandWords.push_back("open");
	commandWords.push_back("drop");
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

Game::~Game()
{
}
