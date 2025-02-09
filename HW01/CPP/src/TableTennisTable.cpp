#include "../include/TableTennisTable.h"
#include <iostream>
#include <string>
using namespace std;

TableTennisTable::TableTennisTable(string material, double price) : IndoorItem(price){
    this->material = material;
    this->price = price;
}

void TableTennisTable::display() {
    cout << "$" << this->price << " - This table tennis table is made of " << this->material;
}