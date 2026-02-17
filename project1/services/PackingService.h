// PackingService.h
// Provides high-level operations for managing packing items.
// Uses SinglyLinkedList<PackingItem> internally.
// Contains business logic related to adding, removing,
// and marking items as packed.

#ifndef PACKINGSERVICE_H
#define PACKINGSERVICE_H

#include <string>
#include "../domain/PackingItem.h"
#include "../structures/SinglyLinkedList.h"
using namespace std;

class PackingService {
private:
    SinglyLinkedList<PackingItem> packingList;

public:
    void addItem(const string& name);
    void removeItem(const string& name);
    void displayPackingList() const;
};

#endif
