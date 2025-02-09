#ifndef OUTDOORITEM_H
#define OUTDOORITEM_H    

#include <string>
#include "Item.h"

class OutdoorItem : public Item {
    public:
        OutdoorItem(double price);
        void display() override;
};

#endif