#ifndef _BODY_
#define _BODY_

#include<vector>
#include<cstdint>
#include<string>

typedef struct {
	int x;
	int y;
} Coord;

typedef struct {
	std::vector<Coord> coords;
	int32_t color;
	int32_t outline;
	std::string tag;
} Vertex;

struct Body {
	std::vector<Vertex> components;
	bool shape_generated;
};

extern std::vector<Body*> bodies;

#endif // !_BODY_
