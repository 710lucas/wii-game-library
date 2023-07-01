#pragma once

#include "VisualElement.h"
#include <grrlib.h>
#include "misc.h"
#include "Rectangle.h"

class Image : public VisualElement{

    public:
        Image(const u8 * image);
        Image(const u8 * image, float px, float py);
        Image(const u8 * image, float px, float py, float scaleX, float scaleY, float rotation, u32 color);
        Image(const u8 * image, floatPair pos, floatPair scale, float rotation, u32 color);

        void draw();
        void setTexture(GRRLIB_texImg &texture);
        void setScale(floatPair scale);
        void setScale(float x, float y);
        void setRotation(float rotation);
        void setHitbox(Rectangle hitbox);
        void move(floatPair amount) override;
        void move(float x, float y) override;
        void setPosition(floatPair position) override;

        Collision moveAndCollide(Rectangle collisionRectangle, float amountX, float amountY);


        GRRLIB_texImg * getTexture();
        floatPair getScale();
        float getRotation();
        Rectangle getHitbox();


    private:
        GRRLIB_texImg *texture;
        floatPair scale;
        float rotation;
        Rectangle hitbox;

};