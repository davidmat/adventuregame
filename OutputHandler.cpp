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
    message="";
}

void OutputHandler::print(string messageId, ...)
{
	va_list arguments;
	va_start ( arguments, messageId );
	
	//va_arg ( arguments, string );
	
	if(messageId=="welcome")
	{
		message = "Welcome to the game! \n";
	}
	else if(messageId=="help")
	{
		message = "Game help: \n";
		message+= "Available commands: \n";
		message+= " * help: displays help message \n";
		message+= " * exit, quit: end the game \n";
		message+= " * look around: gives a description of your surroundings \n";
		message+= " * inventory: tells you what's in your inventory \n";
		message+= " * drop <item>: takes an item from your inventory and drops it on the floor \n";
		message+= " * take <item>: pick up a item and put in in your inventory \n";
		message+= " * open <door>: walk, through the rectangular hole of your choice, into the next room \n";
		
		int choice = rand() % 3 + 1;
		if(choice <=1)
		{
			message += "You're welcome! \n";
		}
		else if(choice <=2)
		{	
			message += "Glad to be of assistance. \n";
		}
		else
		{
			message += "People who need help are weak. \n";
		}
		
	}
	else if(messageId=="goodbye") 
	{
		message = "Bye!! \n";
	}
	else if(messageId=="sure")
	{
		message = "Are you sure you want to quit? (yes/no) \n";
	}
	else if(messageId=="invalid")
	{
		message = "I don't know what you mean... \n";
		message+= "Type 'help' to see a list of available commands \n";
	}
	else if(messageId=="look_error")
	{
		message = "You can't look at that, silly you! \n";
		int choice = rand() % 2 + 1;
		if(choice <=1)
		{
			message += "That's not even funny! \n";
		}
		else
		{
			message += "Your inferior intellect makes me weep \n";
			message+= "... tears of joy. \n";
		}
	}
	else if(messageId=="look")
	{
		message = "You decide to have a look around. \n";
	}
	else if(messageId=="look_contents")
	{
		message = "The room is full of stuff. You see: \n";
		message += va_arg (arguments, char*);
	}
	else if(messageId=="look_room")
	{
		message = "You find yourself in a warm and happy place, more specifically: ";
		message += va_arg (arguments, char*);
		message += "\nIt's ";
		message += va_arg (arguments, char*);
		message += "\n";
		
	}
	else if(messageId=="look_doors")
	{
		message = "You remember from your training course at MI-6 that you're supposed to scan the room for exits. \n";
		message+= "Reluctantly, you do so. There's: \n";
		message += va_arg (arguments, char*);
	}
		
	else if(messageId=="inventory") // must have extra argument
	{
		message = "Your inventory contains the following items: \n";
		message += va_arg (arguments, char*);
	}
	else if(messageId=="inventory_empty")
	{
		message = "Oh noes. Teh Inventories... they are empty! \n"; 
	}
	else if(messageId=="drop")
	{
		message = "You drop your ";
		message += va_arg (arguments, char*);
		message += " \n";
	}
	else if(messageId=="take")
	{
		int choice = rand() % 3 + 1;
		if(choice > 2)
		{
			message = "You start yelling \n";
			message += "MOOOMMMMYYYY! Pick up my ";
			message += va_arg (arguments, char*);
			message += "! NOW !! \n";
			message += "She picks it up for you and hits you in the face with it. \n";
			message += "Wow, that hurt. \n";
		}
		else
		{
			message = "You open you backpack and put the ";
			message += va_arg (arguments, char*);
			message += " in it \n" ;	
		}
	}
	else if(messageId=="win")
	{
		message = "You win! \n";
		message+= "It doesn't seem to have changed anything \n";
		message+= "Still, it did make you feel a little better inside \n";
	}
	else if(messageId=="chucknorris")
	{
		message= "Chuck Norris doesn’t wear a watch, HE decides what ..\n";
		message+="Oh no \n";
		message+="It's the Chuck... he's heeeeerrreeeee!!! \n";
		message+="CHUCK NORRIS SAYS: WHEN CHUCK NORRIS TALKS,EVERYBODY LISTENS. \n";
		message+="AND DIES \n";
		message+="*roundhouse kick* \n";
		message+="-- fly, zOOf, Boom, spLAT -- \n";
		message+="CHUCK NORRIS SAYS: GAME OVER SUCKA \n";
		
	}
	else if(messageId=="chuckwho")
	{
		message="Chuck WHO? \n";
		message+="There is only ONE Chuck \n";
	    message+="And he is not amused \n";
		message+="You lose 50 Million Billion HP (Chuck Norris Roundhouse Kick) \n";  
	}
	else if(messageId=="open_locked")
	{
		message= "Fiercly, you try to open the door. \n";
		message+= "Sadly, it seems locked. \n";
		message+= "Luckily, there is a rocket launcher standing right next to it. \n";
		message+= "Forcefully, you pick up the rocket launcher and prepare to blow up the door \n";
		message+= "Angrily, you notice that the rocket launcher requires a key to get it started \n";
		 
	}
	else if(messageId=="open_unlocked")
	{
		message = "You walk through the door \n";
	}
	else if(messageId=="open_key")
	{
		message = "You find the correct key in your inventory and put it in the rocket launcher \n";
		message+= "It starts up beautifully and kindly opens the door for you. \n";
		message+= "Thank you rocket launcher! \n";
	}
	else if(messageId=="open_nokey")
	{
		message = "But, then, suddenly, unexpectedly, in a bizarre plot twist, it seems... \n";
		message+="You have no key! \n";
	}	 
	else
	{
		message = "Output not implemented yet \n";
	}
	
	cout << message << flush;
}

string OutputHandler::getMessage()
{
	return message;
}
