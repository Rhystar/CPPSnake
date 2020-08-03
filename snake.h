#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "node.h"
#include "food.h"

class snake
{
protected:
    std::vector<node> s;
    char direction;
    bool invincible;

public:
    snake();
    node head();
    int length();
    bool eat(food f);
    void change_direction(char d);
    void move(bool add);
    bool died();
    bool print_node(int x, int y);
};

#endif