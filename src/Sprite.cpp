#include "Sprite.h"


Sprite::Sprite(const u8 * image) : Image(image){

}

Sprite::Sprite(const u8 * image, u32 tileWidth, u32 tileHeight) : Sprite(image){
    setTileSize(tileWidth, tileHeight);
}

Sprite::Sprite(const u8 * image, u32Pair tileSize) : Sprite(image, tileSize.x, tileSize.y){
    ;
}

Sprite::Sprite(const u8 * image, u32Pair tileSize, floatPair position, floatPair scale, float rotation, u32 color) : Image(image, position, scale, rotation, color){
    setTileSize(tileSize);
}

void Sprite::setTileSize(u32Pair tileSize){
    this->tileSize = tileSize;
}

void Sprite::setTileSize(u32 tileW, u32 tileH){
    setTileSize(u32Pair{tileW, tileH});
}

void Sprite::setFrame(int frame){
    this->frame = frame;
}

void Sprite::draw(){
    GRRLIB_DrawTile(getPosition().x, getPosition().y,
    &getTexture(), getRotation(), getScale().x, getScale().y,
    getColor(), getFrame());
}

u32Pair Sprite::getTileSize(){return tileSize;}
int Sprite::getFrame(){return frame;}

