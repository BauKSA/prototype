#include<actors/explosion/Explosion.h>
#include<actors/splinter/Splinter.h>
#include<game/utils/Random.h>

void InitExplosion(float x, float y, unsigned int count)
{
	int angle = random(0, 360);

	for (size_t i = 0; i < count; i++) {
		InitSplinter(x, y, angle);
		angle += 360 / count;
	}
}