#include <string>
using namespace std;

#ifndef ADAPTER_H
#define ADAPTER_H
class Employee {
    private:
        string name;
        int age;
        int salary;
    public:
        Employee(string n, int a, int s): name(n), age(a), salary(s) {};
        void setAge(int age) { this->age = age;};
        int getAge() { return this->age;};
        void setName(string name) { this->name = name;};
        string getName() { return this->name;};
        void setSalary(int salary) { this->salary = salary;};
        int getSalary() { return this->salary;};
};

class Adapter: public Employee {
    private:
        string addr;
    public:
        Adapter(string n, int a, int s, string addr): Employee(n, a, s), addr(addr) {};
        void setAddr(string addr) { this->addr = addr;};
        string getAddr() { return this->addr;};
};
#endif
