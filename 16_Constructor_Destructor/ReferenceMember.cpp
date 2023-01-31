#include <iostream>

class AAA
{
public:
    AAA()
    {
        std::cout << "empty object" << std::endl;
    }
    void ShowYourName()
    {
        std::cout << "I'm class AAA" << std::endl;
    }
};

class BBB
{
private:
   AAA &ref;
   const int &num;

public:
    BBB(AAA &r, const int &n) : ref(r), num(n) { }

    void ShowYourName()
    {
        ref.ShowYourName();
        std::cout << "and" << std::endl;
        std::cout << "I ref num " << num << std::endl;
    }
};

int main()
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();
    return 0;
}