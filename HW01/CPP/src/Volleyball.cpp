#include "../include/Volleyball.h"
#include <iostream>
#include <string>
using namespace std;

Volleyball::Volleyball(string material, string size, double price) : IndoorItem(price){
    this->material = material;
    this->size = size;
    this->price = price;
}

void Volleyball::display() {
    cout << "$" << this->price << " - This volleyball is made of " << this->material << " and is " << this->size << endl;
}