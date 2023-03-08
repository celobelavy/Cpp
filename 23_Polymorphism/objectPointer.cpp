#include <iostream>

class Person
{
public:
    void Sleep() { std::cout << "Sleep" << std::endl; }
};

class Student : public Person
{
public:
    void Study() { std::cout << "Study" << std::endl; }
};

class PartTimeStudent : public Student
{
public:
    void work() { std::cout << "Work" << std::endl; }
};

int main()
{
    Person * ptr1 = new Student();
    Person * ptr2 = new PartTimeStudent();
    Student * ptr3 = new PartTimeStudent();
    ptr1 -> Sleep();
    ptr2 -> Sleep();
    ptr3 -> Study();
    delete ptr1;
    delete ptr2;
    delete ptr3;
    return 0;
}