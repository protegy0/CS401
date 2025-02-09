#include "../include/SoccerballNet.h"
#include <iostream>
#include <string>
using namespace std;

SoccerballNet::SoccerballNet(int size, double price) : OutdoorItem(price){
    this->size = size;
    this->price = price;
}

void SoccerballNet::display() {
    cout << "$" << this->price << " - This soccerball net is " << this->size << " feet wide";
}