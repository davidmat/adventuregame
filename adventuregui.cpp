#include "adventuregui.h"
#include "Game.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

using namespace std;

adventureGUI::adventureGUI(QWidget *parent)
    : QWidget(parent)
{
	//ui.setupUi(this);
	setLayout(new QHBoxLayout());
	
	Playfield *p;
	p = Playfield::Instance();
	
	vector <Door *>  doors = p->getPlayer()->getCurrentRoom()->getDoors();
	
	vector<Door* >::iterator iter;
	for (iter = doors.begin(); iter!=doors.end(); iter++) 
	{
		string s = (*iter)->getDescription();	
		QString naam = "deur: " + QString::fromUtf8(s.c_str());
		QPushButton * btn = new QPushButton(naam, this);

		connect(btn, SIGNAL(clicked()), this, SLOT(buttonClicked()));
		layout()->addWidget(btn);
	}
}

void adventureGUI::buttonClicked()
{
	QPushButton * btn = qobject_cast<QPushButton *>(QObject::sender());

	if(btn != 0)
	{
		QString value = "this deur has been pressed: " + btn->text();
		QMessageBox::information(0, "button clicked text", value);
	}
}

adventureGUI::~adventureGUI()
{

}
