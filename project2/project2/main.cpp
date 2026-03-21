#include <iostream>
#include "EmergencyRoom.h"

using namespace std;

int main() {

    EmergencyRoom er;

    int choice;

    do {

        cout << "\n===== Emergency Room System =====\n";
        cout << "1 Add Patient\n";
        cout << "2 Add Critical Patient\n";
        cout << "3 Treat Next Patient\n";
        cout << "4 Show Waiting Patients\n";
        cout << "5 Exit\n";

        cin >> choice;

        switch(choice) {

        case 1:
            er.addPatient();
            break;

        case 2:
            er.addCriticalPatient();
            break;

        case 3:
            er.treatNextPatient();
            break;

        case 4:
            er.showWaitingPatients();
            break;
        }

    } while(choice != 5);

    return 0;
}