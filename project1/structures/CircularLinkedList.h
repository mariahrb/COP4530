// Implements a generic circular linked list using templates.
// Tail connects back to head to allow continuous rotation.
// Used for outfit rotation scheduling.

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    int count;

public:
    CircularLinkedList() : head(nullptr), count(0) {}

    ~CircularLinkedList() {
        while (!isEmpty()) {
            removeCurrent();
        }
    }

    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        count++;
    }

    void removeCurrent() {
        if (head == nullptr) return;
        
        if (head->next == head) { // only one node
            delete head;
            head = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) { // find last node
                temp = temp->next;
            }
            Node<T>* toDelete = head;
            head = head->next; // move head forward
            temp->next = head; // update last node
            delete toDelete;
        }
        count--;
    }

    T getCurrent() const {
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    void moveToNext() {
        if (head != nullptr) {
            head = head->next;
        }
    }

    void displayAll() const {
        if (head == nullptr) return;
        
        Node<T>* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};

#endif
