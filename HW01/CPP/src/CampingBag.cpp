#include "../include/CampingBag.h"
#include <iostream>
#include <string>
using namespace std;

CampingBag::CampingBag(string size, double thickness, double price) : OutdoorItem(price){
    this->size = size;
    this->thickness = thickness;
    this->price = price;
}

void CampingBag::display() {
    cout << "$" << this->price << " - This camping bag is size " << this->size << " and has a thickness of " << this->thickness << " inches";
}