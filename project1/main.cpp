// main.cpp
// Entry point of the Travel Packing Rotation System.
// Handles user interaction and menu navigation.
// Calls service-layer functions to perform operations.
// Contains no business logic or data structure implementation.

#include <iostream>
#include <string>
#include "services/PackingService.h"
#include "services/TripHistoryService.h"
#include "services/OutfitRotationService.h"

using namespace std;

// -------------------- PACKING MENU --------------------
void packingMenu(PackingService &packing) {
    int choice;
    string name;

    do {
        cout << "\n--- Packing List Menu ---\n";
        cout << "1. Add Item\n2. Remove Item\n3. Display Packing List\n0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Item name: ";
                getline(cin, name);
                packing.addItem(name);
                break;
            case 2:
                cout << "Item name to remove: ";
                getline(cin, name);
                packing.removeItem(name);
                break;
            case 3:
                packing.displayPackingList();
                break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}

// -------------------- TRIP HISTORY MENU --------------------
void tripMenu(TripHistoryService &trips) {
    int choice;
    string dest;

    do {
        cout << "\n--- Trip History Menu ---\n";
        cout << "1. Add Trip\n2. Display Forward\n3. Display Backward\n0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Destination: ";
                getline(cin, dest);
                trips.addTrip(dest);
                break;
            case 2:
                trips.displayTripsForward();
                break;
            case 3:
                trips.displayTripsBackward();
                break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}

// -------------------- OUTFIT ROTATION MENU --------------------
void outfitMenu(OutfitRotationService &outfits) {
    int choice;
    string name;

    do {
        cout << "\n--- Outfit Rotation Menu ---\n";
        cout << "1. Add Outfit\n2. Next Outfit\n3. Show Current Outfit\n0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Outfit name: ";
                getline(cin, name);
                outfits.addOutfit(name);
                break;
            case 2:
                outfits.nextOutfit();
                break;
            case 3:
                outfits.showCurrentOutfit();
                break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}

// -------------------- MAIN --------------------
int main() {
    PackingService packing;
    TripHistoryService trips;
    OutfitRotationService outfits;

    int choice;

    do {
        cout << "\n=== Travel Packing Rotation System ===\n";
        cout << "1. Packing List\n2. Trip History\n3. Outfit Rotation\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: packingMenu(packing); break;
            case 2: tripMenu(trips); break;
            case 3: outfitMenu(outfits); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}
