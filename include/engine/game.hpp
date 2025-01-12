#pragma once

#include "renderer.hpp"
#include "eventHandler.hpp"

class Game {
private:
    Renderer renderer;
    EventHandler eventHandler;
public:
    Game();
    void run();
};