#include "Patient.h"

Patient::Patient(string n, int a, string s) {
    name = n;
    age = a;
    symptoms = s;
}

void Patient::displayInfo() {
    cout << "Patient: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Symptoms: " << symptoms << endl;
}