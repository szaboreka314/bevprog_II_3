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

};

#endif // GAMELOGIC_H
