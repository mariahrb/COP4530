# Travel Packing Rotation System 

## Project Overview
The **Travel Packing Rotation System** is inspired by a spring break trip to Lapland, Finland. Organizing packing items, tracking multiple destinations, and rotating outfits efficiently can become confusing; this system provides a structured digital solution.

This project applies core concepts from **Data Structures and Object-Oriented Programming**, including:
* Singly, Doubly, and Circular Linked Lists
* Templates (Generic Programming)
* Object-Oriented Programming (OOP)
* Clean Layered Architecture

---

## Inspiration: Lapland, Finland
Our trip includes multiple destinations and varying weather conditions. We designed this system to:
1.  **Organize** packing items sequentially.
2.  **Track** visited destinations (forward and backward).
3.  **Rotate** outfits daily without repetition using a circular logic.

---

## Clean Architecture
The system follows a layered design to separate concerns and ensure maintainability:



### Domain Layer (Entities)
* `PackingItem`: Represents a physical item (name).
* `TripRecord`: Represents a destination.
* `Outfit`: Represents a daily clothing ensemble.
* *Features: Encapsulation and `<<` operator overloading.*

### Data Structure Layer (Generic Templates)
* **SinglyLinkedList<T>**: Stores packing items.
* **DoublyLinkedList<T>**: Stores trip records for bi-directional navigation.
* **CircularLinkedList<T>**: Stores outfits for continuous rotation.

### Service Layer
Wraps the data structures to provide high-level API operations:
* **PackingService**: `addItem()`, `removeItem()`, `displayPackingList()`.
* **TripHistoryService**: `addTrip()`, `displayTripsForward()`, `displayTripsBackward()`.
* **OutfitRotationService**: `addOutfit()`, `nextOutfit()`, `showCurrentOutfit()`.

### Main Program (Front-End)
* A menu-driven console interface.
* Interacts only with the Service Layer (no direct pointer manipulation).

---

## Features & Logic

### Packing List Management
* Uses a **Singly Linked List**.
* Supports adding and removing items by name.
* Linear traversal for display.

### Trip History Tracking
* Uses a **Doubly Linked List**.
* Allows users to view their journey chronologically or in reverse.

### Outfit Rotation
* Uses a **Circular Linked List**.
* **Rotation is achieved in $O(1)$ time** by simply moving the head pointer to the next node.

---

## Time Complexity Summary

| Operation | Data Structure | Complexity |
| :--- | :--- | :--- |
| **Add Item** | Singly Linked List | $O(n)$ (at tail) |
| **Remove Item** | Singly Linked List | $O(n)$ |
| **Display List** | Any List | $O(n)$ |
| **Rotate Outfit** | Circular Linked List | $O(1)$ |
| **Add Trip** | Doubly Linked List | $O(1)$ (at head/tail) |

---

## File Structure

```text
GroupNumber/
├── main.cpp
├── domain/
│   ├── PackingItem.h
│   ├── TripRecord.h
│   └── Outfit.h
├── structures/
│   ├── Node.h
│   ├── SinglyLinkedList.h
│   ├── DoublyLinkedList.h
│   └── CircularLinkedList.h
├── services/
│   ├── PackingService.h
│   ├── TripHistoryService.h
│   └── OutfitRotationService.h
├── tests/
│   ├── values_tests.cpp
│   └── errors_tests.cpp
└── README.md