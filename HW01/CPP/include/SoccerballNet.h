#ifndef SOCCERBALLNET_H
#define SOCCERBALLNET_H

#include "OutdoorItem.h"
#include <string>
using namespace std;

class SoccerballNet : public OutdoorItem {
    private:
        int size;
    public:
        SoccerballNet(int size, double price);
        void display() override;
};

#endif