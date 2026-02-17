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
    Node<T>* current; // track current node for rotation

public:
    CircularLinkedList() : head(nullptr), current(nullptr) {}

    ~CircularLinkedList() {
        if (!head) return;
        Node<T>* temp = head->next;
        while (temp != head) {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete head;
    }

    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            current = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void moveNext() {
        if (current)
            current = current->next;
    }

    void displayCurrent() const {
        if (current)
            cout << current->data << endl;
        else
            cout << "List is empty.\n";
    }
};

#endif
