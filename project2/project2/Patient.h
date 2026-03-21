#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient {

protected:
    string name;
    int age;
    string symptoms;

public:

    Patient(string n, int a, string s);

    virtual void displayInfo();
};

#endif