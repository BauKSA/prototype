#ifndef _AABB_
#define _AABB_
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Rect.hpp>

sf::FloatRect GetAABB(const sf::ConvexShape& shape);
bool AABB_Intersect(const sf::ConvexShape& a, const sf::ConvexShape& b);

#endif // !_AABB_
