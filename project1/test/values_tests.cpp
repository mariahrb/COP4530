#include <iostream>
#include "../services/PackingService.h"
#include "../services/TripHistoryService.h"
#include "../services/OutfitRotationService.h"

using namespace std;

// ---------------- PACKING SERVICE TEST ----------------
void testPackingService() {
    cout << "\n=== Testing PackingService (Values) ===\n";
    PackingService packing;

    // Add items (name only in simplified version)
    packing.addItem("T-Shirt");
    packing.addItem("Laptop");
    packing.addItem("Toothbrush");

    cout << "\nPacking list after adding 3 items:\n";
    packing.displayPackingList();

    // Remove an item
    packing.removeItem("Toothbrush");
    cout << "\nAfter removing Toothbrush:\n";
    packing.displayPackingList();
}

// ---------------- TRIP HISTORY TEST ----------------
void testTripHistoryService() {
    cout << "\n=== Testing TripHistoryService (Values) ===\n";
    TripHistoryService trips;

    // Add trips (destination only in simplified version)
    trips.addTrip("Paris");
    trips.addTrip("Tokyo");

    cout << "\nTrip history forward:\n";
    trips.displayTripsForward();

    cout << "\nTrip history backward:\n";
    trips.displayTripsBackward();
}

// ---------------- OUTFIT ROTATION TEST ----------------
void testOutfitRotationService() {
    cout << "\n=== Testing OutfitRotationService (Values) ===\n";
    OutfitRotationService outfits;

    // Add outfits (name only)
    outfits.addOutfit("Casual Jeans");
    outfits.addOutfit("Formal Suit");
    outfits.addOutfit("Beach Shorts");

    cout << "\nShow current outfit (expected Casual Jeans):\n";
    outfits.showCurrentOutfit();

    // Rotate
    outfits.nextOutfit();
    cout << "After next outfit (expected Formal Suit):\n";
    outfits.showCurrentOutfit();

    outfits.nextOutfit();
    cout << "After next outfit (expected Beach Shorts):\n";
    outfits.showCurrentOutfit();

    outfits.nextOutfit();
    cout << "After next outfit (expected Casual Jeans again - circular):\n";
    outfits.showCurrentOutfit();
}

int main() {
    cout << "=== VALUES TESTS FOR TRAVEL PACKING ROTATION SYSTEM ===\n";

    testPackingService();
    testTripHistoryService();
    testOutfitRotationService();

    cout << "\n=== VALUES TESTS COMPLETED ===\n";
    return 0;
}
