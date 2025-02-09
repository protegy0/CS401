#include "../include/TableTennisPaddle.h"
#include <iostream>
#include <string>
using namespace std;

TableTennisPaddle::TableTennisPaddle(string style, double price) : IndoorItem(price){
    this->style = style;
    this->price = price;
}

void TableTennisPaddle::display() {
    cout << "$" << this->price << " - This table tennis paddle is for " << this->style << endl;
}