#include "../include/IndoorItem.h"
#include <iostream>

using namespace std;

IndoorItem::IndoorItem(double price) : Item() {
    this->price = price;
};

void IndoorItem::display() {
    cout << "This indoor item is $" << this->price << endl;
}