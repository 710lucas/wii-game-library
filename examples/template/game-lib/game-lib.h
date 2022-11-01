#pragma once
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <iostream>
#include <vector>

class Game{
    public:
        void init();
        void update_wiimote();
        bool wiimote_pressed(ubyte button);
        bool wiimote_pressed(int button);
        bool wiimote_hold(int button);
        bool wiimote_hold(ubyte button);
        ir_t ir1;
        u32 wpaddown, wpadheld;
    private:
};

class pos{
    public:
        float x = 0;
        float y = 0;
};

class Element{
    public:
        pos get_pos();
        u32 get_color();
        bool get_filled();

        void set_pos(int x, int y);
        void set_color(u32 col);
        void set_filled(bool fil);

        void move(int x, int y);
    private:
        pos position;
        u32 color;
        bool filled;
};

class Rectangle : public Element{
    public:
        Rectangle(float x, float y, float h, float w, u32 _color, bool _filled);
        Rectangle();

        float get_h();
        float get_w();
        void set_h(float h);
        void set_w(float w);

        void render();


        bool clicked(Game game);

        bool is_colliding(Rectangle rec);

        bool side_collision(Rectangle rec);

    private:
        float width = 10;
        float height = 10;
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
        Rectangle get_rec();
        const GRRLIB_texImg *get_img();
    private:
        GRRLIB_texImg *texture;
        pos position = {10, 10};
        pos scale = {1, 1};
        float rotation = 0;
        u32 color = 0xffffffff;
        Rectangle rec;
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

class Circle : public Element{
    public:
        Circle(int x, int y, f32 rad, u32 color, bool filled);
        void render();
    private:
        f32 radius;
};

class Button : public Rectangle{
    public:
        Button(std::string label, int x, int y, u32 color);
        std::string get_label();
        std::string get_alignment();
        std::string get_text_alignment();

        void set_label(std::string lab);
        void set_alignment(std::string al);
        void set_text_alignment(std::string al);
        void render_button();
    private:
        std::string label;
        std::string alignment = "center";
        std::string text_align = "center";
};

class Tilemap{
    public:
        Tilemap(std::vector<std::vector<int>> m);
        Tilemap();

        void define(int n, Image im);

        std::vector<std::vector<int>> get_map();

    private:
        std::vector<std::vector<int>> map;
        pos division = {1, 1}; 
        std::vector<Image> textures;
        std::vector<int> textures_index;
        //define em quantas tiles vai dividir o tabuleiro

        //quero algo tipo
        // int map[3][3] = {
        // {1, 0, 2},
        // {1, 0, 1},
        // {1, 2, 1}
        //};
        //Tilemap tile(map);
        // cada numero corresponde a uma imagem diferente
        // Image fnaf(fnaf_test_png)
        // tile.define(1, fnaf)
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