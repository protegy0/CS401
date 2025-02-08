#include "../include/Inventory.h"
#include <iostream>

Inventory::Inventory() {
    this->IndoorInventory = LinkedList();
    this->OutdoorInventory = LinkedList();

};


void Inventory::addIndoorItem(Item item, string type) {
    this->IndoorInventory.insertAtBeginning(item, type);
}

void Inventory::addOutdoorItem(Item item, string type) {
    this->OutdoorInventory.insertAtBeginning(item, type);
}

void Inventory::displayIndoorItems() {
    Node* node = IndoorInventory.getHead();

    while (node != nullptr) {
        if (node->type == "indoor") {
            node->item.display();
        }
    }
}

void Inventory::displayOutdoorItems() {
    Node* node = OutdoorInventory.getHead();

    while (node != nullptr) {
        if (node->type == "outdoor") {
            node->item.display();
        }
    }
}