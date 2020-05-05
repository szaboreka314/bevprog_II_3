#include "GameLogic.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

GameLogic::GameLogic(GUI g)
{
    gui = g;
    std::fstream input;
    input.open("input.csv");
    std::string line, s;
    char l;
    std::getline(input, line);
    std::stringstream ss, ssi;
    int d, m;
    ss << line;
    for(int i = 0; i < 9; ++i)
    {
        std::vector<int> aux;
        for(int j = 0; j < 9; ++j)
        {
           std::getline(ss,l, ';');
           ssi << s;
           ssi >> d;
           aux.push_back(d);
           std::cout << s << " ";
           d = s-'0';
           std::cout << d << " ";
           if(m == 1)
           {
               gui.setValue(i,j,d);
           }
        }
        table.push_back(aux);
    }
}

