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
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) {
                handleOrbitAngle(world);
            } else if (event.key.code == sf::Keyboard::Space) {
                handleMovement(world);
            }
            break;
        default:
            break;
    }
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

void EventHandler::handleMovement(World& world) {
    PlayerCharacter& player = world.getPlayerCharacter();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.velocity = sf::Vector2f(std::cos(player.orbitAngle), std::sin(player.orbitAngle)) * 2.0f;
    }
}