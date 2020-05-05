#include "GameLogic.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

GameLogic::GameLogic(GUI g)
{
    gui = g;
    std::fstream input;
    input.open("input.csv");
    std::string line, s, mask;
    std::getline(input, line);
    std::getline(input, mask);
    std::stringstream ss, ss2, ssi;
    int d, m;
    ss << line;
    ss2 << mask;
    for(int i = 0; i < 9; ++i)
    {
        std::vector<int> aux;
        for(int j = 0; j < 9; ++j)
        {
           std::getline(ss,s, ';');
           ssi << s;
           ssi >> d;
           std::getline(ss2,s, ';');
           ssi << s;
           ssi >> m;
           aux.push_back(d);
           std::cout << d << " ";
           if(m == 1)
           {
               gui.setValue(i,j,d);
           }
        }
        table.push_back(aux);
    }
}

