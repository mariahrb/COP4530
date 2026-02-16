#include "PackingService.h"

void PackingService::addItem(const string& name, const string& category, double weight) {
    packingList.insertAtEnd(PackingItem(name, category, weight));
}

void PackingService::removeItem(const string& name) {
    packingList.removeByName(name);
}

void PackingService::markItemPacked(const string& name) {
    packingList.markItem(name);
}

void PackingService::displayPackingList() const {
    packingList.display();
}

int PackingService::getItemCount() const {
    return packingList.size();
}

int PackingService::getTotalItems() const {
    return packingList.size();
}

void PackingService::clearPackingList() {
    packingList.clear();
}