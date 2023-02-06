#include <iostream>

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        std::cout << "New Object : " << this << std::endl;
    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        std::cout << "New Copy Obj" << this << std::endl;
    }
    ~SoSimple()
    {
        std::cout << "Destroy obj : " << this << std::endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    std::cout << "Parm ADR : " << &ob << std::endl;
    return ob;
}

int main()
{
    SoSimple obj(7);
    SoSimple tempRef = SimpleFuncObj(obj);
    std::cout << "Return Obj" << &tempRef << std::endl;
    return 0;
}