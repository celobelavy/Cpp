#include <iostream>
#include "Point.h"

Point::Point(const int &xpos, const int &ypos)
{
    x = xpos;
    y = ypos;
}

int Point::GetX() const { return x; }
int Point::GetY() const { return y; }

bool Point::SetX(int xpos)
{
    if(0 > xpos || xpos > 100)
    {
        std::cout << "벗어난 범위의 값 전달" << std::endl;
        return false;
    }

    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if(0 > ypos || ypos > 100)
    {
        std::cout << "벗어난 범위의 값 전달" << std::endl;
        return false;
    }

    y = ypos;
    return true;
}