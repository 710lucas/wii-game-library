#include "game-lib.h"

// pos Rectangle::get_pos() {
//     return position;
// }

Rectangle::Rectangle(float x, float y, float h, float w, u32 _color, bool _filled){
    width = w;
    height = h;
    set_color(_color);
    set_filled(_filled);
    set_pos(x, y);
}

Rectangle::Rectangle(){;}


// void Rectangle::set_pos(float x, float y){
//     position.x = x;
//     position.y = y;
// }

float Rectangle::get_h(){ 
    return height;
}
float Rectangle::get_w() {
    return width;
}

void Rectangle::set_h(float h){
    height = h;
}

void Rectangle::set_w(float w){
    width = w;
}

// void Rectangle::set_color(u32 col){
//     color = col;
// }

void Rectangle::render(){
    GRRLIB_Rectangle(get_pos().x, get_pos().y, width, height, get_color(), get_filled());
}

// void Rectangle::move(float x, float y){
//     position.x += x;
//     position.y -= y;
// }

bool Rectangle::clicked(Game game){
    if(game.ir1.x > get_pos().x && game.ir1.x < get_pos().x+width && game.ir1.y > get_pos().y && game.ir1.y < get_pos().y+height && game.wiimote_pressed(WPAD_BUTTON_A))
        return true;
    return false;
}

bool Rectangle::is_colliding(Rectangle rec){
    pos rpos = rec.get_pos();
    float rw = rec.get_w();
    float rh = rec.get_h();
    pos p = get_pos();

    if (
        p.x < rpos.x+rw and
        p.x + width > rpos.x and
        p.y < rpos.y+rh and
        p.y + height > rpos.y
    )
        return true;

    
    // if( ((p.x >= rpos.x and p.x <= rpos.x+rec.get_w()) or 
    //     (p.x+width >= rpos.x and p.x+width <= rpos.x+rec.get_w() ) ) and
    //     ((p.y >= rpos.y and p.y <= rpos.y+rec.get_h())or
    //     (p.y+height >= rpos.y and p.y+height <= rpos.y+rec.get_h()))){
    //         return true;
    //     }
    return false;
}

bool Rectangle::side_collision(Rectangle rec){
    pos rpos = rec.get_pos();
    float rw = rec.get_w();
    float rh = rec.get_h();
    pos p = get_pos();

    if  ((p.x == rpos.x and
        rpos.y >= p.y and 
        rpos.y + rh <= p.y+height)
        or
        (p.x+width == rpos.x+rw and
        rpos.y >= p.y and 
        rpos.y + rh <= p.y+height
        )){
        return true;
    }
    return false;

}

Rectangle Image::get_rec(){ return rec; }