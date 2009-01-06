#include "adventuregui.h"
#include "Game.h"

#include <QtGui>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QTextBrowser>
#include <QLabel>

using namespace std;

adventureGUI::adventureGUI(QWidget *parent)
    : QWidget(parent)
{
	// TODO: add pixmap van room	
	//ui.setupUi(this);
	
	setLayout(new QHBoxLayout);
	paint();
}

void adventureGUI::paint()
{
	QList<QObject*> child = children();
	for(int i = 0; i < child.count(); i++)
		if(child[i]->isWidgetType())
	  		child[i]->deleteLater();   
	
	Playfield *p;
	p = Playfield::Instance();
	
	
	createItemButtons();
	createDoorButtons();
	createInventoryButtons();
	    
    layout()->addWidget(itemButtons);
    layout()->addWidget(doorButtons);
    layout()->addWidget(inventoryButtons);
    
    OutputHandler *o;
    o = OutputHandler::Instance();
    string message = o->getMessage();
    QString qmessage = QString::fromUtf8(message.c_str());
    
    // textarea to print extra info
    QTextBrowser *textBrowser = new QTextBrowser();
	//textBrowser->setMinimumHeight (100);
	//textBrowser->setMinimumHeight (200);
	textBrowser->append(qmessage);
	layout()->addWidget(textBrowser);
	
	// pic of room
	QLabel *imageLabel = new QLabel;
	QImage image("img/conference_room.bmp");	
	imageLabel->setPixmap(QPixmap::fromImage(image));
	layout()->addWidget( imageLabel );	
	/*string s = p->getPlayer()->getCurrentRoom()->getImage();
	QString path = QString::fromUtf8(s.c_str());		
	QImage image(path);										// werkt nog niet!
	imageLabel->setPixmap(QPixmap::fromImage(image));
	layout()->addWidget( imageLabel );*/
		
	// heading
	string s = p->getPlayer()->getCurrentRoom()->getDescription();
	QString kamer = "You are in the " + QString::fromUtf8(s.c_str());
    setWindowTitle(kamer);    
}

void adventureGUI::doorButtonClicked()
{

	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		//QString value = "you walk through this door: " + btn->text();
		//QMessageBox::information(0, "button clicked text", value);
				
		QString Str = btn->text();
		string str = Str.toStdString();
		
		Playfield *p;
		p = Playfield::Instance();
		
		vector <string> input;
		input.push_back("open");
        input.push_back(str);
        
        game.processCommand(input);
        
		paint();
		
	}
}

void adventureGUI::inventoryButtonClicked()
{

	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		//QString value = "you drop this item: " + btn->text();
		//QMessageBox::information(0, "button clicked text", value);
				
		QString Str = btn->text();
		string str = Str.toStdString();
		
		vector <string> input;
		input.push_back("drop");
        input.push_back(str);
        
        game.processCommand(input);
        
		paint();
	}
}

void adventureGUI::itemButtonClicked()
{

	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		//QString value = "you pick up this item: " + btn->text();
		//QMessageBox::information(0, "button clicked text", value);
		
		QString Str = btn->text();
		string str = Str.toStdString();
		
		vector <string> input;
		input.push_back("take");
        input.push_back(str);
        
        game.processCommand(input);
        
		paint();
	}
}

void adventureGUI::createDoorButtons()
{
    doorButtons = new QGroupBox(tr("Doors"));

	Playfield *p;
	p = Playfield::Instance();

    QVBoxLayout *doorButtonsLayout = new QVBoxLayout;
    
	vector <Door *>  doors = p->getPlayer()->getCurrentRoom()->getDoors();
	
	vector<Door* >::iterator iter;
	for (iter = doors.begin(); iter!=doors.end(); iter++) 
	{
		string s = (*iter)->getDescription();	
		QString naam = QString::fromUtf8(s.c_str());
		QPushButton * btn = new QPushButton(naam);
		doorButtonsLayout->addWidget(btn);

		connect(btn, SIGNAL(clicked()), this, SLOT(doorButtonClicked()));
	}
	doorButtons->setLayout(doorButtonsLayout);
}

void adventureGUI::createInventoryButtons()
{
    inventoryButtons = new QGroupBox(tr("Inventory"));

	Playfield *p;
	p = Playfield::Instance();

	inventoryButtons->setLayout(new QVBoxLayout);
    
	vector <Item *>  inventory = p->getPlayer()->getInventory();
	
	vector<Item* >::iterator iter;
	for (iter = inventory.begin(); iter!=inventory.end(); iter++) 
	{
		string s = (*iter)->getDescription();	
		QString naam = QString::fromUtf8(s.c_str());
		QPushButton * btn = new QPushButton(naam);

		connect(btn, SIGNAL(clicked()), this, SLOT(inventoryButtonClicked()));
		inventoryButtons->layout()->addWidget(btn);
	}
}

void adventureGUI::createItemButtons()
{
	itemButtons = new QGroupBox(tr("Items"));

	Playfield *p;
	p = Playfield::Instance();

    QVBoxLayout *itemButtonsLayout = new QVBoxLayout;
    
	vector <Item *>  items = p->getPlayer()->getCurrentRoom()->getItems();
	
	vector<Item* >::iterator iter;
	for (iter = items.begin(); iter!=items.end(); iter++) 
	{
		string s = (*iter)->getDescription();	
		QString naam = QString::fromUtf8(s.c_str());
		QPushButton * btn = new QPushButton(naam);

		connect(btn, SIGNAL(clicked()), this, SLOT(itemButtonClicked()));
		itemButtonsLayout->addWidget(btn);		
	}
	itemButtons->setLayout(itemButtonsLayout);
}

adventureGUI::~adventureGUI()
{
}
