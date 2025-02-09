from project import *

def main():
    inventory = Inventory()
    
    vbCheap = Volleyball(5.99, "foam", "small")
    vbExpensive = Volleyball(20.99, "leather", "small")
    vbNetSmall = VolleyballNet(34.99, "indoor", "small")
    vbNetLarge = VolleyballNet(69.99, "indoor", "large")
    ttBall = TableTennisBall(0.99)
    ttPaddleBeginner = TableTennisPaddle(9.99, "beginner")
    ttPaddleIntermediate = TableTennisPaddle(29.99, "intermediate")
    ttPaddleExpert = TableTennisPaddle(69.99, "expert")
    ttTableStd = TableTennisTable(199.99, "plywood")
    ttTablePrem = TableTennisTable(349.99, "fiberglass")
    
    cTentCheap = CampingTent(49.99, "small", 1, "weak")
    cTentIntermediate = CampingTent(89.99, "small", 3, "intermediate")
    cTentExpensive = CampingTent(149.99, "medium", 6, "strong")
    cStoveCheap = CampingStove(59.99, 500, "small")
    cStoveExpensive = CampingStove(119.99, 1200, "medium")
    cBagCheap = CampingBag(15.99, "medium", 0.5)
    cBagIntermediate = CampingBag(30.99, "medium", 1.2)
    cBagExpensive = CampingBag(51.99, "medium", 2.2)
    sbCheap = Soccerball(6.99, "PVC")
    sbExpensive = Soccerball(24.99, "polyurethane")
    sbNetSmall = SoccerballNet(24.99, 8)
    sbNetMedium = SoccerballNet(32.99, 12)
    sbNetLarge = SoccerballNet(51.99, 24)
    
    inventory.addIndoorItem(vbCheap, "vb", 100)
    inventory.addIndoorItem(vbExpensive, "vb", 25)
    inventory.addIndoorItem(vbNetSmall, "vb", 10)
    inventory.addIndoorItem(vbNetLarge, "vb", 5)
    inventory.addIndoorItem(ttBall, "tt", 1000)
    inventory.addIndoorItem(ttPaddleBeginner, "tt", 150)
    inventory.addIndoorItem(ttPaddleIntermediate, "tt", 100)
    inventory.addIndoorItem(ttPaddleExpert, "tt", 50)
    inventory.addIndoorItem(ttTableStd, "tt", 30)
    inventory.addIndoorItem(ttTablePrem, "tt", 15)
    
    inventory.addOutdoorItem(cTentCheap, "c", 25)
    inventory.addOutdoorItem(cTentIntermediate, "c", 20)
    inventory.addOutdoorItem(cTentExpensive, "c", 20)
    inventory.addOutdoorItem(cStoveCheap, "c", 45)
    inventory.addOutdoorItem(cStoveExpensive, "c", 20)
    inventory.addOutdoorItem(cBagCheap, "c", 45)
    inventory.addOutdoorItem(cBagIntermediate, "c", 40)
    inventory.addOutdoorItem(cBagExpensive, "c", 30)
    inventory.addOutdoorItem(sbCheap, "s", 100)
    inventory.addOutdoorItem(sbExpensive, "s", 50)
    inventory.addOutdoorItem(sbNetSmall, "s", 30)
    inventory.addOutdoorItem(sbNetMedium, "s", 20)
    inventory.addOutdoorItem(sbNetLarge, "s", 10)
    
    
    
    run = True
    page = ""
    print("Welcome to our catalogue! Please choose a section to browse!")
    print("--------------------------------------------")
    while(run):
        run = False
        print("All Indoor items: 1")
        print("All outdoor Items: 2")
        print("Volleyball items: 3")
        print("Table tennis items: 4")
        print("Camping items: 5")
        print("Soccer items: 6")
        choiceForDisplay = int(input(""))
        match choiceForDisplay:
            case 1:
                print("\nINDOOR ITEMS\n--------------------------------------------\n")
                inventory.displayIndoorItems()
                page = "i"
            case 2:
                print("\nOUTDOOR ITEMS\n--------------------------------------------\n")
                inventory.displayOutdoorItems()
                page = "o"
            case 3:
                print("\nVOLLEYBALL ITEMS\n--------------------------------------------\n")
                inventory.displayVolleyballItems()
                page = "i"
            case 4:
                print("\nTABLE TENNIS ITEMS\n--------------------------------------------\n")
                inventory.displayTabletennisItems()
                page = "i"
            case 5:
                print("\nCAMPING ITEMS\n--------------------------------------------\n")
                inventory.displayCampingItems()
                page = "o"
            case 6: 
                print("\nSOCCER ITEMS\n--------------------------------------------\n")
                inventory.displaySoccerItems()
                page = "o"
            case _:
                print("\nNot an option, please choose again!")
                run = True
                continue
        print("--------------------------------------------")
        choiceForBuy = input("Would you like to buy something from this page? (Y/N): ")
        if (choiceForBuy.lower() == "y" or choiceForBuy.lower() == "yes"):
            id = int(input("Please enter the ID of the item you would like to purchase: "))
            inventory.buyItem(id, page)
        cont = input("Continue? (Y/N): ")
        if (cont.lower() == "y" or cont.lower() == "yes"):
            run = True
            






if __name__ == "__main__":
    main()