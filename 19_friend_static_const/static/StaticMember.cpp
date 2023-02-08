#include <iostream>

class SoSimple
{
private:
    static int simObject;
public:
    SoSimple()
    {
        simObject++;
        std::cout << simObject << "번째 SoSimple 객체" << std::endl;
    }
};

int SoSimple::simObject = 0;

class SoComplex
{
private:
    static int cmxObjCnt;
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
int SoComplex::cmxObjCnt = 0;

int main()
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex cmx1;
    SoComplex cmx2=cmx1;
    SoComplex();
    return 0;
}