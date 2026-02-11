#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <game/component/Body.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "game/Entity.h"
#include "game/system/Draw.h"
#include "game/utils/ColorConversor.h"
#include "game/component/Position.h"
#include "game/component/Transform.h"
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/component/Shape.h>
#include <iostream>
#include <ostream>
#include <string>

void DrawActors(sf::RenderWindow& window) {
    for (size_t i = 0; i < layers.size(); i++) {
        Entity e = layers.at(i).entity;

        if (!states[e].active) {
            continue;
        }

        Body& body = *bodies.at(e);
        int xPos = 0;
        int yPos = 0;
        float rotation_angle = 0.f;

        if (e < positions.size()) {
            xPos = positions[e].x;
            yPos = positions[e].y;
        }

        if (e < transforms.size()) {
            rotation_angle = transforms[e].rotation;
        }

		if (body.shape_generated) {
            for (size_t j = 0; j < shapes[e].size(); j++) {
				sf::ConvexShape& shape = shapes[e][j].shape;
                Coord offset = shapes[e][j].offset;

                shape.setPosition(xPos + offset.x, yPos + offset.y);
                shape.setRotation(rotation_angle);

                window.draw(shape);
            }

            continue;
        }

		body.shape_generated = true;
        std::string tag = "";
        if (e < states.size()) {
            tag = states[e].tag;
        }

        for (const Vertex& component : body.components) {
            std::cout << "Drawing shape for entity " << e << std::endl;
            if (component.coords.empty()) {
                continue;
            }

            if (e >= shapes.size()) {
                shapes.resize(GetCurrentEntity());
            }

            sf::ConvexShape shape;

            shape.setPointCount(component.coords.size());

            float min_x = component.coords[0].x;
            float max_x = component.coords[0].x;
            float min_y = component.coords[0].y;
            float max_y = component.coords[0].y;

            for (size_t i = 0; i < component.coords.size(); ++i) {
                float px = component.coords[i].x;
                float py = component.coords[i].y;

                shape.setPoint(i, sf::Vector2f(px, py));

                if (px < min_x) min_x = px;
                if (px > max_x) max_x = px;
                if (py < min_y) min_y = py;
                if (py > max_y) max_y = py;
            }

            float center_x = (min_x + max_x) / 2.f;
            float center_y = (min_y + max_y) / 2.f;

            shape.setOrigin(center_x, center_y);
            shape.setPosition(xPos + center_x + component.offset.x, yPos + center_y + component.offset.y);
            shape.setRotation(rotation_angle);

            shape.setFillColor(HexToSf(component.color));
            shape.setOutlineColor(HexToSf(component.outline));
            shape.setOutlineThickness(1.f);

			ShapeComponent shapeComp;
			shapeComp.shape = shape;
			shapeComp.tag = tag + "_" + component.tag;
            shapeComp.offset = component.offset;

            shapes[e].push_back(shapeComp);

            window.draw(shape);
        }
    }
}
