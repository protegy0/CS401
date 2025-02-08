#ifndef INDOORITEM_H
#define INDOORITEM_H    

#include <string>
#include "Item.h"

class IndoorItem : public Item {
    protected:
        double price;
    public:
        IndoorItem(double price);
        virtual void display();
};

#endif