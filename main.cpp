#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "snake.h"
#include "food.h"
#include "const.h"
#include "ui.h"
using namespace std;

static snake rhys;

int main()
{
    food *apple = new food;
    while (1)
    {
        system("cls");
        if (rhys.died())
            break;
        bool eat = rhys.eat(*apple);
        if (eat)
        {
            delete apple;
            apple = new food;
        }
        char direction = 0;
        if (kbhit())
            direction = getch(); 
        if (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd')
            rhys.change_direction(direction);
        rhys.move(eat);
        print_game(rhys, *apple);
        print_message();
        //Sleep(1);
    }
    cout << "out" << endl
         << rhys.length() << endl;
    system("pause");
}