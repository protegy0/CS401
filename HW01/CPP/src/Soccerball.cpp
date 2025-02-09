#include "../include/Soccerball.h"
#include <iostream>
#include <string>
using namespace std;

Soccerball::Soccerball(string material, double price) : OutdoorItem(price){
    this->material = material;
    this->price = price;
}

void Soccerball::display() {
    cout << "$" << this->price << " - This soccerball is made of " << this->material;
}