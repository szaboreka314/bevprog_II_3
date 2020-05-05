#include "GameLogic.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

GameLogic::GameLogic(GUI g)
{
    gui = g;
    std::fstream input;
    input.open("input.csv");
    std::string line, coma;
    std::stringstream ss;
    std::getline(input, line);
    ss << line;
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            getline(ss, coma, ';');
            std::stringstream conv;
            conv << coma;
            int value;
            conv>> value;
            if(value != 0)
            {
                gui.setStatic(i,j);
                gui.setValue(i,j,value);
            }

        }
    }
}

bool GameLogic::isOK(int i, int j)
{
    int actValue = gui.getValue(i,j);
    for(int k = 0; k < 9; ++k)
    {
        if(k != i && gui.getValue(k,j) == actValue) /// vele egy oszlopban lévõk
            return false;
        if(k != j && gui.getValue(i,k) == actValue) ///vele egy sorban lévõk
            return false;
    }
}
