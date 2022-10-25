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

class Image{
    public:
        Image(const u8 * image);
        Image(const u8 * image, float px, float py);
        Image(const u8 * imagem, float px, float py, float h, float w, float rotation, u32 _color);
        
        void render();
        void render(float px, float py);

        void set_pos(float px, float py);
        void set_scale(float x, float y);
        void set_rotation(float rot);
        void set_color(u32 col);
        void move(float x, float y);

        pos get_pos();
        pos get_scale();
        float get_rotation();

        const GRRLIB_texImg *get_img();
    private:
        GRRLIB_texImg *texture;
        pos position = {10, 10};
        pos scale = {1, 1};
        float rotation = 0;
        u32 color = 0xffffffff;
};