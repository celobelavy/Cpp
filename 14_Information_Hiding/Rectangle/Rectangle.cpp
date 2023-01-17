#include <iostream>
#include "Rectangle.h"

bool Rectangle::InitMembers(const Point &ul, const Point &lr) {
    if (ul.GetX() > lr.GetX() || ul.GetX() > lr.GetY()) {
        std::cout << "잘못된 위치 정보 전달" << std::endl;
        return false;
    }

    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const {
    std::cout << "좌 상단 : " << '[' << upLeft.GetX() << ", ";
    std::cout << upLeft.GetY() << ']' << std::endl;
    std::cout << "우 하단 : " << '[' << lowRight.GetX() << ", ";
    std::cout << lowRight.GetY() << ']' << std::endl << std::endl;
}