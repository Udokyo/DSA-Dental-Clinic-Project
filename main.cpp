#include "Patient.h"
#include "appointmentBST.h"
#include "dentist.h"
#include "dentistList.h"
#include "patientList.h"
#include "waitingRoomQueue.h"
#include <iostream>
#include <string>
#include <limits>

void displayMenu() {
  std::cout << "\nTechStars Dental Clinic Enterprise Software\n"
            << "---------------------------------------------\n"
            << "Select from the options below\n"
            << "1. Add Patient\n"
            << "2. Schedule Appointment\n"
            << "3. Patient check-in and check-out\n"
            << "4. View Waiting Room\n"
            << "5. View Appointments\n"
            << "6. Display Patients\n"
            << "7. Add Dentist\n"
            << "8. Display Dentists\n"
            << "9. Display Patient Appointment History\n"
            << "10. Cancel appointment\n"
            << "0. Exit the program\n";
}

int main() {
  // Initialize data structures
  patientList patientList;
  DentistList dentistList(5, 5);
  AppointmentBST appointmentTree;
  waitingRoomQueue waitingRoomQueue;

  // Variable for input handling
  int choice = 0;
  // Main loop for the main menu
  bool running = true;
  while (running) {
    // Admin menu handling
    displayMenu();
    std::cin >> choice;
    // Switch case for the selected admin menu option
    switch (choice) {
    case 1:
      patientList.addPatientFromInput();
      break;
    case 2:
      addAppointmentToBST(appointmentTree, patientList, dentistList);
      break;
    case 3:
      managePatientCheckInAndOut(waitingRoomQueue, patientList,
                                 appointmentTree);
      break;
    case 4:
      waitingRoomQueue.displayQueue();
      break;
    case 5:
      appointmentTree.displayAppointments();
      break;
    case 6:
      patientList.displayAllPatients();
      break;
    case 7:
      createAndAddDentist(dentistList);
      break;
    case 8:
      dentistList.displayDentists();
      break;
    case 9: {
      std::string patientId;
      std::cout << "Enter patient ID: ";
      std::cin >> patientId;
      searchAndDisplayPatientAppointments(appointmentTree.getRoot(), patientId);
      break;
    }
    case 10: {
      std::string appId;
      std::cout << "Enter ID of appointment you wish to cancel ID: ";
      std::cin >> appId;
      appointmentTree.deleteAppointment(appId);
      break;
    }
    case 0:
      running = false;
      break;
    default:
      std::cout << "Invalid menu option. Please try again.\n";
    }
  }
  std::cout << "Thank you for using our program. Goodbye!" << std::endl;
  return 0;
}
