#include "game-lib.h"


void Game::init(){
    GRRLIB_Init();
    WPAD_Init();
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
}

void Game::update_wiimote(){

        WPAD_SetVRes(0, 640, 480);
        WPAD_ScanPads();
        wpaddown = WPAD_ButtonsDown(0);
        wpadheld = WPAD_ButtonsHeld(0);


        WPAD_IR(WPAD_CHAN_0, &ir1);
}


bool Game::wiimote_pressed(ubyte button){
    if (wpaddown & button) return true;
    return false;
}

pos Rectangle::get_pos() {
    return position;
}

Rectangle::Rectangle(float x, float y, float h, float w, u32 _color, bool _filled){
    width = w;
    height = h;
    color = _color;
    filled = _filled;
    set_pos(x, y);
}

Rectangle::Rectangle(){;}


void Rectangle::set_pos(float x, float y){
    position.x = x;
    position.y = y;
}

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

void Rectangle::render(){
    GRRLIB_Rectangle(position.x, position.y, width, height, color, filled);
}

void Rectangle::move(float x, float y){
    position.x += x;
    position.y -= y;
}

ImageTexture::ImageTexture(const u8 * image){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
}

const GRRLIB_texImg * ImageTexture::get_img(){
    return texture;
}