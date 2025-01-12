#include "engine/game.hpp"

Game::Game() {}

void Game::run() {
    while (renderer.isOpen()) {
        eventHandler.pollEvent(renderer);
        renderer.update();
    }
}