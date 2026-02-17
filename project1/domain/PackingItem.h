// PackingItem.h
// Defines the PackingItem class.
// Represents an item that a user plans to pack for a trip.
// Used inside the SinglyLinkedList for current packing list management.

#ifndef PACKINGITEM_H
#define PACKINGITEM_H

#include <iostream>
#include <string>
using namespace std;

class PackingItem {
private:
    string name;

public:
    PackingItem(string n = "") : name(n) {}

    string getName() const {
        return name;
    }

    friend ostream& operator<<(ostream& os, const PackingItem& item) {
        os << item.name;
        return os;
    }
};

#endif
