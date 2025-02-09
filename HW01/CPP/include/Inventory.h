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
        void addOutdoorItem(Item* item, string category);
        void addIndoorItem(Item* item, string category);
        void displayOutdoorItems();
        void displayIndoorItems();
        void displayVolleyballItems();
        void displayTabletennisItems();
        void displayCampingItems();
        void displaySoccerItems();
};

#endif