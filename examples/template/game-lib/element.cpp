#include "game-lib.h"

pos Element::get_pos() { return position; }
u32 Element::get_color() { return color; }
bool Element::get_filled() {return filled; }

void Element::set_pos(int x, int y){
    position.x = x;
    position.y = y;
}

void Element::set_color(u32 col){
    color = col;
}

void Element::set_filled(bool fil){
    filled =fil;
}

void Element::move(int x, int y){
    position.x += x;
    position.y -= y;
}