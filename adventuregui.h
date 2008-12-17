#ifndef ADVENTUREGUI_H
#define ADVENTUREGUI_H

#include <QtGui/QWidget>
#include "ui_adventuregui.h"

class adventureGUI : public QWidget
{
    Q_OBJECT

public:
    adventureGUI(QWidget *parent = 0);
    ~adventureGUI();

private:
    Ui::adventureGUIClass ui;
    
private slots:
   void buttonClicked();
};

#endif // ADVENTUREGUI_H
