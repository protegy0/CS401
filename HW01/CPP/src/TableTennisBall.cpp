#include "../include/TableTennisBall.h"
#include <iostream>
#include <string>
using namespace std;

TableTennisBall::TableTennisBall(double price) : IndoorItem(price){
    this->price = price;
}

void TableTennisBall::display() {
    cout << "$" << this->price << " - A standard table tennis ball";
}