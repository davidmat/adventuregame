#include "adventuregui.h"
#include "Game.h"

#include <QtGui>
#include <QApplication>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	Game game;
	if(argc>1)
	{
		string argument = string(argv[1]);
	
    	if(argument=="-c")
    	{
    		game.play();
    	
    		return 1;
    	}
	}	
    
    QApplication a(argc, argv);
   	adventureGUI w;
    w.show();
    
    return a.exec();
    
}
