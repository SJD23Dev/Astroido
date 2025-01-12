#pragma once

#include "renderer.hpp"

class Game {
private:
    Renderer renderer;
public:
    Game();
    bool run();
};