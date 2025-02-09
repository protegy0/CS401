#include "../include/Inventory.h"
#include <iostream>

Inventory::Inventory() {
    this->IndoorInventory = LinkedList();
    this->OutdoorInventory = LinkedList();

};


void Inventory::addIndoorItem(Item* item, string category) {
    this->IndoorInventory.insertAtBeginning(item, category);
}

void Inventory::addOutdoorItem(Item* item, string category) {
    this->OutdoorInventory.insertAtBeginning(item, category);
}

void Inventory::displayIndoorItems() {
    Node* node = IndoorInventory.getHead();
    while (node != nullptr) {
        node->item->display();
        node = node->next;
    }
}

void Inventory::displayOutdoorItems() {
    Node* node = OutdoorInventory.getHead();
    while (node != nullptr) {
        node->item->display();
        node = node->next;
    }
}

void Inventory::displayVolleyballItems() {
    Node* node = IndoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "vb") {
            node->item->display();
        }
        node = node->next;
    }
}

void Inventory::displayTabletennisItems() {
    Node* node = IndoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "tt") {
            node->item->display();
        }
        node = node->next;
    }
}

void Inventory::displayCampingItems() {
    Node* node = OutdoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "c") {
            node->item->display();
        }
        node = node->next;
    }
}

void Inventory::displaySoccerItems() {
    Node* node = OutdoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "s") {
            node->item->display();
        }
        node = node->next;
    }
}