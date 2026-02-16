// Implements a generic singly linked list using templates.
// Used for managing the active packing list.

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int size() const {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void removeByName(string name) {
        if (head == nullptr) return;

        if (head->data.getName() == name) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data.getName() != name) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }       
    }

    void markItem(string name) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data.getName() == name) {
                temp->data.setPacked(true);
                return;
            }
            temp = temp->next;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif