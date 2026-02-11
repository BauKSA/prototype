#include <vector>
#include <iostream>

#include<SFML/Graphics/Color.hpp>
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/System/Time.hpp>
#include<SFML/Window/Window.hpp>
#include<SFML/Window/WindowBase.hpp>
#include<SFML/Window/Event.hpp>
#include<SFML/System/Clock.hpp>

#include<actors/player/Player.h>
#include<actors/circuits/example/ExampleCircuit.h>
#include<actors/star/Star.h>
#include<actors/camera/Camera.h>
#include<actors/tank/Tank.h>

#include<game/system/Draw.h>
#include<game/system/JoystickInput.h>
#include<game/system/PlayerInput.h>
#include<game/system/Movement.h>
#include<game/system/ConstantForwardMovement.h>
#include<game/system/CollisionSystem.h>
#include<game/system/TimerSystem.h>

#include<game/event/Event.h>
#include<game/utils/EventContainer.h>

int main() {
    InitCamera();

    InitPlayer();

    sf::Clock clock;

    sf::Clock fpsClock;
    int frames = 0;
    float currentFPS = 0.f;

    sf::Clock debugClock;

    InitStar();
    InitTank();

    InitCollisionEvents();
    InitExampleCircuit();

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

        window->clear(sf::Color::Black);

        ConstantForwardMovement();
        TimerSystem(delta_time);
        MoveActors(delta_time);
        CheckCollisions();
        DispatchEvents();
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