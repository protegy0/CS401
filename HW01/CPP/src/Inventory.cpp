#include "../include/Inventory.h"
#include <iostream>
#include <iomanip>
#include <string>

Inventory::Inventory() {
    this->IndoorInventory = LinkedList();
    this->OutdoorInventory = LinkedList();
};


void Inventory::addIndoorItem(Item* item, string category, int stock) {
    this->IndoorInventory.insertAtBeginning(item, category, stock);
}

void Inventory::addOutdoorItem(Item* item, string category, int stock) {
    this->OutdoorInventory.insertAtBeginning(item, category, stock);
}

void Inventory::displayIndoorItems() {
    Node* node = IndoorInventory.getHead();

    while (node != nullptr) {
        cout << "ID: " << node->ID << " - ";
        node->item->display();
        cout << " - Current stock: " << node->stock << endl;
        node = node->next;
    }
}

void Inventory::displayOutdoorItems() {
    Node* node = OutdoorInventory.getHead();
    while (node != nullptr) {
        cout << "ID: " << node->ID << " - ";
        node->item->display();
        cout << " - Current stock: " << node->stock << endl;
        node = node->next;
    }
}

void Inventory::displayVolleyballItems() {
    Node* node = IndoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "vb") {
            cout << "ID: " << node->ID << " - ";
            node->item->display();
            cout << " - Current stock: " << node->stock << endl;
        }
        node = node->next;
    }
}

void Inventory::displayTabletennisItems() {
    Node* node = IndoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "tt") {
            cout << "ID: " << node->ID << " - ";
            node->item->display();
            cout << " - Current stock: " << node->stock << endl;
        }
        node = node->next;
    }
}

void Inventory::displayCampingItems() {
    Node* node = OutdoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "c") {
            cout << "ID: " << node->ID << " - ";
            node->item->display();
            cout << " - Current stock: " << node->stock << endl;
        }
        node = node->next;
    }
}

void Inventory::displaySoccerItems() {
    Node* node = OutdoorInventory.getHead();
    while (node != nullptr) {
        if (node->type == "s") {
            cout << "ID: " << node->ID << " - ";
            node->item->display();
            cout << " - Current stock: " << node->stock << endl;
        }
        node = node->next;
    }
}

void Inventory::buyItem(int ID, string page) {
    Node* node;
    if (page == "i") {
        node = IndoorInventory.getHead();
    } else {
        node = OutdoorInventory.getHead();
    }
    Item* item;
    while (node != nullptr) {
        if (node->ID == ID) {
            item = node->item;
            break;
        }
        node = node->next;
    }
    if (node == nullptr) {
        cout << "That item ID does not exist\n";
        return;
    }
    int amount;
    cout << "Please enter the amount you would like to purchase: ";
    cin >> amount;
    while (amount <= 0) {
        cout << "Please enter a number above zero: ";
        cin >> amount;
    }
    
    if (node->stock < amount) {
        cout << "There is not enough of that item to purchase " << amount << "!\n";
        return;
    }
    
    
    string choice;
    cout << fixed << setprecision(2) << "It will cost $" << (item->getPrice() * amount) << " to purchase. Are you sure? (Y/N): ";
    cin >> choice;
    if (choice == "Y" || choice == "y" || choice == "yes" || choice == "YES") {
        node->stock -= amount;
        cout << "Successfully purchased!" << endl;
    }
    

}