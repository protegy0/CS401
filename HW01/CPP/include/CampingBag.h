#ifndef CAMPINGBAG_H
#define CAMPINGBAG_H

#include "OutdoorItem.h"
#include <string>
using namespace std;

class CampingBag : public OutdoorItem {
    private:
        string size;
        int thickness;
    public:
        CampingBag(string size, int thickness, double price);
        void display() override;
};

#endif