#include "../include/Item.h"
#include <iostream>


using namespace std;

Item::Item(double price) {
    this->price = price;
};

void Item::display() {
    cout << "This is an item." << endl;
}

double Item::getPrice() {
    return this->price;
}

Item::~Item() {};

