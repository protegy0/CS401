#include "../include/Volleyball.h"
#include <iostream>

using namespace std;

Volleyball::Volleyball(double price) {
    this->price = price;
};

void Volleyball::display() {
    cout << "This volleyball item is $" << this->price << endl;
}