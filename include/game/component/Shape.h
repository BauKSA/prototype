#ifndef _SHAPE_
#define _SHAPE_
#include<SFML/Graphics/ConvexShape.hpp>
#include<vector>

typedef std::vector<sf::ConvexShape> Shape;

extern std::vector<Shape> shapes;

#endif // !_SHAPE_