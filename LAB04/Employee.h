#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
    protected:
        string name;
        int id;
        double basicSalary;
    public:
        Employee(string name, int id, double basicSalary);
        virtual void calculateSalary();
        void displayInfo();
        virtual ~Employee();

};

class RegularEmployee : public Employee {
    private:
        int overtimeHours;
    public:
        RegularEmployee(string name, int id, double basicSalary, int overtimeHours);
        void calculateSalary() override;
        ~RegularEmployee();
};

class Manager : public Employee {
    private:
        int bonus;
    public:
        Manager(string name, int id, double basicSalary, int overtimeHours);
        void calculateSalary() override;
        ~Manager();
};

#endif