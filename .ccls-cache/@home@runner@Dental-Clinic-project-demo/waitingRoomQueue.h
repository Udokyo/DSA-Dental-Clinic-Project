#ifndef WAITINGROOMQUEUE_H
#define WAITINGROOMQUEUE_H

#include "Patient.h"
#include "appointment.h"
#include <queue>

class waitingRoomQueue {
private:
  struct QueueNode {
    Patient patient;
    int appointmentId;
    QueueNode(const Patient &p, int id) : patient(p), appointmentId(id) {}
  };

  std::queue<QueueNode> queue; //Using std::queue to manage the patients in the queue
public:
  void enqueue(const Patient &patient, int appointmentId); // Method to add a patient to the queue when they check in
  void dequeue(); // Method to remove a patient from the queue when they check out
  void displayQueue() const; // Method to display the current queue status
};

#endif // WAITINGROOMQUEUE_H
