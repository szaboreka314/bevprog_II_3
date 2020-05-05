#include "MessageHandler.hpp"

MessageHandler::MessageHandler(GUI g, GameLogic gl)
{
    gui = g;
    gameLogic = gl;
}

void MessageHandler::setValue(int i, int j, int v)
{
    gui.setValue(i,j,v);
}

int MessageHandler::getValue(int i, int j)
{
    return gui.getValue(i,j);
}

void MessageHandler::setStatic(int i, int j)
{
    gui.setStatic(i,j);
}

bool MessageHandler::isWrong(int i, int j)
{
    return gameLogic.is_OK(i,j);
}
