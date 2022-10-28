#include "game-lib.h"

Tilemap::Tilemap(std::vector<std::vector<int>> m){
    map = m;
}

std::vector<std::vector<int>> Tilemap::get_map() { return map;}