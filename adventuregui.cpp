#include "adventuregui.h"
#include "Game.h"

#include <QtGui>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

using namespace std;

adventureGUI::adventureGUI(QWidget *parent)
    : QWidget(parent)
{

	// TODO: add pixmap van room
	// links buttons met move, pickup, drop...
	// soort van tekst terminal?
	
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
	
	createItemButtons();
	createDoorButtons();
	createInventoryButtons();
	    
    layout()->addWidget(itemButtons);
    layout()->addWidget(doorButtons);
    layout()->addWidget(inventoryButtons);
    
    Playfield *p;
	p = Playfield::Instance();
	
	
	
	string s = p->getPlayer()->getCurrentRoom()->getDescription();
	QString kamer = "You are in " + QString::fromUtf8(s.c_str());
	
    setWindowTitle(kamer);
}

void adventureGUI::doorButtonClicked()
{
	// TODO:
	// btn->text() (=QString) omzetten naar normal string 
	// getDoorByDescription (description = btn->text());
	// move oproepen op specifieke deur
	// redraw GUI
	
	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		QString value = "you walk through this door: " + btn->text();
		QMessageBox::information(0, "button clicked text", value);
				
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
	// TODO:
	// btn->text() (=QString) omzetten naar normal string 
	// getItemByDescription (description = btn->text());
	// terug droppen of zo?
	// redraw GUI
	
	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		QString value = "you drop this item: " + btn->text();
		QMessageBox::information(0, "button clicked text", value);
				
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
	// TODO:
	// btn->text() (=QString) omzetten naar normal string 
	// getItemByDescription (description = btn->text());
	// item in inventory steken
	// redraw GUI
	
	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		QString value = "you pick up this item: " + btn->text();
		QMessageBox::information(0, "button clicked text", value);
		
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
	
    /*QLabel *integerLabel = new QLabel(tr("Enter a value between "
        "%1 and %2:").arg(-20).arg(20));
    QSpinBox *integerSpinBox = new QSpinBox;
    integerSpinBox->setRange(-20, 20);
    integerSpinBox->setSingleStep(1);
    integerSpinBox->setValue(0);

    QLabel *zoomLabel = new QLabel(tr("Enter a zoom value between "
        "%1 and %2:").arg(0).arg(1000));
    QSpinBox *zoomSpinBox = new QSpinBox;
    zoomSpinBox->setRange(0, 1000);
    zoomSpinBox->setSingleStep(10);
    zoomSpinBox->setSuffix("%");
    zoomSpinBox->setSpecialValueText(tr("Automatic"));
    zoomSpinBox->setValue(100);

    QLabel *priceLabel = new QLabel(tr("Enter a price between "
        "%1 and %2:").arg(0).arg(999));
    QSpinBox *priceSpinBox = new QSpinBox;
    priceSpinBox->setRange(0, 999);
    priceSpinBox->setSingleStep(1);
    priceSpinBox->setPrefix("$");Deuren
    priceSpinBox->setValue(99);

    QVBoxLayout *spinBoxLayout = new QVBoxLayout;
    spinBoxLayout->addWidget(integerLabel);
    spinBoxLayout->addWidget(integerSpinBox);
    spinBoxLayout->addWidget(zoomLabel);
    spinBoxLayout->addWidget(zoomSpinBox);
    spinBoxLayout->addWidget(priceLabel);
    spinBoxLayout->addWidget(priceSpinBox);
    spinBoxesGroup->setLayout(spinBoxLayout);*/
}


adventureGUI::~adventureGUI()
{

}
