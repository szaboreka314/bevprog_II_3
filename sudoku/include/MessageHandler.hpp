#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "GUI.hpp"
#include "GameLogic.hpp"

class GUI;
class GameLogic;
class MessageHandler
{
protected:
    GUI *gui;
    GameLogic gameLogic;
public:
    MessageHandler(GUI g, GameLogic gl);
    virtual void setValue(int i, int j,int v);
    virtual int getValue(int i, int j);
    virtual void setStatic(int i, int j);
    virtual bool isWrong(int i, int j);
};

#endif // MESSAGEHANDLER_H
