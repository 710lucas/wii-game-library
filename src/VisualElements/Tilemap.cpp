#include "Tilemap.h"
Tilemap::Tilemap(int* tilemap, Sprite sprite, intPair dimensions):sprite(NULL){
    int size = sizeof(tilemap)/sizeof(tilemap[0]);
    if(size > 640*480)
        return ;


    setScale(intPair{640/dimensions.x, 480/dimensions.y});
    setTilemap(tilemap, dimensions);
    this->sprite = sprite;


}

void Tilemap::setTilemap(int* tilemap, intPair dimensions){
    this->tilemap = std::vector<std::vector<int>>(dimensions.y, std::vector<int>(dimensions.x));
     
    int size = sizeof(tilemap)/sizeof(tilemap[0]);

    int j = 0;

    for(int i = 0; i<size; i++){
        if(i%4 == 0)
            j++;
        this->tilemap[i-(4*j)][j] = tilemap[i];
    }

}

void Tilemap::setSprite(Sprite sprite){
    this->sprite = sprite;
}

void Tilemap::setScale(intPair scale){
    this->scale = scale;
}

void Tilemap::draw(){
    std::vector<Sprite> sprites;
    for(int i = 0; i<this->tilemap.size(); i++){
        for(int j = 0; j<this->tilemap[i].size(); j++){
            if(j != 0){
                sprite.setFrame(j-1);
                sprite.setPosition(floatPair{static_cast<float>(i*scale.x), static_cast<float>(j*scale.y)});
                sprite.setScale(floatPair{static_cast<float>(scale.x), static_cast<float>(scale.y)});
                sprites.push_back(sprite);
            }

        }
    }
    for(Sprite sp : sprites)
        sp.draw();
}