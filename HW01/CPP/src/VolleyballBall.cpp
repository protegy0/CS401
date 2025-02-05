#include "../include/VolleyballBall.h"
#include <iostream>
#include <string>
using namespace std;

VolleyballBall::VolleyballBall(string material, string size, double price) : Volleyball(price){
    this->material = material;
    this->size = size;
    this->price = price;
}

void VolleyballBall::display() {
    cout << "$" << this->price << " - This volleyball is made of " << this->material << " and is " << this->size << endl;
}