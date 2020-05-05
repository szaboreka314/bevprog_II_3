#include "GUI.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include "StaticText.hpp"
#include "NumericUpDown.hpp"

#include <iostream>

using namespace genv;
GUI::GUI()
{
    gout.open(800,600);
    int x = 10;
    int y = 10;
    for(int i = 0; i < 9; ++i)
    {
        x = 10;
        for(int j = 0; j < 9; ++j)
        {
            NumericUpDown *nup = new NumericUpDown(x, y, 30, 30, 0, 9);
            widgets.push_back(nup);
            x += 50;
            if(j == 2 || j == 5)
                x += 10;
        }
        if(i == 2 || i == 5)
            y += 10;
        y += 50;
    }
}

void GUI::start()
{
    for(Widget* w:widgets)
    {
        w->draw();
    }
    gout << refresh;
    widget_handler();
}

void GUI::widget_handler()
{
    event ev;

    while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_mouse && ev.button == btn_left) ///belekattintok, kiválasztja
        {
            for(Widget* w:widgets)
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
        for(Widget* w:widgets)
        {
            if(w->get_focus())
                w->handle(ev);
            w->draw();
        }
        gout << refresh;
    }
}

int GUI::getValue(int i, int j)
{
    return widgets[i*9+j]->get_value();
}

void GUI::setValue(int i, int j, int v)
{
    widgets[i*9+j]->set_value(v);
}
