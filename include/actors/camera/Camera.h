#ifndef _CAMERA_
#define _CAMERA_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

extern sf::RenderWindow* window;
extern sf::View camera;

void InitCamera();
void UpdateCamera();

#endif // !_CAMERA_
