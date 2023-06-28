#pragma once

#include "Image.h"

class Sprite : public Image{


    public:
        Sprite(Sprite* sp);
        Sprite(const u8 * image);
        Sprite(const u8 * image, u32 tileWidth, u32 tileHeight);
        Sprite(const u8 * image, u32Pair tileSize);
        Sprite(const u8 * image, u32Pair tileSize, floatPair position, floatPair scale, float rotation, u32 color);

        void setTileSize(u32Pair tileSize);
        void setTileSize(u32 tileW, u32 tileH);
        void setFrame(int frame);
        void nextFrame();
        void draw();

        u32Pair getTileSize();
        int getFrame();

    
    private:
        u32Pair tileSize;
        int frame;


};