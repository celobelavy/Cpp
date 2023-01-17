#include <iostream>
#include "Point.h"
#include "Rectangle.h"

int main()
{
    Point pos1;
    if(!pos1.InitMembers(-2, 4))
        std::cout << "초기화 실패" << std::endl;
    if(!pos1.InitMembers(2, 4))
        std::cout << "초기화 실패" << std::endl;

    Point pos2;
    if(!pos2.InitMembers(5, 9))
        std::cout << "초기화 실패" << std::endl;

    Rectangle rec;
    if(!rec.InitMembers(pos2, pos1))
        std::cout << "직사각형 초기화 실패" << std::endl;

    if(!rec.InitMembers(pos1, pos2))
        std::cout << "직사각형 초기화 실패" << std::endl;
    
    rec.ShowRecInfo();
    return 0;
}