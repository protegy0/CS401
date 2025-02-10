#include "Employee.h"
#include <iostream>
using namespace std;

int main() {

    // Declaring base class employees
    Employee* employee1 = new Employee("Dylon Morgan", 1, 2000);
    Employee* employee2 = new Employee("Jamichael York", 2, 2500);

    // Declaring regular employee derived class employees
    Employee* regEmployee1 = new RegularEmployee("Xavier McGee", 3, 3000, 12);
    Employee* regEmployee2 = new RegularEmployee("Ernie Abreu", 4, 3600, 6);

    // Declaring manager derived class employees
    Employee* manager1 = new Manager("Manuel Torres", 5, 4000, 570);
    Employee* manager2 = new Manager("John Fernandez", 6, 4100, 610);

    // Adding all employees to employee pointer array
    Employee* arr[6] = {employee1, employee2, regEmployee1, regEmployee2, manager1, manager2};

    // Looping through employee array to display all info
    for (int i = 0; i < 6; i++) {
        arr[i]->displayInfo();
        arr[i]->calculateSalary();
    }

    // Calling destructors on all created employee objects
    delete employee1;
    delete employee2;
    delete regEmployee1;
    delete regEmployee2;
    delete manager1;
    delete manager2;

    return 0;
}