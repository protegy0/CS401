#include "../include/OutdoorItem.h"
#include <iostream>

using namespace std;

OutdoorItem::OutdoorItem(double price) : Item(price) {
    this->price = price;
};

void OutdoorItem::display() {
    cout << "This outdoor item is $" << this->price << endl;
}