#ifndef VOLLEYBALL_H
#define VOLLEYBALL_H

#include "IndoorItem.h"
#include <string>
using namespace std;

class Volleyball : public IndoorItem {
    private:
        string material;
        string size;
    public:
        Volleyball(string material, string size, double price);
        void display() override;
};

#endif