#include<actors/camera/Camera.h>
#include<actors/player/Player.h>

#include<game/component/Position.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Vector2.hpp>

sf::RenderWindow* window = nullptr;
sf::View camera;

void InitCamera() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    if (window) delete window;
    window = new sf::RenderWindow(desktop, "Prototype");

    window->setFramerateLimit(120);

    sf::Vector2f Center(400, 300);
    sf::Vector2f HalfSize(800, 600);
    camera = sf::View(Center, HalfSize);

    float windowRatio = (float)desktop.width / desktop.height;
    float viewRatio = 800.f / 600.f;
    float sizeX = 1.f;
    float sizeY = 1.f;
    float posX = 0.f;
    float posY = 0.f;

    if (windowRatio > viewRatio) {
        // La ventana es más ancha que la vista → bordes negros a los lados
        sizeX = viewRatio / windowRatio;
        posX = (1.f - sizeX) / 2.f;
    }
    else {
        // La ventana es más alta que la vista → bordes negros arriba/abajo
        sizeY = windowRatio / viewRatio;
        posY = (1.f - sizeY) / 2.f;
    }

    camera.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

    window->setView(camera);
}

void UpdateCamera() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    float windowRatio = (float)desktop.width / desktop.height;
    float viewRatio = 800.f / 600.f;
    float vpX = 0.f;
    float vpY = 0.f;
    float vpW = 1.f;
    float vpH = 1.f;

    if (windowRatio > viewRatio) {
        // Ventana más ancha → bordes negros laterales
        vpW = viewRatio / windowRatio;
        vpX = (1.f - vpW) / 2.f;
    }
    else {
        // Ventana más alta → bordes arriba/abajo
        vpH = windowRatio / viewRatio;
        vpY = (1.f - vpH) / 2.f;
    }

    camera.setViewport(sf::FloatRect(vpX, vpY, vpW, vpH));

    // 👉 ESTO es lo que hace que siga al player
    camera.setCenter(positions[Player].x, positions[Player].y);


    window->setView(camera);
}