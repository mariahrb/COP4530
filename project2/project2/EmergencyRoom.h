#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H

#include "CircularQueue.h"
#include "Patient.h"
#include "CriticalPatient.h"
#include "Doctor.h"

class EmergencyRoom {

private:

    CircularQueue<Patient*> patientQueue;
    Doctor doctor;

public:

    EmergencyRoom();

    void addPatient();
    void addCriticalPatient();
    void treatNextPatient();
    void showWaitingPatients();
};

#endif