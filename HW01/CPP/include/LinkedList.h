#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"
#include <string>
using namespace std;


struct Node {
    Item* item;
    string type;
    int stock;
    Node* next;
    Node* prev;
    int ID;
};

class LinkedList {
    Node* head;
    int count;
    public:
        LinkedList();
        void insertAtBeginning(Item* item, string type, int stock);
        void insertAtEnd(Item* item, string type, int stock);
        void display();
        Node* getHead();

};

#endif