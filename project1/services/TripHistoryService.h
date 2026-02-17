// TripHistoryService.h
// Manages past trip records.
// Uses DoublyLinkedList<TripRecord> internally.
// Allows navigation through previous trips.

#ifndef TRIPHISTORYSERVICE_H
#define TRIPHISTORYSERVICE_H

#include <string>
#include "../structures/DoublyLinkedList.h"
#include "../domain/TripRecord.h"
using namespace std;

class TripHistoryService {
private:
    DoublyLinkedList<TripRecord> tripHistory;

public:
    void addTrip(string destination);
    void displayTripsForward() const;
    void displayTripsBackward() const;
};

#endif
