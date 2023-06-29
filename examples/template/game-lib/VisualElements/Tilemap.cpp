#include "Tilemap.h"
#include <cstdio>
Tilemap::Tilemap(std::vector<std::vector<int>> tilemap, Sprite sprite):sprite(sprite){

    setTilemap(tilemap);
    this->sprite = sprite;
    initTilemap();

}

void Tilemap::setTilemap(std::vector<std::vector<int>> tilemap){
    this->tilemap = tilemap;
}

void Tilemap::setSprite(Sprite sprite){
    this->sprite = sprite;
}

void Tilemap::setScale(intPair scale){
    this->scale = scale;
}

void Tilemap::initTilemap(){
    intPair dimensions = {tilemap[0].size(), tilemap.size()};
    for(int i = 0; i<dimensions.y; i++){
        for(int j = 0; j<dimensions.x; j++){
            if(tilemap[i][j] == 0)
                continue;
            
            Sprite sp(sprite);
            GRRLIB_texImg texture = *sp.getTexture();
            floatPair relativeScale = {640/dimensions.x, 480/dimensions.y};
            floatPair scale = {relativeScale.x/sprite.getTileSize().x, relativeScale.y/sprite.getTileSize().y};
            floatPair position = {j*relativeScale.x, i*relativeScale.y};
            sp.setScale(scale);
            sp.setColor(0xffffffff);
            sp.setPosition(position);
            sp.setFrame(tilemap[i][j]-1);
            sprites.push_back(sp);
        }
    }
}

void Tilemap::draw(){
    for(Sprite sp : sprites)
        sp.draw();
}


bool Tilemap::isColiding(Rectangle rectangle){
    for(Sprite sp : sprites) {
        if(sp.getHitbox().isColidingWith(rectangle))
            return true;
    }
    return false;
}


bool Tilemap::isColiding(Image image){
    return isColiding(image.getHitbox());
}

bool Tilemap::isColiding(Sprite sprite){
    return isColiding(sprite.getHitbox());
}


std::vector<std::vector<int>> Tilemap::getTilemap(){return tilemap;}
Sprite Tilemap::getSprite(){return sprite;}
intPair Tilemap::getScale(){return scale;}
std::vector<Sprite> Tilemap::getSprites(){return sprites;}

