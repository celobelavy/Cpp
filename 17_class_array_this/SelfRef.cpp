#include <iostream>

class SelfRef
{
private:
   int num;
public:
   SelfRef(int n) : num(n)
   {
       std::cout << "객체생성"  << std::endl;
   }
   SelfRef &Adder(int n)
   {
       num+=n;
       return *this;
   }
    SelfRef &ShowTwoNumber()
    {
        std::cout << num << std::endl;
        return *this;
    }
};

int main()
{
    SelfRef obj(3);
    SelfRef &ref=obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;
}