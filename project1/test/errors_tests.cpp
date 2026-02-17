#include <iostream>
#include "../services/PackingService.h"
#include "../services/TripHistoryService.h"
#include "../services/OutfitRotationService.h"

using namespace std;

// ---------------- PACKING ERROR TESTS ----------------
void testPackingErrors() {
    cout << "\n=== Testing PackingService (Errors) ===\n";
    PackingService packing;

    // Remove non-existent item
    packing.removeItem("NonExistent");
    cout << "Attempted to remove non-existent item (should handle gracefully)\n";

    // Display empty list
    packing.displayPackingList();
    cout << "Displayed empty packing list (should not crash)\n";
}

// ---------------- TRIP HISTORY ERROR TESTS ----------------
void testTripHistoryErrors() {
    cout << "\n=== Testing TripHistoryService (Errors) ===\n";
    TripHistoryService trips;

    // Display empty trip history
    trips.displayTripsForward();
    trips.displayTripsBackward();
    cout << "Displayed empty trip history (should not crash)\n";
}

// ---------------- OUTFIT ROTATION ERROR TESTS ----------------
void testOutfitRotationErrors() {
    cout << "\n=== Testing OutfitRotationService (Errors) ===\n";
    OutfitRotationService outfits;

    // Rotate empty rotation
    outfits.nextOutfit();
    cout << "Attempted next outfit on empty rotation\n";

    // Show current outfit when empty
    outfits.showCurrentOutfit();
    cout << "Attempted to show current outfit on empty rotation\n";
}

int main() {
    cout << "=== ERROR TESTS FOR TRAVEL PACKING ROTATION SYSTEM ===\n";

    testPackingErrors();
    testTripHistoryErrors();
    testOutfitRotationErrors();

    cout << "\n=== ERROR TESTS COMPLETED ===\n";
    return 0;
}
