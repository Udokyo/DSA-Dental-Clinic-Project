#include "waitingRoomQueue.h"
#include <iostream>

void waitingRoomQueue::enqueue(const Patient& patient, int appointmentId) {
    QueueNode node(patient, appointmentId);
    queue.push(node);
    std::cout << patient.getFirstName() << " " << patient.getLastName() << " checked in.\n";
}

void waitingRoomQueue::dequeue() {
    if (!queue.empty()) {
        QueueNode node = queue.front();
        queue.pop();
        std::cout << node.patient.getFirstName() << " " << node.patient.getLastName() << " checked out.\n";
    } else {
        std::cout << "Waiting room queue is empty.\n";
    }
}

void waitingRoomQueue::displayQueue() const {
  if (queue.empty()) {
    std::cout << "Waiting room queue is empty.\n";
  } else {
    std::cout << "Waiting room queue:\n";
    int position = 1;
    std::queue<QueueNode> tempQueue = queue; // Create a copy of the queue

    // Dequeue elements and print their details
    while (!tempQueue.empty()) {
        const QueueNode& node = tempQueue.front();
        std::cout << position << ". " << node.patient.getFirstName() << " " << node.patient.getLastName() << " (Appointment ID: " << node.appointmentId << ")\n";
        tempQueue.pop();
        position++;
    }
  } 
}
