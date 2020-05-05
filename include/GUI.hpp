#ifndef GUI_H
#define GUI_H

#include "NumericUpDown.hpp"
#include <vector>

class GUI
{
protected:
    std::vector<NumericUpDown*> widgets;
public:
    GUI();
    virtual void start();
    virtual void widget_handler();
    virtual int getValue(int i, int j);
    virtual void setValue(int i, int j, int v);
};

#endif // GUI_H
