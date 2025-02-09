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
    inventory.addIndoorItem(vbCheap, "vb", 100);
    inventory.addIndoorItem(vbExpensive, "vb", 25);
    inventory.addIndoorItem(vbNetSmall, "vb", 10);
    inventory.addIndoorItem(vbNetLarge, "vb", 5);
    inventory.addIndoorItem(ttBall, "tt", 1000);
    inventory.addIndoorItem(ttPaddleBeginner, "tt", 150);
    inventory.addIndoorItem(ttPaddleIntermediate, "tt", 100);
    inventory.addIndoorItem(ttPaddleExpert, "tt", 50);
    inventory.addIndoorItem(ttTableStd, "tt", 30);
    inventory.addIndoorItem(ttTablePrem, "tt", 15);

    // Adding outdoor items to inventory object
    inventory.addOutdoorItem(cTentCheap, "c", 25);
    inventory.addOutdoorItem(cTentIntermediate, "c", 20);
    inventory.addOutdoorItem(cTentExpensive, "c", 20);
    inventory.addOutdoorItem(cStoveCheap, "c", 45);
    inventory.addOutdoorItem(cStoveExpensive, "c", 20);
    inventory.addOutdoorItem(cBagCheap, "c", 45);
    inventory.addOutdoorItem(cBagIntermediate, "c", 40);
    inventory.addOutdoorItem(cBagExpensive, "c", 30);
    inventory.addOutdoorItem(sbCheap, "s", 100);
    inventory.addOutdoorItem(sbExpensive, "s", 50);
    inventory.addOutdoorItem(sbNetSmall, "s", 30);
    inventory.addOutdoorItem(sbNetMedium, "s", 20);
    inventory.addOutdoorItem(sbNetLarge, "s", 10);
    






    bool run = true;
    int choiceForDisplay;
    string choiceForBuy;
    string cont;
    string page;
    cout << "Welcome to our catalogue! Please choose a section to browse!";
    cout << endl << "--------------------------------------------" << endl;
    while (run) {
        run = false;
        cout << "All Indoor items: 1" << endl;
        cout << "All Outdoor items: 2" << endl;
        cout << "Volleyball items: 3" << endl;
        cout << "Table tennis items: 4" << endl;
        cout << "Camping items: 5" << endl;
        cout << "Soccer items: 6" << endl;
        start:  
        cin >> choiceForDisplay;
        switch (choiceForDisplay) {
            case 1:
                cout << endl << "INDOOR ITEMS" << endl << "--------------------------------------------" << endl;
                inventory.displayIndoorItems();
                page = "i";
                break;
            case 2:
            cout << endl << "OUTDOOR ITEMS" << endl << "--------------------------------------------" << endl;
                inventory.displayOutdoorItems();
                page = "o";
                break;
            case 3: 
                cout << endl << "VOLLEYBALL ITEMS" << endl << "--------------------------------------------" << endl;
                inventory.displayVolleyballItems();
                page = "i";
                break;
            case 4:
                cout << endl << "TABLE TENNIS ITEMS" << endl << "--------------------------------------------" << endl;
                inventory.displayTabletennisItems();
                page = "i";
                break;
            case 5:
                cout << endl << "CAMPING ITEMS" << endl << "--------------------------------------------" << endl;
                inventory.displayCampingItems();
                page = "o";
                break;
            case 6:
                cout << endl << "SOCCER ITEMS" << endl << "--------------------------------------------" << endl; 
                inventory.displaySoccerItems();
                page = "o";
                break;
            default:
                cout << endl << "Not an option. please choose again!" << endl;
                goto start;
        }
        cout << "--------------------------------------------" << endl;
        cout << "Would you like to buy something from this page? (Y/N): ";
        cin >> choiceForBuy;
        if (choiceForBuy == "Y" || choiceForBuy == "yes" || choiceForBuy == "y" || choiceForBuy == "YES") {
            int ID;
            cout << "Please enter the ID of the item you would like to purchase: ";
            cin >> ID;
            inventory.buyItem(ID, page);
        } 
        cout << "Continue? (Y/N): ";
        cin >> cont;
        if (cont == "Y" || cont == "yes" || cont == "y" || cont == "YES") {
            run = true;
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