#include "Text.h"

Text::Text(const u8* fileName, s32 fileSize){
    font = *GRRLIB_LoadTTF(fileName, fileSize);
}

Text::Text(const u8* fileName, s32 fileSize, const char* text, floatPair position) : Text(fileName, fileSize){
    this->text = text;
    this->position = position;
}
Text::Text(const u8* fileName, s32 fileSize, const char* text, floatPair position, int fontSize) : Text(fileName, fileSize, text, position){
    this->fontSize = fontSize;
}
Text::Text(const u8* fileName, s32 fileSize, const char* text, floatPair position, int fontSize, u32 color) : Text(fileName, fileSize, text, position,fontSize){
    this->color = color;
}

void Text::print(const char* str){
    GRRLIB_PrintfTTF(position.x, position.y, &font, str, fontSize, color);
}

void Text::print(){
    print(text);
}

void Text::print(const char* str, float x, float y, int fontSize, u32 color){
    GRRLIB_PrintfTTF(x,y,&font,str,fontSize,color);
}

void Text::print(const char* str, floatPair position, int fontSize, u32 color){
    print(str, position.x, position.y, fontSize, color);
}

void Text::print(float x, float y, int fontSize, u32 color){
    GRRLIB_PrintfTTF(x,y,&font,text,fontSize,color);
}

void Text::print(floatPair position, int fontSize, u32 color){
    print(position.x, position.y, fontSize, color);
}

void Text::setText(const char* text){
    this->text = text;
}

void Text::setPosition(floatPair position){
    this->position = position;
}

void Text::setPosition(float x, float y){
    setPosition(floatPair{x,y});
}

void Text::setFontSize(int fontSize){
    this->fontSize = fontSize;
}

void Text::setColor(u32 color){
    this->color = color;
}

const char* Text::getText(){return text;}
floatPair Text::getPosition(){return position;}
int Text::getFontSize(){return fontSize;}
u32 Text::getColor(){return color;}

