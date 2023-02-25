#include <iostream>
#include <cstring>

class Computer
{
private:
    char owner[50];
public:
    Computer(char * name)
    {
        strcpy(owner, name);
    }
    void Calculate()
    {
        std::cout << "요청 내용을 계산합니다." << std::endl;
    }
};

class NotebookComp : public Computer
{
private:
    int Battery;
public:
    NotebookComp(char * name, int initChag) : Computer(name), Battery(initChag) {}
    void Charging() { Battery += 5; }
    void UseBattery() { Battery -= 1; }
    void MovingCal()
    {
        if(GetBatteryInfo()<1)
        {
            std::cout << "충전이 필요합니다." << std::endl;
            return;
        }
        std::cout << "이동 하면서 ";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
    char regstPenModel[50];
public:
    TabletNotebook(char * name, int initChag, char * pen) : NotebookComp(name, initChag)
    {
        strcpy(regstPenModel, pen);
    }
    void Write(char * penInfo)
    {
        if (GetBatteryInfo() < 1)
        {
            std::cout << "충전이 필요합니다." << std::endl;
            return;
        }
        if(strcmp(regstPenModel, penInfo) != 0)
        {
            std::cout <<"등록된 펜이 아닙니다.";
            return;
        }
        std::cout << "필기 내용을 처리합니다." << std::endl;
        UseBattery();
    }
};

int main()
{
    NotebookComp nc("이수종", 5);
    TabletNotebook tn("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}