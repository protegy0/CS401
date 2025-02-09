#include <iostream>
#include "project.h"
using namespace std;


int main() {
    Inventory inventory;


    // Indoor items declaration
    Item* vbCheap = new Volleyball("foam", "small", 5.99);
    Item* vbExpensive = new Volleyball("leather", "small", 20.99);
    Item* vbNetSmall = new VolleyballNet("indoor", "small", 34.99);
    Item* vbNetLarge = new VolleyballNet("indoor", "large", 69.99);
    Item* ttBall = new TableTennisBall(0.99);
    Item* ttPaddleBeginner = new TableTennisPaddle("beginner", 9.99);
    Item* ttPaddleIntermediate = new TableTennisPaddle("intermediate", 29.99);
    Item* ttPaddleExpert = new TableTennisPaddle("expert", 69.99);
    Item* ttTableStd = new TableTennisTable("plywood", 199.99);
    Item* ttTablePrem = new TableTennisTable("fiberglass", 349.99);
    
    // Outdoor items declaration
    Item* cTentCheap = new CampingTent("small", 1, "weak", 49.99);
    Item* cTentIntermediate = new CampingTent("small", 3, "intermediate", 89.99);
    Item* cTentExpensive = new CampingTent("medium", 6, "strong", 149.99);
    Item* cStoveCheap = new CampingStove("small", 500, 59.99);
    Item* cStoveExpensive = new CampingStove("medium", 1200, 119.99);
    Item* cBagCheap = new CampingBag("medium", 0.5, 15.99);
    Item* cBagIntermediate = new CampingBag("medium", 1.2, 30.99);
    Item* cBagExpensive = new CampingBag("medium", 2.2, 51.99);
    Item* sbCheap = new Soccerball("PVC", 6.99);
    Item* sbExpensive = new Soccerball("polyurethane", 20.99);
    Item* sbNetSmall = new SoccerballNet(8, 24.99);
    Item* sbNetMedium = new SoccerballNet(12, 32.99);
    Item* sbNetLarge = new SoccerballNet(24, 51.99);

    // Adding indoor items to inventory object
    inventory.addIndoorItem(vbCheap, "vb");
    inventory.addIndoorItem(vbExpensive, "vb");
    inventory.addIndoorItem(vbNetSmall, "vb");
    inventory.addIndoorItem(vbNetLarge, "vb");
    inventory.addIndoorItem(ttBall, "tt");
    inventory.addIndoorItem(ttPaddleBeginner, "tt");
    inventory.addIndoorItem(ttPaddleIntermediate, "tt");
    inventory.addIndoorItem(ttPaddleExpert, "tt");
    inventory.addIndoorItem(ttTableStd, "tt");
    inventory.addIndoorItem(ttTablePrem, "tt");

    // Adding outdoor items to inventory object
    inventory.addOutdoorItem(cTentCheap, "c");
    inventory.addOutdoorItem(cTentIntermediate, "c");
    inventory.addOutdoorItem(cTentExpensive, "c");
    inventory.addOutdoorItem(cStoveCheap, "c");
    inventory.addOutdoorItem(cStoveExpensive, "c");
    inventory.addOutdoorItem(cBagCheap, "c");
    inventory.addOutdoorItem(cBagIntermediate, "c");
    inventory.addOutdoorItem(cBagExpensive, "c");
    inventory.addOutdoorItem(sbCheap, "s");
    inventory.addOutdoorItem(sbExpensive, "s");
    inventory.addOutdoorItem(sbNetSmall, "s");
    inventory.addOutdoorItem(sbNetMedium, "s");
    inventory.addOutdoorItem(sbNetLarge, "s");
    






    bool run = true;
    int choice;
    string cont;

    while (run) {
        cout << "Display all indoor items: 1" << endl;
        cout << "Display all outdoor items: 2" << endl;
        cout << "Display only volleyball items: 3" << endl;
        cout << "Display only table tennis items: 4" << endl;
        cout << "Display only camping items: 5" << endl;
        cout << "Display only soccer items: 6" << endl;  
        cin >> choice;
        switch (choice) {
            case 1:
                inventory.displayIndoorItems();
                break;
            case 2:
                inventory.displayOutdoorItems();
                break;
            case 3: 
                inventory.displayVolleyballItems();
                break;
            case 4:
                inventory.displayTabletennisItems();
                break;
            case 5:
                inventory.displayCampingItems();
                break;
            case 6: 
                inventory.displaySoccerItems();
                break;
            default:
                cout << "Not an option. please choose again.";
                continue;
        }
        cout << "Continue? (Y/N): ";
        cin >> cont;
        if (cont == "N" || cont == "no" || cont == "n" || cont == "NO") {
            run = false;
        }
    }

    delete vbCheap;
    delete vbExpensive;
    delete vbNetSmall;
    delete vbNetLarge;
    delete ttBall;
    delete ttPaddleBeginner;
    delete ttPaddleIntermediate;
    delete ttPaddleExpert;
    delete ttTableStd;
    delete ttTablePrem;
    delete cTentCheap;
    delete cTentIntermediate;
    delete cTentExpensive;
    delete cStoveCheap;
    delete cStoveExpensive;
    delete cBagCheap;
    delete cBagIntermediate;
    delete cBagExpensive;
    delete sbCheap;
    delete sbExpensive;
    delete sbNetSmall;
    delete sbNetMedium;
    delete sbNetLarge;

    
    return 0;
}