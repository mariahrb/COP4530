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
    do {
        cout << "\n--- Packing List Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Mark Item as Packed\n";
        cout << "4. Display Packing List\n";
        cout << "5. Clear Packing List\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // flush newline

        string name, category;
        double weight;

        switch(choice) {
            case 1:
                cout << "Enter item name: ";
                getline(cin, name);
                cout << "Enter category: ";
                getline(cin, category);
                cout << "Enter weight: ";
                cin >> weight;
                cin.ignore(); // ADD THIS LINE - flush newline after cin >> weight
                packing.addItem(name, category, weight);
                cout << "Item added successfully!\n";
                break;
            case 2:
                cout << "Enter item name to remove: ";
                getline(cin, name);
                packing.removeItem(name);
                break;
            case 3:
                cout << "Enter item name to mark as packed: ";
                getline(cin, name);
                packing.markItemPacked(name);
                break;
            case 4:
                packing.displayPackingList();
                break;
            case 5:
                packing.clearPackingList();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);
}

// -------------------- TRIP HISTORY MENU --------------------
void tripMenu(TripHistoryService &trips) {
    int choice;
    do {
        cout << "\n--- Trip History Menu ---\n";
        cout << "1. Add Trip\n";
        cout << "2. Remove Last Trip\n";
        cout << "3. Display Trips Forward\n";
        cout << "4. Display Trips Backward\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        string dest, start, end;
        int total;

        switch(choice) {
            case 1:
                cout << "Enter destination: ";
                getline(cin, dest);
                cout << "Enter start date (YYYY-MM-DD): ";
                getline(cin, start);
                cout << "Enter end date (YYYY-MM-DD): ";
                getline(cin, end);
                cout << "Enter total items packed: ";
                cin >> total;
                cin.ignore();
                trips.addTrip(dest, start, end, total);
                cout << "Trip added successfully!\n";
                break;
            case 2:
                trips.removeLastTrip();
                break;
            case 3:
                trips.displayTripsForward();
                break;
            case 4:
                trips.displayTripsBackward();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);
}

// -------------------- OUTFIT ROTATION MENU --------------------
void outfitMenu(OutfitRotationService &outfits) {
    int choice;
    do {
        cout << "\n--- Outfit Rotation Menu ---\n";
        cout << "1. Add Outfit\n";
        cout << "2. Remove Current Outfit\n";
        cout << "3. Next Outfit\n";
        cout << "4. Show Current Outfit\n";
        cout << "5. Display All Outfits\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        string name, occasion, weather;

        switch(choice) {
            case 1:
                cout << "Enter outfit name: ";
                getline(cin, name);
                cout << "Enter occasion: ";
                getline(cin, occasion);
                cout << "Enter weather type: ";
                getline(cin, weather);
                outfits.addOutfit(name, occasion, weather);
                break;
            case 2:
                outfits.removeCurrentOutfit();
                break;
            case 3:
                outfits.nextOutfit();
                break;
            case 4:
                outfits.showCurrentOutfit();
                break;
            case 5:
                outfits.displayAllOutfits();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);
}

// -------------------- MAIN MENU --------------------
int main() {
    PackingService packing;
    TripHistoryService trips;
    OutfitRotationService outfits;

    int choice;

    do {
        cout << "\n=== TRAVEL PACKING ROTATION SYSTEM ===\n";
        cout << "1. Manage Packing List\n";
        cout << "2. Manage Trip History\n";
        cout << "3. Manage Outfit Rotation\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                packingMenu(packing);
                break;
            case 2:
                tripMenu(trips);
                break;
            case 3:
                outfitMenu(outfits);
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}
