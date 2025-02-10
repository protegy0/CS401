#include "Employee.h"
#include <iostream>
using namespace std;

// Employee constructor
Employee::Employee(string name, int id, double basicSalary) {
    this->name = name;
    this->id = id;
    this->basicSalary = basicSalary;
};

void Employee::calculateSalary() {
    cout << "This employee's salary is $" << this->basicSalary << endl;
}

void Employee::displayInfo() {
    cout << "ID: " << this->id << " - " << this->name << endl;
}

Employee::~Employee() {
    cout << "Employee ID: " << this->id << " deleted" << endl;
}

// Regular Employee constructor - inherits Employee
RegularEmployee::RegularEmployee(string name, int id, double basicSalary, int overtimeHours) : Employee(name, id, basicSalary) {
    this->name = name;
    this->id = id;
    this->basicSalary = basicSalary;
    this->overtimeHours = overtimeHours;
};

void RegularEmployee::calculateSalary() {
    // Multiplying overtime hours by 16 to get overtime pay
    int extraPay = 16 * this->overtimeHours;
    cout << "This employee's salary is $" << this->basicSalary << " + overtime pay of $" << extraPay << endl;
}

RegularEmployee::~RegularEmployee() {
    cout << "Regular Employee ID: " << this->id << " deleted" << endl;
}

// Manager constructor - inherits Employee
Manager::Manager(string name, int id, double basicSalary, int bonus) : Employee(name, id, basicSalary) {
    this->name = name;
    this->id = id;
    this->basicSalary = basicSalary;
    this->bonus = bonus;
};

void Manager::calculateSalary() {
    cout << "This employee's salary is $" << this->basicSalary << " + a bonus of $" << this->bonus << endl;
}

Manager::~Manager() {
    cout << "Manager ID: " << this->id << " deleted" << endl;
}