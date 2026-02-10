#include<game/system/TimerSystem.h>
#include<game/component/Timer.h>
#include<game/Entity.h>
#include<game/component/State.h>

void TimerSystem(float delta_time)
{
	for (Entity& entity : timedEntities)
	{
		if (entity >= states.size())
			continue;

		if(!states[entity].active)
			continue;

		if (entity >= timers.size())
			continue;

		timers[entity].timer += delta_time;
		if (timers[entity].timer >= timers[entity].cb_time)
		{
			timers[entity].timer = 0.0f;
			timers[entity].callback(entity);
		}
	}
}