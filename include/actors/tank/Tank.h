#ifndef _TANK_
#define _TANK_
#include<vector>
#include<string>
#include<game/Entity.h>

extern std::vector<Entity> tanks;
extern std::string TANK_TAG;

void InitTank();
void DeactivateTank(Entity tank);

#endif //_TANK_