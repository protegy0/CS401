#include "../include/LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
    this->head = nullptr;
    this->count = 0;
}

Node* LinkedList::getHead() {
    return this->head;
}

void LinkedList::insertAtBeginning(Item* item, string type, int stock) {
    Node* newNode = new Node();
    this->count++;
    newNode->item = item;
    newNode->type = type;
    newNode->stock = stock;
    newNode->ID = this->count;
    newNode->next = this->head;
    this->head = newNode;
}

void LinkedList::insertAtEnd(Item* item, string type, int stock) {
    Node* newNode = new Node();
    this->count++;
    newNode->item = item;
    newNode->type = type;
    newNode->ID = this->count;
    newNode->stock = stock;
    newNode->next = nullptr;

    if (!this->head) {
        head = newNode;
        return;
    }

    Node* temp = this->head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

