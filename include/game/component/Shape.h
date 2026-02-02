#ifndef _SHAPE_
#define _SHAPE_
#include<SFML/Graphics/ConvexShape.hpp>
#include<vector>
#include<string>

struct ShapeComponent {
	sf::ConvexShape shape;
	std::string tag;
};

typedef std::vector<ShapeComponent> Shape;

extern std::vector<Shape> shapes;

#endif // !_SHAPE_