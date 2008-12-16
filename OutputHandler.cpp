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

void OutputHandler::print(string messageId)
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
		cout << " * look at: looks at something" <<endl;
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
			sleep(2);
			cout << "... tears of joy." <<endl;
		}
	}	
	else
	{
		cout << "Output not implemented yet " << endl;
	}
}

