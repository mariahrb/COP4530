// TripRecord.h
// Defines the TripRecord class.
// Represents a completed trip and its associated packing summary.
// Used inside the DoublyLinkedList for trip history navigation.

#ifndef TRIPRECORD_H
#define TRIPRECORD_H

#include <iostream>
#include <string>
using namespace std;

class TripRecord {
private:
    string destination;

public:
    TripRecord(string dest = "") : destination(dest) {}

    string getDestination() const {
        return destination;
    }

    friend ostream& operator<<(ostream& os, const TripRecord& trip) {
        os << trip.destination;
        return os;
    }
};

#endif
