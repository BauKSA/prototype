#ifndef _COLORCONVERSOR_
#define _COLORCONVERSOR_
#include <cstdint>
#include <SFML/Graphics/Color.hpp>

uint32_t SfToHex(sf::Color color);
sf::Color HexToSf(uint32_t color);

#endif //_COLORCONVERSOR_