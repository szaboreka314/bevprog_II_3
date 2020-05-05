#ifndef WIDGET_H
#define WIDGET_H

#include "graphics.hpp"

class Widget
{
protected:
    int posx,posy,sx,sy;
    bool in_focus;
public:
    Widget(int x, int y, int w, int h);
    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
    virtual bool get_focus();
    virtual void set_focus(bool f);
};

#endif // WIDGET_H
