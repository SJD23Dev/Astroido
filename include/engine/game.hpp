#pragma once

#include "renderer.hpp"
#include "eventHandler.hpp"
#include "world.hpp"

class Game {
private:
    Renderer renderer;
    EventHandler eventHandler;
    World world;
public:
    Game();
    void run();
};