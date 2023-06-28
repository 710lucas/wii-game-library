#pragma once
#include <grrlib.h>
#include "misc.h"

class Text{

    public:
        Text(const u8* fileName, s32 fileSize);
        Text(const u8* fileName, s32 fileSize, const char* text, floatPair position);
        Text(const u8* fileName, s32 fileSize, const char* text, floatPair position, int fontSize);
        Text(const u8* fileName, s32 fileSize, const char* text, floatPair position, int fontSize, u32 color);
        void print(const char* str);
        void print();
        void print(const char* str, float x, float y, int fontSize, u32 color);
        void print(const char* str, floatPair position, int fontSize, u32 color);
        void print(float x, float y, int fontSize, u32 color);
        void print(floatPair position, int fontSize, u32 color);

        void setText(const char* text);
        void setPosition(floatPair position);
        void setPosition(float x, float y);
        void setFontSize(int fontSize);
        void setColor(u32 color);

        const char* getText();
        floatPair getPosition();
        int getFontSize();
        u32 getColor();


    private:
        const char* text;
        floatPair position;
        int fontSize;
        u32 color;
        GRRLIB_ttfFont font;


};