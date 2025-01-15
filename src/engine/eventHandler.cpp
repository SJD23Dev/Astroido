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
    } else if (event.key.code == sf::Keyboard::F && !player.isLocked) {
        player.isLocked = true;
        player.lockAngle = player.headerAngle;
    } else if (event.key.code == sf::Keyboard::F && player.isLocked) {
        player.isLocked = false;
    } else if (event.key.code == sf::Keyboard::A) {
        player.headerAngle -= 0.15f;
    } else if (event.key.code == sf::Keyboard::D) {
        player.headerAngle += 0.15f;
    }
}

void EventHandler::handleKeyRelease(World& world) {
}

void EventHandler::handleHeadingAngle(World& world) {
    PlayerCharacter& player = world.getPlayerCharacter();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.headerAngle -= 0.15f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.headerAngle += 0.15f;
    }
}