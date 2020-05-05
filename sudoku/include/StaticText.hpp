#ifndef STATICTEXT_H
#define STATICTEXT_H

#include "widget.hpp"

class StaticText : public Widget {
protected:
    std::string stext;
public:
    StaticText(int x, int y, int w, int h, std::string t);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void set_text(std::string t);
    virtual std::string get_value(){return "";};
};

#endif // STATICTEXT_H
