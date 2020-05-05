#include "NumericUpDown.hpp"
#include "graphics.hpp"

#include <sstream>

using namespace genv;

NumericUpDown::NumericUpDown(int x, int y, int w, int h, int minv, int maxv):Widget(x,y,w,h)
{
    static int ID = 0;
    w_id = ID;
    ++ID;
    value = min_val = minv;
    max_val = maxv;
    updown_size = w*0.4; ///a növelõ terület mérete
}

bool NumericUpDown::is_selected(int mx, int my)
{
    if(posx+sx <= mx && mx <= posx+sx+updown_size && posy <= my && my <= posy+sy/2)
        up = true;
    if(posx+sx <= mx && mx <= posx+sx+updown_size && posy+sy/2 <= my && my <= posy+sy)
        down = true;
    return (posx <= mx && mx <= posx+sx+updown_size && posy <= my && my <= posy+sy);
}

void NumericUpDown::draw() const
{
    gout << move_to(posx, posy) << color(255,255,255) << box(sx,sy);
    gout << move_to(posx+sx,posy) << color(150,150,150) << box(updown_size, sy);
    gout << move_to(posx+sx, posy+(sy/2)) << color(0,0,0) << line_to(posx+sx+updown_size, posy+(sy/2));
    gout << move_to(posx+sx+updown_size/2,posy+(sy/2*0.1)) << line_to(posx+sx+updown_size*0.8,posy+(0.8*sy/2)) << line_to(posx+sx+updown_size*0.2,posy+(0.8*sy/2)) << line_to(posx+sx+updown_size/2,posy+(sy/2*0.1));
    gout << move_to(posx+sx+updown_size*0.2,posy+sy/2+(sy/2*0.2)) << line_to(posx+sx+updown_size*0.8,posy+sy/2+(0.2*sy/2)) << line_to(posx+sx+updown_size/2,posy+sy/2+(sy/2*0.8)) << line_to(posx+sx+updown_size*0.2,posy+sy/2+(sy/2*0.2));
    std::stringstream ss;
    ss << value;
    int px =(sx-gout.twidth(ss.str()))/2;
    int py = sy-gout.cascent();
    gout << move_to(posx+px, posy+py) << color(0,0,0) << text(ss.str());
}

void NumericUpDown::handle(genv::event ev)
{
    if(up || (in_focus && ev.keycode == key_up))
    {
        ++value;
        if(value > max_val)
            value = max_val;
        up = false;
    }
    if(in_focus && ev.keycode == key_pgup)
    {
        value += 10;
        if(value > max_val)
            value = max_val;
    }
    if(down || (in_focus && ev.keycode == key_down))
    {
        --value;
        if(value < min_val)
            value = min_val;
        down = false;
    }
    if(in_focus && ev.keycode == key_pgdn)
    {
        value -= 10;
        if(value < min_val)
            value = min_val;
    }
}

int NumericUpDown::get_value()
{
    return value;
}

void NumericUpDown::set_value(int v)
{
    value = v;
    draw();
}

