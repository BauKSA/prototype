#ifndef _ANIMFRAMES_
#define _ANIMFRAMES_
#include<game/component/Animation.h>
#include<game/Entity.h>

void UpdateFrames(float delta_time);
void ChangeAnimation(Entity e, ANIMATION_INDEX index);

#endif // !_ANIMFRAMES_
