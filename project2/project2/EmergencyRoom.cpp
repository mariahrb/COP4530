#include <iostream>
#include "EmergencyRoom.h"

using namespace std;

EmergencyRoom::EmergencyRoom() : doctor("Dr. Smith") {}

void EmergencyRoom::addPatient() {

    string name, symptoms;
    int age;

    cout << "Enter patient name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter symptoms: ";
    cin >> symptoms;

    Patient* p = new Patient(name, age, symptoms);

    patientQueue.enqueue(p);

    cout << "Patient added to queue\n";
}

void EmergencyRoom::addCriticalPatient() {

    string name, symptoms;
    int age, severity;

    cout << "Enter patient name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter symptoms: ";
    cin >> symptoms;

    cout << "Enter severity level (1-10): ";
    cin >> severity;

    Patient* p = new CriticalPatient(name, age, symptoms, severity);

    patientQueue.enqueue(p);

    cout << "Critical patient added to queue\n";
}

void EmergencyRoom::treatNextPatient() {

    if (patientQueue.isEmpty()) {
        cout << "No patients waiting\n";
        return;
    }

    Patient* p = patientQueue.dequeue();

    doctor.treatPatient(p);

    delete p;
}

void EmergencyRoom::showWaitingPatients() {

    cout << "\n===== Waiting Patients =====\n";

    patientQueue.displayPatients();
}