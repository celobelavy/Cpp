#include <iostream>

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n) {}
    SoSimple(const SoSimple &copy) : num(copy.num)
    {
        std::cout << "Caslled SoSimple(const SoSimple &copy)" << std::endl;
    }
    void ShowData()
    {
        std::cout << "num : " << num << std::endl;
    }
};

void SimpleerFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main()
{
    SoSimple obj(7);
    std::cout << "함수호출 전" << std::endl;
    SimpleerFuncObj(obj);
    std::cout << "함수 호출 후" << std::endl;
    return 0;
}