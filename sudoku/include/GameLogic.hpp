#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "NumericUpDown.hpp"
#include "StaticText.hpp"
#include <vector>

class GameLogic
{
protected:
    std::vector<NumericUpDown*> widgets;
public:
    GameLogic();
    virtual void start();
    virtual bool is_OK(int i, int j);
    virtual void widget_handler();
};

#endif // GAMELOGIC_H
