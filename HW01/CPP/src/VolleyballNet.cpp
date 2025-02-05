#include "../include/VolleyballNet.h"
#include <iostream>
#include <string>
using namespace std;

VolleyballNet::VolleyballNet(string type, string size, double price) : Volleyball(price) {
    this->type = type;
    this->size = size;
    this->price = price;
}

void VolleyballNet::display() {
    cout << "$" << this->price << " - This volleyball is made for " << this->type << "s and is " << this->size << endl;
}