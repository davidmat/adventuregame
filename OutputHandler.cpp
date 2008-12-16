#include "OutputHandler.h"

OutputHandler* OutputHandler::pinstance = 0;// initialize pointer
OutputHandler* OutputHandler::Instance () 
{
    if (pinstance == 0)  // is it the first call?
    {  
      pinstance = new OutputHandler;  // create sole instance
    }
    return pinstance; // address of sole instance
}

OutputHandler::OutputHandler() 
{ 
    srand( time(NULL) );
}

void OutputHandler::print(string messageId, ...)
{
	if(messageId=="welcome")
	{
		cout << "Welcome to the game!" <<endl;
	}
	else if(messageId=="help")
	{
		cout << "Game help: \n";
		cout << "Available commands: \n";
		cout << " * help: displays help message \n";
		cout << " * exit, quit: end the game \n";
		cout << " * look around: gives a description of your surroundings \n";
		cout << " * inventory: tells you what's in your inventory \n"; 
		
		int choice = rand() % 3 + 1;
		if(choice <=1)
		{
			cout << "You're welcome!" << endl;
		}
		else if(choice <=2)
		{	
			cout << "Glad to be of assistance." <<endl;
		}
		else
		{
			cout << "People who need help are weak." <<endl;
		}
		
	}
	else if(messageId=="goodbye") 
	{
		cout << "Bye!!" <<endl;
	}
	else if(messageId=="sure")
	{
		cout << "Are you sure you want to quit? (yes/no)" << endl;
	}
	else if(messageId=="invalid")
	{
		cout << "I don't know what you mean... \n";
		cout << "Type 'help' to see a list of available commands" << endl;
	}
	else if(messageId=="look_error")
	{
		cout << "You can't look at that, silly you!" << endl;
		int choice = rand() % 2 + 1;
		if(choice <=1)
		{
			cout << "That's not even funny!" << endl;
		}
		else
		{
			cout << "Your inferior intellect makes me weep" <<flush;
			sleep(1);
			cout << "... tears of joy." <<endl;
		}
	}
	else if(messageId=="look")
	{
		cout << "You decide to have a look around." << endl;
	}
	else if(messageId=="look_contents")
	{
		cout << "The room is full of stuff. You see: " << endl;
	}
	else if(messageId=="look_room")
	{
		cout << "You find yourself in a warm and happy place, more specifically: " << flush;
	}
	else if(messageId=="look_doors")
	{
		cout << "You remember from your training course at MI-6 that you're supposed to scan the room for exits." << endl;
		cout << "Reluctantly, you do so. There's:" << endl;
	}
		
	else if(messageId=="inventory")
	{
		cout<< "Your inventory contains the following items: " << endl;
	}
	else if(messageId=="inventory_empty")
	{
		cout << "Oh noes. Teh Inventories... they are empty!" << endl; 
	}	
	else
	{
		cout << "Output not implemented yet " << endl;
	}
}

