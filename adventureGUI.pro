TEMPLATE = app
TARGET = adventureGUI
QT += core \
    gui
HEADERS += Door.h \
    Game.h \
    GameObject.h \
    Item.h \
    OutputHandler.h \
    Parser.h \
    Player.h \
    Playfield.h \
    Room.h \
    adventuregui.h
SOURCES += Door.cpp \
    Game.cpp \
    GameObject.cpp \
    Item.cpp \
    OutputHandler.cpp \
    Parser.cpp \
    Player.cpp \
    Playfield.cpp \
    Room.cpp \
    main.cpp \
    adventuregui.cpp
FORMS += adventuregui.ui
RESOURCES += 
