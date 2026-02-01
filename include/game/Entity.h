#ifndef _ENTITY_
#define _ENTITY_
#include<iostream>

typedef unsigned int Entity;

void Resize();

inline unsigned int& GetCurrentEntity() {
    static unsigned int current_entity = 0;
    return current_entity;
}

inline Entity CreateEntity() {
    unsigned int& current = GetCurrentEntity();
    Entity new_entity = current;
    current++;

    std::cout << "New entity ID: " << new_entity << std::endl;

    Resize();

    return new_entity;
}

#endif // !_ENTITY_