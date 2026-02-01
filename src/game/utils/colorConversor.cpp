#include <cstdint>
#include <SFML/Graphics/Color.hpp>

#include "game/utils/ColorConversor.h"

uint32_t SfToHex(sf::Color color) {
	return (color.r << 16) | (color.g << 8) | color.b;
}

sf::Color HexToSf(uint32_t color) {
	sf::Color sf((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	return sf;
}