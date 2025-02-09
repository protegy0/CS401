#ifndef ITEM_H
#define ITEM_H    


class Item {
    protected:
        double price;
    public:
        Item(double price);
        virtual void display();
        virtual ~Item();
        double getPrice();
};

#endif