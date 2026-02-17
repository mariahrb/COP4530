#include "TripHistoryService.h"
#include <iostream>
using namespace std;

void TripHistoryService::addTrip(string destination) {
    TripRecord trip(destination);   
    tripHistory.insertAtEnd(trip);
    cout << "Trip added.\n";
}

void TripHistoryService::displayTripsForward() const {
    tripHistory.displayForward();
}

void TripHistoryService::displayTripsBackward() const {
    tripHistory.displayBackward();
}
