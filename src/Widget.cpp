#include "widget.hpp"
#include "graphics.hpp"

Widget::Widget(int x, int y, int w, int h) : posx(x), posy(y), sx(w), sy(h)
{
    in_focus = false;
}

bool Widget::is_selected(int mx, int my)
{
    return (posx <= mx && mx <= posx+sx && posy <= my && my <= posy+sy);
}

bool Widget::get_focus()
{
    return in_focus;
}

void Widget::set_focus(bool f)
{
    in_focus = f;
}
