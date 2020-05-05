#ifndef NUMERICUPDOWN_H
#define NUMERICUPDOWN_H

#include "widget.hpp"

class NumericUpDown: public Widget
{
protected:
    int value, min_val, max_val, w_id;
    double updown_size;
    bool up,down;
public:
    NumericUpDown(int x, int y, int w, int h, int minv, int maxv);
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
    virtual bool is_selected(int mx, int my) override;
    virtual int get_value();
    virtual void set_value(int v);
};

#endif // NUMERICUPDOWN_H
