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
		cout << " * drop <item>: takes an item from your inventory and drops it on the floor \n";
		cout << " * take <item>: pick up a item and put in in your inventory \n";
		cout << " * open <door>: walk, through the rectangular hole of your choice, into the next room \n";
		
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
	else if(messageId=="drop")
	{
		cout << "You drop " << flush;
	}
	else if(messageId=="take")
	{
		cout << "Your mom comes running in and suddenly a new item appears in your backpack \n";
		cout << "Oh yeah, and it also seems to have disappeared from the room \n";
		cout << "Nevertheless, you decide to thoroughly enjouy your new " << flush;
	}
	else if(messageId=="win")
	{
		cout <<"You win!" << endl;
		cout <<"It doesn't seem to have changed anything" <<endl;
		cout <<"Still, it did make you feel a little better inside" << endl;
	}
	else if(messageId=="chucknorris")
	{
		cout <<"Chuck Norris doesn’t wear a watch, HE decides what .." << endl;
		sleep(2);
		cout <<"Oh no" << endl;
		sleep(2);
		cout <<"It's the Chuck... he's heeeeerrreeeee!!!" << endl;
		sleep(2);
		cout <<"CHUCK NORRIS SAYS: WHEN CHUCK NORRIS TALKS,EVERYBODY LISTENS." << endl;
		sleep(4);
		cout<<"AND DIES" << endl;
		cout<< "*roundhouse kick*" <<endl;
		cout<<"-- fly, zOOf, Boom, spLAT -- "<< endl;
		cout<<"CHUCK NORRIS SAYS: GAME OVER SUCKA" << endl;
		
	}
	else if(messageId=="chuckwho")
	{
		cout << "Chuck WHO?" << endl;
		cout << "There is only ONE Chuck" << endl;
		cout << "And he is not amused" << endl;
		cout << "You lose 50Million HP (Chuck Norris Face Kick)" <<endl;  
	}
	else if(messageId=="open_locked")
	{
		cout << "Fiercly, you try to open the door." << endl;
		cout << "Sadly, it seems locked." << endl;
		cout << "Luckily, there is a rocket launcher standing right next to it. " << endl;
		cout << "Forcefully, you pick up the rocket launcher and prepare to blow up the door" << endl;
		cout << "Angrily, you notice that the rocket launcher requires a key to get it started" << endl;
		 
	}
	else if(messageId=="open_unlocked")
	{
		cout << "You walk through the door" << endl;
	}
	else if(messageId=="open_key")
	{
		cout << "You find the correct key in your inventory and put it in the rocket launcher" << endl;
		cout << "It starts up beautifully and kindly opens the door for you. " << endl;
		cout << "Thank you rocket launcher!" << endl;
	}
	else if(messageId=="open_nokey")
	{
		cout << "But, then, suddenly, unexpectedly, in a bizarre plot twist, it seems... * tum dum tum *" << endl;
		cout << "You have key!" << endl;
	}	 
	else
	{
		cout << "Output not implemented yet " << endl;
	}
}

