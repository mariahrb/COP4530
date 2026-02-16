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
    string type;
    string weather;

public:
    Outfit(string n = "", string t = "", string w = "")
        : name(n), type(t), weather(w) {}

    // Getters
    string getName() const { return name; }
    string getType() const { return type; }
    string getWeather() const { return weather; }

    // Setters (optional)
    void setName(const string& n) { name = n; }
    void setType(const string& t) { type = t; }
    void setWeather(const string& w) { weather = w; }

    // Display method
    void display() const {
        cout << name << " (" << type << " for " << weather << " weather)";
    }

    // Output stream
    friend ostream& operator<<(ostream& os, const Outfit& outfit) {
        os << outfit.name << " (" << outfit.type << " for " << outfit.weather << " weather)";
        return os;
    }
};

#endif
