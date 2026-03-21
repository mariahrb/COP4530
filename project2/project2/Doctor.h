#ifndef DOCTOR_H
#define DOCTOR_H

#include "Patient.h"

class Doctor {

private:
    string name;

public:

    Doctor(string n);

    void treatPatient(Patient* p);
};

#endif