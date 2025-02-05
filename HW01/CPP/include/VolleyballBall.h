#ifndef VOLLEYBALLBALL_H
#define VOLLEYBALLBALL_H

#include "Volleyball.h"
#include <string>
using namespace std;

class VolleyballBall : public Volleyball {
    private:
        string material;
        string size;

    public:
        VolleyballBall(string material, string size, double price);
        void display();
};

#endif