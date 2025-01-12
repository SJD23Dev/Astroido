#include "engine/eventHandler.hpp"
#include "engine/renderer.hpp"

bool EventHandler::pollEvent(Renderer& renderer) {
    while (renderer.getWindow().pollEvent(event)) {
        handleEvent(renderer, *this);
    }

    return true;
}

void EventHandler::handleEvent(Renderer& renderer, EventHandler& event) {
    switch (event.event.type) {
        case sf::Event::Closed:
            renderer.getWindow().close();
            break;
        default:
            break;
    }
}