#include <iostream>
#include "Doctor.h"

using namespace std;

Doctor::Doctor(string n) {
    name = n;
}

void Doctor::treatPatient(Patient* p) {

    cout << name << " is treating the following patient:\n";
    p->displayInfo();
    cout << "------------------------\n";
}