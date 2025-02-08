#include "../include/CampingStove.h"
#include <iostream>
#include <string>
using namespace std;

CampingStove::CampingStove(string size, int wattage, double price) : OutdoorItem(price){
    this->size = size;
    this->wattage = wattage;
    this->price = price;
}

void CampingStove::display() {
    cout << "$" << this->price << " - This camping stove is size " << this->size << " and has a wattage of " << this->wattage << endl;
}