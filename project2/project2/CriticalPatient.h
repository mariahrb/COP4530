#ifndef CRITICALPATIENT_H
#define CRITICALPATIENT_H

#include "Patient.h"

class CriticalPatient : public Patient {

private:
    int severityLevel;

public:

    CriticalPatient(string n, int a, string s, int severity);

    void displayInfo() override;
};

#endif