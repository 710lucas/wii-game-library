#include "game-lib.h"



Text::Text(const u8* file_base, s32 file_size){
    fonte = GRRLIB_LoadTTF(file_base, file_size);
    position.x = 0;
    position.y = 0;
    font_size = 24;
    color = 0xffffffff;
    content = "";
}

void Text::print(const char* str){
    GRRLIB_PrintfTTF(position.x, position.y, fonte, str, font_size, color);
}
void Text::print(){
    GRRLIB_PrintfTTF(position.x, position.y, fonte, content, font_size, color);
}
void Text::print(const char* str, int x, int y, int f_size, u32 col){
    GRRLIB_PrintfTTF(x, y, fonte, str, f_size, col);
}

void Text::print(int x, int y, int f_size, u32 col){
    GRRLIB_PrintfTTF(x, y, fonte, content, f_size, col);
}
void Text::print(const char* str, int x, int y){
    GRRLIB_PrintfTTF(x, y, fonte, str, font_size, color);
}

void Text::set_content(const char* inp){
    content = inp;
}

void Text::set_pos(int x, int y){
    position.x = x; position.y = y;
}

void Text::set_font_size(int f_size){
    font_size = f_size;
}

void Text::set_color(u32 col){
    color = col;
}

const char* Text::get_content(){
    return content;
}

pos Text::get_pos(){
    return position;
}

int Text::get_font_size(){
    return font_size;
}

u32 Text::get_color(){
    return color;
}