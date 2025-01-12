#include "engine/eventHandler.hpp"
#include "engine/renderer.hpp"
#include "engine/world.hpp"

bool EventHandler::pollEvent(Renderer& renderer, World& world) {
    while (renderer.getWindow().pollEvent(event)) {
        handleEvent(renderer, world);
    }

    return true;
}

void EventHandler::handleEvent(Renderer& renderer, World& world) {
    switch (event.type) {
        case sf::Event::Closed:
            renderer.getWindow().close();
            break;
        case sf::Event::KeyPressed:
            handleKeyPress(world);
            break;
        case sf::Event::KeyReleased:
            handleKeyRelease(world);
            break;
        default:
            break;
    }
}

void EventHandler::handleKeyPress(World& world) {
    PlayerCharacter& player = world.getPlayerCharacter();
    if (event.key.code == sf::Keyboard::W && player.thrust < 5) {
        player.thrust++;
    } else if (event.key.code == sf::Keyboard::S && player.thrust > 0) {
        player.thrust--;
    }
}

void EventHandler::handleKeyRelease(World& world) {
}

void EventHandler::handleOrbitAngle(World& world) {
    PlayerCharacter& player = world.getPlayerCharacter();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.orbitAngle -= 0.15f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.orbitAngle += 0.15f;
    }
}