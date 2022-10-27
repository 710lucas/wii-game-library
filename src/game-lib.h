#pragma once
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <iostream>

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
        void set_color(u32 col);

        void render();

        void move(float x, float y);

        bool clicked(Game game);

        bool is_coliding(Rectangle rec);

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

class Text{
    public:
        Text(const u8* file_base, s32 file_size);
        void print(const char* str);
        void print();
        void print(const char* str, int x, int y, int font_size, u32 color);
        void print(int x, int y, int font_size, u32 color);
        void print(const char* str, int x, int y);

        void set_content(const char* inp);
        void set_pos(int x, int y);
        void set_font_size(int f_size);
        void set_color(u32 col);

        const char* get_content();
        pos get_pos();
        int get_font_size();
        u32 get_color();

    private:
        const char* content;
        pos position;
        int font_size;
        u32 color;
        GRRLIB_ttfFont *fonte;
};

/*
ideia de tilmeap
Tile tilemap = {
    {1, 1, 0},
    {1, 1, 1}
}

desenha tipo:

==_
===

*/