#ifndef ADVENTUREGUI_H
#define ADVENTUREGUI_H

#include <QtGui/QWidget>
#include "ui_adventuregui.h"
#include "Game.h"

class QGroupBox;

class adventureGUI : public QWidget
{
    Q_OBJECT

public:
    adventureGUI(QWidget *parent = 0);
    ~adventureGUI();
 	Game game;
	

private:
    Ui::adventureGUIClass ui;
    void createItemButtons();
    void createDoorButtons();
    void createInventoryButtons();
    void paint();
    
    QGroupBox *itemButtons;
    QGroupBox *doorButtons;
    QGroupBox *inventoryButtons;
    
    
private slots:
   void doorButtonClicked();
   void inventoryButtonClicked();
   void itemButtonClicked();
};

#endif // ADVENTUREGUI_H
