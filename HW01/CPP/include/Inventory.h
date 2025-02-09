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
        void addOutdoorItem(Item* item, string category, int stock);
        void addIndoorItem(Item* item, string category, int stock);
        void displayOutdoorItems();
        void displayIndoorItems();
        void displayVolleyballItems();
        void displayTabletennisItems();
        void displayCampingItems();
        void displaySoccerItems();
        void buyItem(int ID, string page);
};

#endif