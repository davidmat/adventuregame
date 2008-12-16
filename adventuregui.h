#ifndef ADVENTUREGUI_H
#define ADVENTUREGUI_H

#include <QtGui/QMainWindow>
#include "ui_adventuregui.h"

class adventureGUI : public QMainWindow
{
    Q_OBJECT

public:
    adventureGUI(QWidget *parent = 0);
    ~adventureGUI();

private:
    Ui::adventureGUIClass ui;
};

#endif // ADVENTUREGUI_H
