#include <iostream>
#include <cstring>

class Gun
{
private:
    int bullet;     // 장전된 총알의 수
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        std::cout << "BANG!" << std::endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;      //소지한 수갑 수
    Gun * pistol;       // 소지하고 있는 권총
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if(bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol=NULL;
    }
    void PutHandcuff()
    {
        std::cout << "SNAP!" << std::endl;
        handcuffs--;
    }
    void Shot()
    {
        if (pistol==NULL)
            std::cout << "RELOAD PLEASE" << std::endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol != NULL)
            delete pistol;
    }
};

int main()
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);     // 권총을 소유하지 않은 경찰
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}