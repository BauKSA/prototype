#ifndef _JOY_INPUTSYSTEM_
#define _JOY_INPUTSYSTEM_

#include<bitset>
#include<cstdint>

typedef uint8_t JoystickID;

enum class Action : uint8_t {
	ROTATE,
	MOVE_FORWARD,
	MOVE_BACKWARD,
	SHOOT,

	//DEBUG
	RESET_POSITION,

	COUNT
};

typedef struct {
	float x;
	float y;
} Axis;

typedef struct {
	Axis LeftStick;
	Axis RightStick;
	std::bitset<(size_t)Action::COUNT> Buttons;
} Joystick;

typedef std::bitset<(size_t)Action::COUNT> PrevButtons;

extern Joystick joystick;
extern PrevButtons prevJoystick;

void ReceiveJoystickInput(JoystickID id);

#endif //_JOY_INPUTSYSTEM_