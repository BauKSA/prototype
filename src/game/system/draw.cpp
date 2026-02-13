#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <game/component/Body.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include<cmath>

#include "game/Entity.h"
#include "game/system/Draw.h"
#include "game/utils/ColorConversor.h"
#include "game/component/Position.h"
#include "game/component/Transform.h"
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/component/Shape.h>
#include <string>

void DrawActors(sf::RenderWindow& window) {
    for (size_t i = 0; i < layers.size(); i++) {
        Entity e = layers.at(i).entity;

        if (!states[e].active) {
            continue;
        }

        Body& body = *bodies.at(e);

        float xPos = 0.f;
        float yPos = 0.f;
        float rotation_angle = 0.f;

        if (e < positions.size()) {
            xPos = (float)positions[e].x;
            yPos = (float)positions[e].y;
        }

        if (e < transforms.size()) {
            rotation_angle = transforms[e].rotation;
        }

        // Precalcular rotación una sola vez
        float rad = rotation_angle * 3.14159265f / 180.f;
        float cos_r = std::cos(rad);
        float sin_r = std::sin(rad);

        // ===============================
        // Shapes ya generados
        // ===============================
        if (body.shape_generated) {
            for (ShapeComponent& comp : shapes[e]) {

                float ox = comp.offset.x;
                float oy = comp.offset.y;

                float rx = ox * cos_r - oy * sin_r;
                float ry = ox * sin_r + oy * cos_r;

                comp.shape.setPosition(xPos + rx, yPos + ry);
                comp.shape.setRotation(rotation_angle);

                window.draw(comp.shape);
            }

            continue;
        }

        // ===============================
        // Generación inicial de shapes
        // ===============================
        body.shape_generated = true;

        if (e >= shapes.size()) {
            shapes.resize(GetCurrentEntity());
        }

        std::string tag = (e < states.size()) ? states[e].tag : "";

        for (const Vertex& component : body.components) {
            if (component.coords.empty()) {
                continue;
            }

            sf::ConvexShape shape;
            shape.setPointCount(component.coords.size());

            for (size_t i = 0; i < component.coords.size(); ++i) {
                shape.setPoint(i, sf::Vector2f(
                    component.coords[i].x,
                    component.coords[i].y
                    ));
            }

            // ORIGEN COMÚN DEL ACTOR
            shape.setOrigin(0.f, 0.f);

            // Offset rotado
            float offset_x = component.offset.x;
            float offset_y = component.offset.y;

            float rotated_x = offset_x * cos_r - offset_y * sin_r;
            float rotated_y = offset_x * sin_r + offset_y * cos_r;

            shape.setPosition(xPos + rotated_y, yPos + rotated_x);
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

