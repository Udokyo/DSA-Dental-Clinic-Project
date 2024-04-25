#include "waitingRoomQueue.h"
#include <iostream>

// Define the isEmpty function to check if the queue is empty
bool waitingRoomQueue::isEmpty() const {
    return queue.empty();
}

void waitingRoomQueue::enqueue(const Patient &patient,
                               const Appointment &appointment) {
  QueueNode node(patient, appointment);
  queue.push(node);
  std::cout << patient.getFirstName() << " " << patient.getLastName()
            << " checked in.\n";
}

void waitingRoomQueue::dequeue(const Patient &patient,
                               const Appointment &appointment) {
  if (queue.empty()) {
    std::cout << "Waiting room is empty.\n";
    return;
  }

  // Create a temporary queue
  std::queue<QueueNode> tempQueue;
  bool found = false;

  // Iterate through the queue to find the patient and appointment
  while (!queue.empty()) {
    QueueNode node = queue.front();
    queue.pop();

    // Check if the current node matches the patient and appointment
    if (node.patient.getId() == patient.getId()) {
      // Patient and appointment found, do not enqueue back to temp queue
      std::cout << patient.getFirstName() << " " << patient.getLastName()
                << " checked out.\n";
      found = true;
    } else {
      // Enqueue the current node to the temporary queue
      tempQueue.push(node);
    }
  }

  // Transfer the temporary queue back to the original queue
  while (!tempQueue.empty()) {
    queue.push(tempQueue.front());
    tempQueue.pop();
  }

  if (!found) {
    std::cout << "Patient not found in the queue.\n";
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
      const QueueNode &node = tempQueue.front();
      std::cout << position << ". " << node.patient.getFirstName() << " "
                << node.patient.getLastName()
                << " (Appointment ID: " << node.appointment.getAppointmentId()
                << ")\n";
      tempQueue.pop();
      position++;
    }
  }
}

void managePatientCheckInAndOut(waitingRoomQueue &waitingRoomQueue,
                                patientList &patientList,
                                AppointmentBST &appointmentTree) {
  Patient *patient;
  Appointment *appointment;
  bool running = true;
  while (running) { // Prompt the user for the desired action (check-in or
                    // check-out)
    std::cout << "Please choose an option:\n";
    std::cout << "1. Check-in a patient\n";
    std::cout << "2. Check-out a patient\n";
    std::cout << "0. Exit\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
      // Check-in a patient
      std::string patientID, appID;

      // Prompt user for patient ID and appointment details
      std::cout << "Enter Patient ID: ";
      std::cin >> patientID;
      std::cout << "Enter Appointment ID: ";
      std::cin >> appID;

      // Search for the patient and appointment
      patient =
          patientList.searchForPatient(patientID);
      appointment = appointmentTree.searchAppointment(
          appID);

      if (patient && appointment) {
        // Enqueue the patient into the waiting room queue
        waitingRoomQueue.enqueue(*patient, *appointment);
      } else {
        // If the patient or appointment is not found
        std::cout
            << "Invalid patient ID or appointment ID\n"                  << "Please try again.\n";
      }

    } else if (choice == 2) {
      // Check-out a patient
      if (waitingRoomQueue.isEmpty()) {
        std::cout << "Waiting room queue is empty.\n";
      } else {
        std::string patientID;
        std::cout << "\nEnter Patient ID to check-out: ";
        std::cin >> patientID;
        waitingRoomQueue.dequeue(*patient, *appointment);
      }
    }
      else if (choice == 0) {
      // Exit the loop
      running = false;
    } else {
      // Invalid choice
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
}