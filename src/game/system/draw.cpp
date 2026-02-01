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
#include<game/component/Animation.h>
#include <iostream>

void DrawActors(sf::RenderWindow& window) {
    std::cout << "drawing " << layers.size() << " entities" << std::endl;

    for (size_t i = 0; i < layers.size(); i++) {
        std::cout << "processing layer index: " << i << std::endl;
        Entity e = layers.at(i).entity;
        std::cout << "layer: " << i << ", entity: " << e << std::endl;

        if (!states[e].active) {
            std::cout << "skipping inactive entity : " << e << std::endl;
            continue;
        }

        const Body& body = *bodies.at(e);
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

        bool has_animation_to_update = false;

        if (e < animations_to_update.size()) {
            has_animation_to_update = animations_to_update[e];
			animations_to_update[e] = false;
        }

		if (e < shapes.size() && !shapes[e].empty() && !has_animation_to_update) {

			std::cout << "entity " << e << " has existing shapes [" << shapes[e].size() << "]" << std::endl;
            for (size_t j = 0; j < shapes[e].size(); j++) {
				sf::ConvexShape& shape = shapes[e][j];

                shape.setPosition(xPos, yPos);
                shape.setRotation(rotation_angle);

                std::cout << "drawing existing shape entity : " << e << std::endl;
                window.draw(shape);
                std::cout << "drawn existing shape : " << e << std::endl;
            }

            continue;
        }

        for (const Vertex& component : body.components) {
            if (component.coords.empty()) {
				std::cout << "skipping empty shape entity : " << e << std::endl;
                continue;
            }

            if (e > shapes.size()) {
				std::cout << "resizing shapes for entity : " << e << std::endl;
                shapes.resize(GetCurrentEntity());
            }


			std::cout << "creating new shape for entity : " << e << std::endl;
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

            // Rotación alrededor del centro del componente
            shape.setOrigin(center_x, center_y);

            // Posición final de la entidad + centro
            shape.setPosition(xPos + center_x, yPos + center_y);

            shape.setRotation(rotation_angle);

            shape.setFillColor(HexToSf(component.color));
            shape.setOutlineColor(HexToSf(component.outline));
            shape.setOutlineThickness(1.f);


			std::cout << "storing new shape for entity : " << e << std::endl;
			shapes[e].push_back(shape);

            std::cout << "drawing new shape entity : " << e << std::endl;
            window.draw(shape);
            std::cout << "drawn new shape : " << e << std::endl;
        }
    }
}
