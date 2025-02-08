#include "../include/CampingTent.h"
#include <iostream>
#include <string>
using namespace std;

CampingTent::CampingTent(string size, int durability, string rating, double price) : OutdoorItem(price){
    this->size = size;
    this->durability = durability;
    this->rating = rating;
    this->price = price;
}

void CampingTent::display() {
    cout << "$" << this->price << " - This camping tent is size " << this->size << " and has a durability rated for " << this->durability << " years. It is also rated for "  << this->rating << " winds and rains" << endl;
}