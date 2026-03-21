#include "CriticalPatient.h"

CriticalPatient::CriticalPatient(string n, int a, string s, int severity)
    : Patient(n, a, s) {

    severityLevel = severity;
}

void CriticalPatient::displayInfo() {

    cout << "CRITICAL PATIENT\n";
    Patient::displayInfo();
    cout << "Severity Level: " << severityLevel << endl;
}