#include "Image.h"

Image::Image(const u8 * image){

    texture = GRRLIB_LoadTexture(image);
    hitbox.setSize(texture->w, texture->h);

}

Image::Image(const u8 * image, float px, float py) : Image(image){

    setPosition(floatPair{px, py});

}

Image::Image(const u8 * image, float px, float py, float scaleX, float scaleY, float rotation, u32 color) : Image(image, px, py){
        
    setScale(scaleX, scaleY);
    setRotation(rotation);
    setColor(color);

}


Image::Image(const u8 * image, floatPair position, floatPair scale, float rotation, u32 color) : Image(image, position.x, position.y, scale.x, scale.y, rotation, color){
 ;   
}

void Image::draw(){
    GRRLIB_DrawImg(getPosition().x, getPosition().y, texture, getRotation(), getScale().x, getScale().y, getColor());
}

void Image::setTexture(GRRLIB_texImg &texture){
    this->texture = &texture;
}

void Image::setScale(floatPair scale){
    hitbox.setSize(hitbox.getSize().w*scale.x, hitbox.getSize().h*scale.y);
    this->scale = scale;
}

void Image::setScale(float x, float y){
    setScale(floatPair{x,y});
}

void Image::setRotation(float rotation){
    this->rotation = rotation;
}

void Image::setHitbox(Rectangle hitbox){
    this->hitbox = hitbox;
}

GRRLIB_texImg Image::getTexture(){return *texture;}
floatPair Image::getScale(){return scale;}
float Image::getRotation(){return rotation;}
Rectangle Image::getHitbox(){return hitbox;}

