#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GUI.hpp"
#include <vector>

class GameLogic
{
protected:
    std::vector<std::vector<int>> table;
    GUI gui;
public:
    GameLogic(GUI g);
    virtual bool isOK(int i, int j);

};

#endif // GAMELOGIC_H
