#include <iostream>

class SoBase
{
private:
    int baseNum;
public:
    SoBase(int n) : baseNum(n)
    {
        std::cout << "SoBase() : " << baseNum << std::endl;
    }
    ~SoBase()
    {
        std::cout << "~SoBase() : " << baseNum << std::endl;
    }
};

class SoDerived : public SoBase
{
private:
    int derivNum;
public:
    SoDerived(int n) : SoBase(n), derivNum(n)
    {
        std::cout << "SoDerived() : " << derivNum << std::endl;
    }
    ~SoDerived()
    {
        std::cout << "~SoDerived() : " << derivNum << std::endl;
    }
};

int main()
{
    SoDerived drv1(15);
    SoDerived drv2(27);
    return 0;
}