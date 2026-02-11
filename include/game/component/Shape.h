#ifndef _SHAPE_
#define _SHAPE_
#include<SFML/Graphics/ConvexShape.hpp>
#include<vector>
#include<string>

#include<game/component/Body.h>

struct ShapeComponent {
	sf::ConvexShape shape;
	Coord offset;
	std::string tag;
};

typedef std::vector<ShapeComponent> Shape;

extern std::vector<Shape> shapes;

#endif // !_SHAPE_