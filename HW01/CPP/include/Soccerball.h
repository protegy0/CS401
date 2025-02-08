#ifndef SOCCERBALL_H
#define SOCCERBALL_H

#include "OutdoorItem.h"
#include <string>
using namespace std;

class Soccerball : public OutdoorItem {
    private:
        string material;
        
    public:
        Soccerball(string material, double price);
        void display() override;
};

#endif