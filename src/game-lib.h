#pragma once
#include <grrlib.h>
#include <wiiuse/wpad.h>

class Game{
    public:
        void init();
        void update_wiimote();
        bool wiimote_pressed(ubyte button);
        ir_t ir1;
        u32 wpaddown, wpadheld;
    private:
};

class pos{
    public:
        float x;
        float y;
};

class Rectangle{
    public:
        Rectangle(float x, float y, float h, float w, u32 _color, bool _filled);
        Rectangle();
        pos get_pos();
        void set_pos(float x, float y);

        float get_h();
        float get_w();
        void set_h(float h);
        void set_w(float w);

        void render();

        void move(float x, float y);

    private:
        float width = 10;
        float height = 10;
        u32 color = 0xff00ffff;
        bool filled;
        pos position;
};

class ImageTexture{
    public:
        ImageTexture(const u8 * image);

        const GRRLIB_texImg *get_img();
    private:
        GRRLIB_texImg *texture;

};