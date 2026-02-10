#ifndef _SPLINTER_
#define _SPLINTER_
#include<vector>
#include<game/Entity.h>
#include<string>

extern std::vector<Entity> splinters;
extern std::string SPLINTER_TAG;

void InitSplinter(float x, float y, float angle);
void DeactivateSplinter(Entity splinter);

#endif //_BULLET_