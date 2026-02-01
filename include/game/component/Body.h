#ifndef _BODY_
#define _BODY_

#include<vector>
#include<cstdint>

typedef struct {
	int x;
	int y;
} Coord;

typedef struct {
	std::vector<Coord> coords;
	int32_t color;
	int32_t outline;
} Vertex;

struct Body {
	std::vector<Vertex> components;
};

extern std::vector<Body*> bodies;

#endif // !_BODY_
