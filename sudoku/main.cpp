#include "GameLogic.hpp"

#include <vector>
#include <iostream>
#include <fstream>

using namespace genv;

/*void widget_handler(std::vector<Widget*> &widgets)
{
    event ev;

    while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_key && ev.keycode == key_enter)
        {
            std::ofstream output("results.txt");
            for(Widget *w: widgets)
            {
                output << w->get_value();
            }
            output.close();
        }
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
}*/

int main()
{
    /*gout.open(800,600);
    gout << move_to(0,0) << color(50,50,50) << box(800,600);
    std::vector<Widget*> widgets;

    StaticText *st1 = new StaticText(70,20,0,0,"Push enter to save values in a file!");

    NumericUpDown *nup = new NumericUpDown(70,160,30,30,0,9);

    widgets.push_back(nup);

    for(Widget* w:widgets)
    {
        w->draw();
    }
    gout << refresh;
    widget_handler(widgets);*/

    GameLogic gameLogic;
    gameLogic.start();
    return 0;
}
