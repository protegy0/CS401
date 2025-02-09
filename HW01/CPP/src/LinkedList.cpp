#include "../include/LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
    this->head = nullptr;
}

Node* LinkedList::getHead() {
    return this->head;
}

void LinkedList::insertAtBeginning(Item* item, string type) {
    Node* newNode = new Node();
    newNode->item = item;
    newNode->type = type;
    newNode->next = this->head;
    this->head = newNode;
}

void LinkedList::insertAtEnd(Item* item, string type) {
    Node* newNode = new Node();
    newNode->item = item;
    newNode->type = type;
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