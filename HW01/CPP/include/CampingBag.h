#ifndef CAMPINGBAG_H
#define CAMPINGBAG_H

#include "OutdoorItem.h"
#include <string>
using namespace std;

class CampingBag : public OutdoorItem {
    private:
        string size;
        double thickness;
    public:
        CampingBag(string size, double thickness, double price);
        void display() override;
};

#endif