#include "game-lib.h"

Button::Button(std::string lab, int x, int y, u32 color){
    label = lab;
    set_pos(x, y);
    set_color(color);
}

std::string Button::get_label(){
    return label;
}

std::string Button::get_alignment(){
    return alignment;
}

std::string Button::get_text_alignment(){
    return text_align;
}

void Button::set_label(std::string lab){
    label = lab;
}

void Button::set_alignment(std::string al){
    alignment = al;
}

void Button::set_text_alignment(std::string al){
    text_align = al;
}

void Button::render_button(){
    render();
    //renderizar texto 
}