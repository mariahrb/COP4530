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
    string category;
    double weight;
    bool packed;

public:
    PackingItem(string n = "", string c = "", double w = 0.0)
        : name(n), category(c), weight(w), packed(false) {}

    string getName() const { return name; }
    void setPacked(bool p) { packed = p; }
    bool isPacked() const { return packed; }

    friend ostream& operator<<(ostream& os, const PackingItem& item) {
        os << item.name << " (" << item.category << ") - " << item.weight << "kg";
        if (item.packed) os << " [PACKED]";
        return os;
    }
};

#endif