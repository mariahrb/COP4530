#include "PackingService.h"
#include <iostream>
using namespace std;

void PackingService::addItem(const string& name) {
    packingList.insertAtEnd(PackingItem(name));
    cout << "Item added.\n";
}

void PackingService::removeItem(const string& name) {
    packingList.removeByName(name);
    cout << "Item removed (or not found).\n";
}

void PackingService::displayPackingList() const {
    packingList.display();
}