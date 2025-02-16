#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Node for standard queue implementation
class Node {
    public:
        int value;
        Node* next;

        Node(int c) {
            value = c;
            next = nullptr;
        }

};

class Queue {
    Node *start, *end;

    public:
    // Initialize queue with no start or end
        Queue() {
            start = nullptr;
            end = nullptr;
        }

        bool isEmpty() {
            if (start == nullptr) {
                return true;
            }
            return false;
        }

        void enqueue(int value) {
            Node* node = new Node(value);

            if (this->isEmpty()) {
                start = node;
                end = node;
                return;
            }

            end->next = node;
            end = node;
        }

        void dequeue() {

            if (this->isEmpty()) {
                cout << "This queue is empty!\n";
                return;
            }

            Node* temp = start;
            start = start->next;

            if (start == nullptr) {
                end = nullptr;
            }

            delete temp;

        }

        int front() {
            if (this->isEmpty()) {
                cout << "This queue is empty!\n";
                return -1;
            }
            return start->value;
        }

};

// Special node to handle string and character indexes
class StringNode {
    public:
        char c;
        int index;
        StringNode* next;

        StringNode(char c, int index) {
            this->c = c;
            this->index = index;
            next = nullptr;
        }

};

class StringQueue {
    StringNode *start, *end;

    public:
        StringQueue() {
            start = nullptr;
            end = nullptr;
        }

        bool isEmpty() {
            if (start == nullptr) {
                return true;
            }
            return false;
        }

        void enqueue(char c, int index) {
            StringNode* node = new StringNode(c, index);

            if (this->isEmpty()) {
                start = node;
                end = node;
                return;
            }

            end->next = node;
            end = node;
        }

        void dequeue() {

            if (this->isEmpty()) {
                cout << "This queue is empty!\n";
                return;
            }

            StringNode* temp = start;
            start = start->next;

            if (start == nullptr) {
                end = nullptr;
            }

            delete temp;

        }

        char getFrontChar() {
            if (this->isEmpty()) {
                cout << "This queue is empty!\n";
                return -1;
            }
            return start->c;
        }

        int getFrontIndex() {
            if (this->isEmpty()) {
                cout << "This queue is empty!\n";
                return -1;
            }
            return start->index;
        }

};



int firstRepeatingCharacter(string s) {
    StringQueue q; // Initialize queue to hold characters in string
    unordered_map<char, int> count; // Initialize map to hold number of occurences of each character in string

    for (int i = 0; i < s.length(); i++) { // Loop to add all characters to queue and map
        count[s[i]]++;
        q.enqueue(s[i], i);

        while (!q.isEmpty() && count[q.getFrontChar()] > 1) { // If a character appears more than once in the string, remove it from the queue
            q.dequeue();
        }
    }

    return q.isEmpty() ? -1 : q.getFrontIndex(); // If queue is empty, return -1 as there are no unique characters. Otherwise, return the front of the queue.
}



int main() {
    
    Queue queue;

    queue.enqueue(7);
    
    
    cout << "Queue front: " << queue.front() << endl;

    queue.dequeue();
    queue.enqueue(72);

    cout << "Queue front: " << queue.front() << endl;
    


    string s = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    cout << "leetcode: " << firstRepeatingCharacter(s) << endl;
    cout << "loveleetcode: " << firstRepeatingCharacter(s2) << endl;
    cout << "aabb: " << firstRepeatingCharacter(s3) << endl;

    return 0;
}