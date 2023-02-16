#include <iostream>
#include <cstring>

class PermanentWorker
{
private:
    char name[20];
    int salary;     // 매달 지불해야하는 급여
public:
    PermanentWorker(char * name, int money) : salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        std::cout << "name : " << name << std::endl;
        std::cout << "salary :" << GetPay() << std::endl << std::endl;
    }
};

class EmployeeHandler
{
private:
    PermanentWorker * empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(PermanentWorker * emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i = 0; i < empNum; i++)
            empList[i] -> ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for(int i = 0; i < empNum; i++)
            sum+=empList[i]->GetPay();
        std::cout << "salary sum : " << sum << std::endl;
    }
    ~EmployeeHandler()
    {
        for(int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // 직원 관리를 목적으로 설계도니 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}