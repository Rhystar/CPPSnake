#include "snake.h"
#include "food.h"
#include "node.h"
#include "const.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

snake::snake()
{
    node head;
    head.x = WIDE / 2;
    head.y = HIGH / 2;
    s.push_back(head);
    invincible = 0;
}

node snake::head()
{
    return s.front();
}

int snake::length()
{
    return s.size();
}

bool snake::eat(food f)
{
    if (s.front().x == f.x && s.front().y == f.y)
    {
        if (f.kind == 1)
            invincible = 1;
        return 1;
    }
    else
        return 0;
}

void snake::change_direction(char d)
{
    direction = d;
}

void snake::move(bool add)
{
    if (add)
    {
        node tail = s.back();
        s.push_back(tail);
    }
    int size = s.size();
    for (int i = size - 1; i > 0; i--)
    {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
        if (s[i].x < 0)
            s[i].x += WIDE;
        if (s[i].x >= WIDE)
            s[i].x -= WIDE;
        if (s[i].y < 0)
            s[i].y += HIGH;
        if (s[i].y >= HIGH)
            s[i].y -= HIGH;
    }
    switch (direction)
    {
    case 'w':
        s[0].y--;
        break;
    case 'a':
        s[0].x--;
        break;
    case 's':
        s[0].y++;
        break;
    case 'd':
        s[0].x++;
        break;
    default:
        break;
    }
    if (s[0].x < 0)
        s[0].x += WIDE;
    if (s[0].x >= WIDE)
        s[0].x -= WIDE;
    if (s[0].y < 0)
        s[0].y += HIGH;
    if (s[0].y >= HIGH)
        s[0].y -= HIGH;
}

bool snake::died()
{
    int size = s.size(); 
    if (size > 1)
    {
        for (int i = 1; i < size; i++)
        {
            if (s.front().x == s[i].x && s.front().y == s[i].y)
            {
                if (invincible)
                {
                    invincible = 0;
                    return 0;
                }    
                else
                    return 1;
            }
        }
        return 0;
    }
    else
        return 0;
}

bool snake::print_node(int x, int y)
{
    bool flag = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i].x == x && s[i].y == y)
        {
            putchar('#');
            return 1;
        }
    }
    return 0;
}