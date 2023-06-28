#pragma once
#include "Sprite.h"
#include <vector>
/*

    Logica do tilemap
    Numeros: Posicao do Sprite, separados por espaço
    00: Nada
    01: representa primeiro sprite(0)

    Sera escalonado
    Ex.: Tilemap de 64:48 -> cada tile com 10x tudo (posicao e escala)
    Tilemap de 32:24 -> 20x

    00 00 00 00
    00 00 03 00
    00 01 02 00
    
    TODO:
        adicionar readFile
*/

class Tilemap{

    public:
        Tilemap(int* tilemap, Sprite sprite, intPair dimensions);
        void draw();
        void setSprite(Sprite sprite);
        void setTilemap(int* tilemap, intPair dimensions);
        void setScale(intPair scale);
        
        std::vector<std::vector<int>> getTilemap();
        Sprite getSprite();
        intPair getScale();



    private: 
        std::vector<std::vector<int>> tilemap;
        Sprite sprite;
        intPair scale;

        void initTileMap();

};