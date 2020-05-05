#include "GameLogic.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace genv;

GameLogic::GameLogic()
{
    gout.open(800,600);
    std::fstream input;
    input.open("input.csv");
    std::string line, coma;
    std::stringstream ss;
    std::getline(input, line);
    ss << line;
    int x = 10;
    int y = 10;
    for(int i = 0; i < 9; ++i)
    {
        x = 10;
        for(int j = 0; j < 9; ++j)
        {
            getline(ss, coma, ';');
            std::stringstream conv;
            conv << coma;
            int value;
            conv>> value;
            NumericUpDown *nup = new NumericUpDown(x, y, 30, 30, 0, 9, i*9+j);
            if(value != 0)
            {
                nup->set_value(value);
                nup->set_static();
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
        if(ev.type == ev_mouse && ev.button == btn_left) ///belekattintok, kiválasztja
        {
            for(NumericUpDown* w:widgets)
            {
                if(w->is_selected(ev.pos_x, ev.pos_y))
                {
                    w->set_focus(true);
                    if(!is_OK(w->get_id()/9, w->get_id()%9))
                    {
                        w->set_wrong(true);
                    }
                    else
                    {
                        w->set_wrong(false);
                    }
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
        for(Widget* w:widgets)
        {
            if(w->get_focus())
                w->handle(ev);
            w->draw();
        }
        gout << refresh;
    }
}


bool GameLogic::is_OK(int i, int j)
{
    int actValue = widgets[i*9+j]->get_value()+1;
    std::cout << actValue << " ";
    for(int k = 0; k < 9; ++k)
    {
        if(k != i && widgets[k*9+j]->get_value() == actValue) /// vele egy oszlopban lévõk
            return false;
        if(k != j && widgets[i*9+k]->get_value() == actValue) ///vele egy sorban lévõk
           return false;
    }
    ///3x3-as négyzetek ellenõrzése, hogy nincs e ütközés
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
