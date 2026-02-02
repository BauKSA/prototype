#include<game/system/AABB.h>
#include<SFML/Graphics/ConvexShape.hpp>
#include<SFML/Graphics/Rect.hpp>
#include<SFML/Graphics/Transform.hpp>
#include<SFML/System/Vector2.hpp>

sf::FloatRect GetAABB(const sf::ConvexShape& shape) {
    if (shape.getPointCount() == 0)
        return sf::FloatRect(0, 0, 0, 0);

    sf::Transform t = shape.getTransform();
    sf::Vector2f first = t.transformPoint(shape.getPoint(0));

    float left = first.x;
    float top = first.y;
    float right = first.x;
    float bottom = first.y;

    for (size_t i = 1; i < shape.getPointCount(); i++) {
        sf::Vector2f p = t.transformPoint(shape.getPoint(i));
        if (p.x < left)   left = p.x;
        if (p.x > right)  right = p.x;
        if (p.y < top)    top = p.y;
        if (p.y > bottom) bottom = p.y;
    }

    return sf::FloatRect(left, top, right - left, bottom - top);
}

bool AABB_Intersect(const sf::ConvexShape& a, const sf::ConvexShape& b) {
    sf::FloatRect rectA = GetAABB(a);
    sf::FloatRect rectB = GetAABB(b);

    return rectA.intersects(rectB);
}