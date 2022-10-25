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

void Rectangle::set_color(u32 col){
    color = col;
}

void Rectangle::render(){
    GRRLIB_Rectangle(position.x, position.y, width, height, color, filled);
}

void Rectangle::move(float x, float y){
    position.x += x;
    position.y -= y;
}

bool Rectangle::clicked(Game game){
    if(game.ir1.x > position.x && game.ir1.x < position.x+width && game.ir1.y > position.y && game.ir1.y < position.y+height && game.wiimote_pressed(WPAD_BUTTON_A))
        return true;
    return false;
}

Image::Image(const u8 * image){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
}

Image::Image(const u8 * image, float px, float py){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
    position.x = px;
    position.y = py;
}

Image::Image(const u8 * image, float px, float py, float sx, float sy, float _rotation, u32 _color){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
    rotation = _rotation;
    position.x = px;
    position.y = py;
    scale.x = sx;
    scale.y = sy;
    color = _color;
}

void Image::set_pos(float px, float py){
    position.x = px;
    position.y = py;
}
void Image::set_scale(float sx, float sy){
    scale.x = sx;
    scale.y = sy;
}
void Image::set_rotation(float rot){
    rotation = rot;
}
void Image::set_color(u32 col){
    color = col;
}

void Image::move(float x, float y){
    position.x += x;
    position.y -= y;
}

pos Image::get_pos(){ 
    return position;
    }
pos Image::get_scale(){ 
    return scale;
    }
float Image::get_rotation(){ 
    return rotation;
    }

const GRRLIB_texImg * Image::get_img(){
    return texture;
}

void Image::render(){
    GRRLIB_DrawImg(position.x, position.y, texture, rotation, scale.x, scale.y, color);
}
void Image::render(float px, float py){
    GRRLIB_DrawImg(px, py, texture, rotation, scale.x, scale.y, color);
}