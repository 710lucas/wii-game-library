#include "game-lib.h"

Circle::Circle(int x, int y, f32 rad, u32 _color, bool _filled){
    set_pos(x, y);
    set_color(_color);
    set_filled(_filled);
    radius = rad;
}


void Circle::render(){
    GRRLIB_Circle(get_pos().x, get_pos().y, radius, get_color(), get_filled());
}