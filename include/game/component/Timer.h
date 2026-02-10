#ifndef _TIMER_
#define _TIMER_
#include<functional>
#include<vector>

#include<game/Entity.h>

typedef std::function<void(Entity)> Callback;

typedef struct Timer
{
	float timer;
	float cb_time;
	Callback callback;
} Timer;

extern std::vector<Timer> timers;
extern std::vector<Entity> timedEntities;

#endif // !_TIMER_
