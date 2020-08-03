#include "ui.h"
#include "const.h"
#include "snake.h"
#include "node.h"
#include "food.h"
#include <iostream>
using namespace std;

void print_game(snake s, food f)
{
    for (int i = 0; i < WIDE + 2; i++)
        putchar('-'); 
    putchar('\n');
    for (int i = 0; i < HIGH; i++)
    {
        putchar('|');
        for (int j = 0; j < WIDE; j++)
        {
            if (!s.print_node(j, i) && !f.print_food(j, i))
                cout << ' ';
        }
        puts("|");
    }
    for (int i = 0; i < WIDE + 2; i++)
        putchar('-');
}

void print_message()
{
    
}

