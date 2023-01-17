#include <iostream>

class Point
{
    public:
        int x;      // 0 <= x <= 100
        int y;      // 0 <= y <= 100
};

class Rectangle
{
    public:
        Point upleft;
        Point lowRight;

    public:
        void ShowRecInfo() {
            std::cout << "좌 상단 : " << '[' << upleft.x << ",";
            std::cout << upleft.y << ']' << std::endl;
            std::cout << "우 하단 : " << '[' << lowRight.x << ",";
            std::cout << lowRight.y << ']' << std::endl << std::endl;
        }
};

int main()
{
    Point pos1={-2, 4};
    Point pos2={5, 9};
    Rectangle rec={pos2, pos1};
    rec.ShowRecInfo();
    return 0;
}