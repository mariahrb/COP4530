// OutfitRotationService.h
// Manages daily outfit rotation.
// Uses CircularLinkedList<Outfit> internally.
// Allows cycling through outfits repeatedly.

#ifndef OUTFITROTATIONSERVICE_H
#define OUTFITROTATIONSERVICE_H

#include <string>
#include "../structures/CircularLinkedList.h"
#include "../domain/Outfit.h"
using namespace std;

class OutfitRotationService {
private:
    CircularLinkedList<Outfit> outfitRotation;

public:
    void addOutfit(string name);
    void nextOutfit();
    void showCurrentOutfit() const;
};

#endif
