#include <iostream>

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++;
        std::cout << simObjCnt << "번째 SoSimple 객체" << std::endl;
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++;
        std::cout << cmxObjCnt << "번째 SoComplex 객체" << std::endl;
    }
    SoComplex(SoComplex &copy)
    {
        cmxObjCnt++;
        std::cout << cmxObjCnt << "번째 SoComplex 객체" << std::endl;
    }
};

int main()
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2=com1;
    SoComplex();
    return 0;
}