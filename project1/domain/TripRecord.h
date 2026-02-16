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
    string startDate;
    string endDate;
    int itemsPacked;

public:
    TripRecord(string dest = "", string start = "", string end = "", int items = 0)
        : destination(dest), startDate(start), endDate(end), itemsPacked(items) {}

    // Getters
    string getDestination() const { return destination; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
    int getItemsPacked() const { return itemsPacked; }

    // Setters
    void setDestination(const string& dest) { destination = dest; }
    void setStartDate(const string& start) { startDate = start; }
    void setEndDate(const string& end) { endDate = end; }
    void setItemsPacked(int items) { itemsPacked = items; }
    void incrementItemsPacked(int n = 1) { itemsPacked += n; }

    // Output
    friend ostream& operator<<(ostream& os, const TripRecord& trip) {
        os << trip.destination << " (" << trip.startDate << " to " << trip.endDate 
           << ") - " << trip.itemsPacked << " items";
        return os;
    }
};

#endif
