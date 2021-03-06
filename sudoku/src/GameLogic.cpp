#include "GameLogic.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace genv;

GameLogic::GameLogic()
{
    OK = 0;
    gout.open(800,600);
    int num, rnd;
    std::string line, coma;
    std::stringstream ss;
    std::fstream input;
    input.open("input.csv");
    std::getline(input, line);
    ss << line;
    ss >> num;
    srand (time(NULL));
    rnd = rand() % num;
    for(int i = 0; i < rnd; ++i)
        std::getline(input,line);
    std::getline(input, line);
    std::stringstream ss2;
    ss2 << line;
    int x = 10;
    int y = 10;
    for(int i = 0; i < 9; ++i)
    {
        x = 10;
        for(int j = 0; j < 9; ++j)
        {
            getline(ss2, coma, ';');
            std::stringstream conv;
            conv << coma;
            int value;
            conv>> value;
            NumericUpDown *nup = new NumericUpDown(x, y, 30, 30, 0, 9, i*9+j);
            if(value != 0)
            {
                nup->set_static();
                nup->set_value(value);
                ++OK;
            }
            widgets.push_back(nup);

            x += 50;
            if(j == 2 || j == 5)
                x += 10;
        }

        if(i == 2 || i == 5)
            y += 10;
        y += 50;
    }
    StaticText *st = new StaticText(600,50,0,0,"Sudoku");
    StaticText *st2 = new StaticText(480, 100, 0, 0, "The objective is to fill the 9x9 grid");
    StaticText *st3 = new StaticText(480, 130, 0,0,"with digits so that each column, each ");
    StaticText *st4 = new StaticText(480, 160, 0,0,"row and each of the nine 3x3 grid");
    StaticText *st5 = new StaticText(480, 190, 0,0,"contain all of the digits from 1 to 9.");
    StaticText *st6 = new StaticText(480, 220, 0,0,"You did well, if there's no red digit!");
    widget_handler();
}

void GameLogic::start()
{
    for(Widget* w:widgets)
    {
        w->draw();
    }
    gout << refresh;
    widget_handler();
}

void GameLogic::widget_handler()
{
     event ev;
   while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_mouse && ev.button == btn_left) ///belekattintok, kiv�lasztja
        {
            for(NumericUpDown* w:widgets)
            {
                if(w->is_selected(ev.pos_x, ev.pos_y))
                {
                    w->set_focus(true);

                }
                else
                {
                    w->set_focus(false);

                }
            }
        }
        if(ev.type == ev_key && ev.keycode == key_tab)
        {
            for(size_t i =0; i<widgets.size(); ++i)
            {
                if(widgets[i]->get_focus())
                {
                    widgets[i]->set_focus(false);
                    int next = (i+1)%widgets.size();
                    widgets[next]->set_focus(true);
                    break;
                }
            }
        }
        for(NumericUpDown* w:widgets)
        {
            if(w->get_focus())
            {
                w->handle(ev);

                if(w->get_value() != 0 && !is_OK(w->get_id()/9, w->get_id()%9))
                    {
                        w->set_wrong(true);
                        w->set_focus(false);
                    }
                    else
                    {
                        w->set_wrong(false);
                        w->set_focus(false);
                    }

            }
            w->draw();
        }
        gout << refresh;
    }

}


bool GameLogic::is_OK(int i, int j)
{
    int actValue = widgets[i*9+j]->get_value();
    //std::cout << actValue << " ";
    for(int k = 0; k < 9; ++k)
    {
        if(k != i && widgets[k*9+j]->get_value() == actValue) /// vele egy oszlopban l�v�k
            return false;
        if(k != j && widgets[i*9+k]->get_value() == actValue) ///vele egy sorban l�v�k
           return false;
    }
    ///3x3-as n�gyzetek ellen�rz�se, hogy nincs e �tk�z�s
    if( i >= 0 && i <= 2)
    {
        if(j >= 0 && j <= 2)
        {
            for(int k = 0; k < 3; ++k)
                for(int l = 0; l < 3; ++l)
                    if(k != i && l != j && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }
        else if(j >= 3 && j <= 5)
        {
            for(int k = 0; k < 3; ++k)
                for(int l = 3; l < 6; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }
        else if(j >= 6 && j <= 8)
        {
            for(int k = 0; k < 3; ++k)
                for(int l = 6; l < 9; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }

    }
    else if( i >= 3 && i <= 5)
    {
        if(j >= 0 && j <= 2)
        {
            for(int k = 3; k < 6; ++k)
                for(int l = 0; l < 3; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }
        else if(j >= 3 && j <= 5)
        {
            for(int k = 3; k < 6; ++k)
                for(int l = 3; l < 6; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }
        else if(j >= 6 && j <= 8)
        {
            for(int k = 3; k < 6; ++k)
                for(int l = 6; l < 9; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }

    }
    else if( i >= 6 && i <= 8)
    {
        if(j >= 0 && j <= 2)
        {
            for(int k = 6; k < 9; ++k)
                for(int l = 0; l < 3; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }
        else if(j >= 3 && j <= 5)
        {
            for(int k = 6; k < 9; ++k)
                for(int l = 3; l < 6; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }
        else if(j >= 6 && j <= 8)
        {
            for(int k = 6; k < 9; ++k)
                for(int l = 6; l < 9; ++l)
                    if(i != k && j != l && widgets[k*9+l]->get_value() == actValue)
                        return false;
        }

    }
    return true;

}
