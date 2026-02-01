#include "game/system/JoystickInput.h"
#include <SFML/Window/Joystick.hpp>

Joystick joystick{
	{0.f, 0.f},
	{0.f, 0.f},
	{}
};

PrevButtons prevJoystick = {};

void ReceiveJoystickInput(JoystickID id) {
	joystick.LeftStick.x = sf::Joystick::getAxisPosition(id, sf::Joystick::Axis::X) / 100;
	joystick.LeftStick.y = sf::Joystick::getAxisPosition(id, sf::Joystick::Axis::Y) / 100;

	prevJoystick = joystick.Buttons;
	joystick.Buttons[(size_t)Action::SHOOT] = sf::Joystick::isButtonPressed(id, 0);
	joystick.Buttons[(size_t)Action::RESET_POSITION] = sf::Joystick::isButtonPressed(id, 6);
}