#ifndef _STATE_
#define _STATE_
#include<string>
#include<vector>

struct State {
	std::string tag;
	bool active;
};

extern std::vector<State> states;

#endif // !_STATE_
