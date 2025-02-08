#include <iostream>
#include "Volleyball.h"
using namespace std;


int main() {
    Item* v = new Volleyball("nylon", "medium", 4.99);
    v->display();
    return 0;
}