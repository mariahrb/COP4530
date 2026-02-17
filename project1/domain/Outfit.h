// Outfit.h
// Defines the Outfit class.
// Represents a clothing combination used for trip outfit rotation.
// Used inside the CircularLinkedList to rotate outfits daily.

#ifndef OUTFIT_H
#define OUTFIT_H

#include <iostream>
#include <string>
using namespace std;

class Outfit {
private:
    string name;

public:
    Outfit(string n = "") : name(n) {}

    string getName() const {
        return name;
    }

    friend ostream& operator<<(ostream& os, const Outfit& outfit) {
        os << outfit.name;
        return os;
    }
};

#endif
