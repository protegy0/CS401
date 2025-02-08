#ifndef TABLETENNISTABLE_H
#define TABLETENNISTABLE_H

#include "IndoorItem.h"
#include <string>
using namespace std;

class TableTennisTable : public IndoorItem {
    private: 
        string material;
    public:
        TableTennisTable(string material, double price);
        void display() override;
};

#endif