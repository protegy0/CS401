#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"
#include <string>
using namespace std;


struct Node {
    Item item;
    string type;
    Node* next;
    Node* prev;
};

class LinkedList {
    Node* head;
    public:
        LinkedList();
        void insertAtBeginning(Item item, string type);
        void insertAtEnd(Item item, string type);
        void display();
        Node* getHead();
};

#endif