#include <iostream>
#include <cstring>

class Gun
{
private:
    int bullet;     // 장전된 총알 수
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        std::cout << "BANG!" << std::endl;
        bullet--;
        std::cout << "bullet : " << bullet << std::endl;
    }
};

class Police : public Gun
{
private:
    int handcuffs;      // 소유한 수갑 수
public:
    Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff) {}
    void PutHandcuff()
    {
        std::cout << "SNAP!" << std::endl;
        handcuffs--;
        std::cout << "handcuffs : " << handcuffs << std::endl;
    }
};

int main()
{
    Police pman(5, 3);      // 총알 5, 수갑 3
    //Police pman(0, 0);
    pman.Shot();
    pman.PutHandcuff();
    return 0;
}