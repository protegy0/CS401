#ifndef VOLLEYBALLNET_H
#define VOLLEYBALLNET_H

#include "IndoorItem.h"
#include <string>
using namespace std;

class VolleyballNet : public IndoorItem {
    private:
        string type;
        string size;
    public:
        VolleyballNet(string type, string size, double price);
        void display() override;
};

#endif