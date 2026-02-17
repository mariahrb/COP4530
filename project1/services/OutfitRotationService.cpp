#include "OutfitRotationService.h"
#include <iostream>
using namespace std;

void OutfitRotationService::addOutfit(string name) {
    Outfit outfit(name);
    outfitRotation.insert(outfit);
    cout << "Outfit added.\n";
}

void OutfitRotationService::nextOutfit() {
    outfitRotation.moveNext(); // Move the current pointer
    cout << "Moved to next outfit.\n";
}

void OutfitRotationService::showCurrentOutfit() const {
    outfitRotation.displayCurrent(); // Print current outfit
}
