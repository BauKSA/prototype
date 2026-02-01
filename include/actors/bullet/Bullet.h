#ifndef _BULLET_
#define _BULLET_
#include<vector>
#include<game/Entity.h>
#include<string>

extern std::vector<Entity> Bullets;
extern std::string BULLET_TAG;

void InitBullet();
void DeactivateBullet(Entity bullet);

#endif //_BULLET_