#include<actors/explosion/Explosion.h>
#include<actors/splinter/Splinter.h>

void InitExplosion(float x, float y, unsigned int count)
{
	for (size_t i = 0; i < count; i++) {
		InitSplinter(x, y);
	}
}