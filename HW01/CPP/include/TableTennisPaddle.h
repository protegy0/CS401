#ifndef TABLETENNISPADDLE_H
#define TABLETENNISPADDLE_H

#include "IndoorItem.h"
#include <string>
using namespace std;

class TableTennisPaddle : public IndoorItem {
    private: 
        string style;
    public:
        TableTennisPaddle(string style, double price);
        void display() override;
};

#endif