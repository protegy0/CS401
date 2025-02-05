#ifndef VOLLEYBALLNET_H
#define VOLLEYBALLNET_H

#include "Volleyball.h"
#include <string>
using namespace std;

class VolleyballNet : public Volleyball {
    private:
        string type;
        string size;
    public:
        VolleyballNet(string type, string size, double price);
        void display();
};

#endif