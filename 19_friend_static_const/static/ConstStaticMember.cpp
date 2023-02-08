#include <iostream>

class CountryArea
{
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

int main()
{
    std::cout << "러시아 면적 : " << CountryArea::RUSSIA << "km^2" << std::endl;
    std::cout << "캐나다 면적 : " << CountryArea::CANADA << "km^2" << std::endl;
    std::cout << "중국 면적 : " << CountryArea::CHINA << "km^2" << std::endl;
    std::cout << "한국 면적 : " << CountryArea::SOUTH_KOREA << "km^2" << std::endl;
    return 0;
}