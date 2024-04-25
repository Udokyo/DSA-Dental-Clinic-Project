#include "menu.h"
#include <iostream>

void displayMainMenu() {
  std::cout << "\nTechStars Dental Clinic Enterprise Software\n"
      << "---------------------------------------------\n"
      << "Select Role\n"
      << "1. Admin\n"
      << "2. Patient\n"
      << "3. Dentist\n";
    
}

// switch case from initial display
void displayAdminMenu(){

  // while (true) {
    std::cout << "\nSelect from the options below\n"
      << "1. Patient Registeration\n"
      << "2. Schedule Appointment\n"
      << "3. Patient check-in and check-out\n"
      << "4. View Waiting Room\n"
      << "5. View Appointments\n"
      << "6. Display Patients\n"
      << "7. Add Dentist\n"
      << "8. Display Dentist\n"
      << "0. Return to Main Menu\n";
      // }
}

void displayPatientMenu() {
  // Display the patient menu options
  std::cout << "\nPatient Menu:\n";
  std::cout << "1. Register\n";
  std::cout << "2. Make appointment\n";
  std::cout << "3. Cancel appointment\n";
  std::cout << "4. View available dentists and their available time slots\n";
  std::cout << "5. Leave feedback on appointment\n";
  std::cout << "6. View medical record\n";
  // Add more menu options as needed
}

void displayDentistMenu() {
  // Display the dentist menu options
  std::cout << "\nDentist Menu:\n";
  std::cout << "1. View patient/appointment Queue\n";
  std::cout << "2. Make prescription\n";
  std::cout << "3. Make report\n";
  std::cout << "4. View scheduled Appointments\n";
  // Add more menu options as needed
}
void patientMenu(patientList& patientList) {
  int patientRegisterationOption;

  while (true) {
    std::cout << "Patient Registeration Menu:\n"
      << "Select from the options below:\n"
      << "1. Input Patient Information\n"
      << "2. Import Patient Information From File\n"
      << "0. Go Back\n";

    std::cin >> patientRegisterationOption;

    if (patientRegisterationOption == 0) {
      break; // Go back to the main menu
    }

    switch (patientRegisterationOption) {
      case 1:
        patientList.addPatientFromInput();
        break;
      case 2: {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        patientList.addPatientFromFile(filename);
        break;
      }
      default:
        std::cerr << "Invalid option selected." << std::endl;
        break;
    }
  }
}
