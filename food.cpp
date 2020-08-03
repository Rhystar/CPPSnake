#include "food.h"
#include "const.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

food::food()
{
    srand(time(0));
    x = rand() % WIDE; 
    y = rand() % HIGH;
    if (rand() % 20 > 0)
        kind = 0;
    else
        kind = 1;
}

bool food::print_food(int x, int y)
{
    if (this->x == x && this->y == y)
    {
        switch (kind)
        {
        case 0:
            putchar('$');
            return 1;
            break;
        case 1:
            putchar('@');
            return 1;
            break;
        default:
            return 1;
            break;
        }
    }
    else
        return 0;
}