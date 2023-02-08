#include <iostream>

void Counter()
{
    static int cnt;
    cnt++;
    std::cout << "Current cnt : " << cnt << std::endl;
}

int main()
{
    for(int i=0; i<10; i++)
        Counter();
    return 0;
}