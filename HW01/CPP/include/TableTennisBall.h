#ifndef TABLETENNISBALL_H
#define TABLETENNISBALL_H

#include "IndoorItem.h"
#include <string>
using namespace std;

class TableTennisBall : public IndoorItem {
    public:
        TableTennisBall(double price);
        void display() override;
};

#endif