#ifndef NUMERICUPDOWN_H
#define NUMERICUPDOWN_H

#include "widget.hpp"

class NumericUpDown: public Widget
{
protected:
    int value, min_val, max_val, w_id;
    double updown_size;
    bool up,down, isStatic, isWrong;
public:
    NumericUpDown(int x, int y, int w, int h, int minv, int maxv, int id);
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
    virtual bool is_selected(int mx, int my) override;
    virtual int get_value();
    virtual void set_value(int v);
    virtual void set_static();
    virtual void set_wrong(bool w);
    virtual int get_id();
};

#endif // NUMERICUPDOWN_H
