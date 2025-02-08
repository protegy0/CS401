#ifndef CAMPINGSTOVE_H
#define CAMPINGSTOVE_H

#include "OutdoorItem.h"
#include <string>
using namespace std;

class CampingStove : public OutdoorItem {
    private:
        string size;
        int wattage;
    public:
        CampingStove(string size, int wattage, double price);
        void display() override;
};

#endif