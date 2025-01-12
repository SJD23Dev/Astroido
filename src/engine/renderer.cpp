#include "engine/renderer.hpp"

Renderer::Renderer() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Astroido") {
    window.setFramerateLimit(FPS);
}

sf::RenderWindow& Renderer::getWindow() {
    return window;
}

bool Renderer::isOpen() {
    return window.isOpen();
}

void Renderer::update(World& world) {
    window.clear();
    world.render(window);
    window.display();
}