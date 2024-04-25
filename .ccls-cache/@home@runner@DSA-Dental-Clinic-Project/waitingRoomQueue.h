#ifndef WAITINGROOMQUEUE_H
#define WAITINGROOMQUEUE_H

#include "Patient.h"
#include "appointment.h"
#include "appointmentBST.h"
#include "patientList.h"
#include <queue>

class waitingRoomQueue {
private:
  struct QueueNode {
    Patient patient;
    Appointment appointment;
    QueueNode(const Patient &p, const Appointment &a) : patient(p), appointment(a) {}
  };

  std::queue<QueueNode> queue; //Using std::queue to manage the patients in the queue
public:
  void enqueue(const Patient &patient, const Appointment &appointment); // Method to add a patient to the queue when they check in
  void dequeue(const Patient &patient, const Appointment &appointment); // Method to remove a patient from the queue when they check out
  void displayQueue() const; // Method to display the current queue status
  bool isEmpty() const; // Method to check if the queue is empty
};

void managePatientCheckInAndOut(waitingRoomQueue &waitingRoomQueue, patientList &patientList, AppointmentBST &appointmentTree);
#endif // WAITINGROOMQUEUE_H
