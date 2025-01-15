#include "engine/game.hpp"

Game::Game() : renderer(),
               world() {
    
}

void Game::run() {
    while (renderer.isOpen()) {
        eventHandler.pollEvent(renderer, world); // Poll events
        eventHandler.handleHeadingAngle(world); // Handle heading angle seperately
        world.update(); // Update/simulate the world
        renderer.update(world); // Draw the world to the screen
    }
}