#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class CircularQueue {

private:
    Node<T>* rear;

public:

    CircularQueue() {
        rear = nullptr;
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(T value) {

        Node<T>* newNode = new Node<T>(value);

        if (rear == nullptr) {
            rear = newNode;
            rear->next = rear;
        }
        else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    T dequeue() {

        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        Node<T>* front = rear->next;
        T value = front->data;

        if (rear == front) {
            rear = nullptr;
        }
        else {
            rear->next = front->next;
        }

        delete front;
        return value;
    }

    T peek() {

        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        return rear->next->data;
    }

    void display() {

        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node<T>* current = rear->next;

        do {
            cout << current->data << endl;
            current = current->next;
        } while (current != rear->next);
    }

    void displayPatients() {

    if (isEmpty()) {
        cout << "No patients in queue\n";
        return;
    }

    Node<T>* current = rear->next; // front

    do {
        current->data->displayInfo();
        cout << "-----------------\n";
        current = current->next;
    } while (current != rear->next);
}
};

#endif