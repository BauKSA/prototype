#include <cstdlib>

#include<game/system/PlayerInput.h>
#include<game/input/PlayerRotate.h>
#include<game/system/JoystickInput.h>
#include<game/input/PlayerShoot.h>

#include<actors/player/Player.h>
#include<game/component/Position.h>

static void CheckRotation() {
	if (std::abs(joystick.LeftStick.x) < 0.5) return;
	PlayerRotate();
}

static void Shoot() {
	if (joystick.Buttons[(size_t)Action::SHOOT] && !prevJoystick[(size_t)Action::SHOOT]) {
		PlayerShoot();
	}
}

void DispatchPlayerInput() {
	CheckRotation();
	Shoot();

	if (joystick.Buttons[(size_t)Action::RESET_POSITION] && !prevJoystick[(size_t)Action::RESET_POSITION]) {
		positions[Player] = { 300.f, 400.f };
	}
}