#include<game/input/PlayerRotate.h>
#include<actors/player/Player.h>
#include<game/system/JoystickInput.h>
#include<game/component/Transform.h>

void PlayerRotate() {
	if (Player > transforms.size()) return;

	transforms[Player].rotation += joystick.LeftStick.x;
}