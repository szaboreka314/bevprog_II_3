#include "StaticText.hpp"
#include "graphics.hpp"

using namespace genv;

StaticText::StaticText(int x, int y, int h, int w, std::string t):Widget(x,y,h,w)
{
    stext = t;
    draw();
}

void StaticText::draw() const
{
    gout << move_to(posx, posy) << color(255,255,255) << text(stext);
}

void StaticText::handle(genv::event ev)
{

}

void StaticText::set_text(std::string t)
{
    stext = t;
    draw();
}
