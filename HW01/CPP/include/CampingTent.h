#ifndef CAMPINGTENT_H
#define CAMPINGTENT_H

#include "OutdoorItem.h"
#include <string>
using namespace std;

class CampingTent : public OutdoorItem {
    private:
        string size;
        int durability;
        string rating;
    public:
        CampingTent(string size, int durability, string rating, double price);
        void display() override;
};

#endif