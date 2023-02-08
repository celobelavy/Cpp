#include <iostream>

class SoSimple
{
public:
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt=0;

int main()
{
    std::cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << std::endl;
    SoSimple sim1;
    SoSimple sim2;

    std::cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << std::endl;
    std::cout << sim1.simObjCnt << "번째 SoSimple 객체" << std::endl;
    std::cout << sim1.simObjCnt << "번째 SoSimple 객체" << std::endl;
    return 0;
}