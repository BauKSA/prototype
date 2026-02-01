#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

#include "actors/player/Player.h"
#include "actors/bullet/Bullet.h"
#include<actors/star/Star.h>
#include<actors/camera/Camera.h>

#include "game/system/Draw.h"
#include "game/system/JoystickInput.h"
#include "game/system/PlayerInput.h"
#include "game/system/Movement.h"
#include "game/system/ConstantForwardMovement.h"
#include<game/system/AnimFrames.h>

#include "game/component/Position.h"
#include "game/component/State.h"
#include <iostream>

int main() {
    
    InitCamera();

    InitPlayer();

    sf::Clock clock;

    sf::Clock fpsClock;
    int frames = 0;
    float currentFPS = 0.f;
    
    sf::Clock debugClock;

    InitStar();

    while (window->isOpen())
    {
        float delta_time = clock.restart().asMilliseconds();

        sf::Event event;

        ReceiveJoystickInput(0);
        DispatchPlayerInput();

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::JoystickButtonPressed) {
                std::cout << "Pressed button: " << event.joystickButton.button << std::endl;
            }
        }

        for (size_t i = 0; i < Bullets.size(); i++) {
            float x = positions[Bullets.at(i)].x;
            float y = positions[Bullets.at(i)].y;

            bool is_active = states[Bullets.at(i)].active;

            if ((x < 0 || x > 800 || y < 0 || y > 600) && is_active) {
                std::cout << "Deactivate bullet with ID: " << Bullets.at(i)
                    <<" at position: " << x << ", " << y << std::endl;
				DeactivateBullet(Bullets.at(i));
            }
        }

        window->clear(sf::Color::Black);
		UpdateFrames(delta_time);
        ConstantForwardMovement();
        MoveActors(delta_time);
        UpdateCamera();
        DrawActors(*window);
        window->display();

        // ===== Contar FPS =====
        frames++;
        if (fpsClock.getElapsedTime().asSeconds() >= 1.f) {
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            fpsClock.restart();
        }

        // ===== Tiempo para debug =====
		if (debugClock.getElapsedTime().asSeconds() >= 10.f) {
            std::cout << "Debug Time!" << std::endl;
            debugClock.restart();
        }
    }

	return 0;
}