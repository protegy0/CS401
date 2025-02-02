#include <iostream>
using namespace std;

class ArrayStack {
    public:
        int size;
        char* charArr;
        int top;

        ArrayStack(int sizeOfStack) {
            charArr = new char[sizeOfStack];
            size = sizeOfStack;
            top = -1;
        }

        void push(char c) {
            if (top == size - 1) {
                cout << "Stack is full";
            } else {
                top++;
                charArr[top] = c;
            }
        }

        char pop() {
            if (top == -1) {
                cout << "Stack is empty. Returned zero.\n";
                return '0';
            } else {
                char temp = charArr[top];
                top--;
                return temp;
            }
        }

        bool isEmpty() {
            return top == -1;
        }

};

class Node {
    public:
        char value;
        Node* next;

        Node(char c) {
            value = c;
            next = nullptr;
        }

};

class LinkedListStack {
    public:
        Node* head;
        int size;

        LinkedListStack() {
            head = nullptr;
            size = 0;
        }

        bool isEmpty() {
            return size == 0;
        }

        void push(char c) {
            Node newNode(c);
            Node* node = &newNode;
            if (head != nullptr) {
                newNode.next = head;
            }
            head = node;
            size++;
        }

        char pop() {
            if (this->isEmpty()) {
                cout << "Stack is empty. Returned zero.\n";
                return '0';
            }
            Node* poppedNode = head;
            head = head->next;
            size--;
            return poppedNode->value;
        }
};

string balancedStringWithArray(string s) {
    ArrayStack stk(s.size());
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        }
        if (c == ')' || c == ']' || c == '}') {
            if (stk.isEmpty()) {
                break;
            }
            char check = stk.pop();
        }
    }
    if (stk.isEmpty()) {
        return "This string is balanced.";
    } else {
        return "This string is unbalanced.";
    }
}
string balancedStringWithLL(string s) {
    LinkedListStack stk;
     
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        }
        if (c == ')' || c == ']' || c == '}') {
            if (stk.isEmpty()) {
                break;
            }
            char check = stk.pop();
        }
    }
    if (stk.isEmpty()) {
        return "This string is balanced.";
    } else {
        return "This string is unbalanced.";
    }
}



int main() {

    string s1 = "a + (b * [c - d])";
    string s2 = "a + (b * [c - d)";
    string s3 = "(";

    cout << s1 << endl << "Array stack string parsing: " << balancedStringWithArray(s1) << endl << "Linked List stack string parsing: " << balancedStringWithLL(s1) << endl;
    cout << s2 << endl << "Array stack string parsing: " << balancedStringWithArray(s2) << endl << "Linked List stack string parsing: " << balancedStringWithLL(s2) << endl;
    cout << s3 << endl << "Array stack string parsing: " << balancedStringWithArray(s3) << endl << "Linked List stack string parsing: " << balancedStringWithLL(s3) << endl;


    


    return 0;
}