#include "engine/game.hpp"

Game::Game() : renderer(),
               world() {
    
}

void Game::run() {
    while (renderer.isOpen()) {
        eventHandler.pollEvent(renderer);
        renderer.update(world);
    }
}