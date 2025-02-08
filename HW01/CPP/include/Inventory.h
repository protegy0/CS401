#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "LinkedList.h"

class Inventory {
    private:
        LinkedList OutdoorInventory;
        LinkedList IndoorInventory;
    public:
        Inventory();
        void addOutdoorItem(Item item, string type);
        void addIndoorItem(Item item, string type);
        void displayOutdoorItems();
        void displayIndoorItems();
};

#endif