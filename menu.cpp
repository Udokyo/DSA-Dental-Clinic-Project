#include "menu.h"
#include <iostream>

void displayMainMenu() {
  std::cout << "TechStars Dental Clinic Enterprise Software\n"
      << "---------------------------------------------\n"
      << "Select Role\n"
      << "1. Admin\n"
      << "2. Patient\n"
      << "3. Dentist\n";
}

void displayAdminMenu(){
  std::cout << "Select from the options below\n"
    << "1. Patient Registeration\n"
    << "2. Schedule Appointment\n"
    << "3. Patient check-in and check-out\n"
    << "4. View Waiting Room\n"
    << "5. Update Appointment Status\n"
    << "6. Patient Search\n"
    << "7. Update Patient Information\n"
    << "8. View Patient information and medical history\n"
    << "9. Add Dentist\n"
    << "10. Dentist Search\n"
    << "11. Update Dentist Availability Slots\n"
    << "12. View Dentist Bookings (2)\n"
    << "13. View Dentist patient/appointment queue\n"
    << "14. View upcoming appointments\n"
    << "15. View Patient Records\n"
    << "16. View payment records and summaries\n"
    << "17. View Appointment history by Patient, Dentist, Date\n"
    << "0. Return to Main Menu\n";
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

void displayDentistMenu() {
  // Display the dentist menu options
  std::cout << "Dentist Menu:\n";
  std::cout << "1. View patient/appointment Queue\n";
  std::cout << "2. Make prescription\n";
  std::cout << "3. Make report\n";
  std::cout << "4. View scheduled Appointments\n";
  // Add more menu options as needed
}

void displayPatientMenu() {
  // Display the patient menu options
  std::cout << "Patient Menu:\n";
  std::cout << "1. Register\n";
  std::cout << "2. Make appointment\n";
  std::cout << "3. Cancel appointment\n";
  std::cout << "4. View available dentists and their available time slots\n";
  std::cout << "5. Leave feedback on appointment\n";
  std::cout << "6. View medical record\n";
  // Add more menu options as needed
}