#include <iostream>
#include <string>
#include "menu.h"
#include "Patient.h"
#include "patientList.h"
#include "dentist.h"
#include "waitingRoomQueue.h"
#include "appointment.h"
#include "admin.h"


int main() {

patientList patientList;
  int optionSelection;

  while (true) {
    displayMainMenu();
    std::cin >> optionSelection;

    if (optionSelection == 0) {
      break; // Exit the program if the user selects 0
    }

    switch (optionSelection) {
      case 1:
        patientMenu(patientList); // Call a function to handle patient registration menu
        break;
      case 2:
        // Call a function to handle dentist registration menu
        break;
      case 3:
        // Call a function to handle patient search menu
        break;
      case 4:
        // Call a function to handle schedule appointment menu
        break;
      case 5:
        // Call a function to handle view available dentists menu
        break;
      case 6:
        // Call a function to handle view upcoming appointments menu
        break;
      case 7:
        // Call a function to handle view patient information and medical history menu
        break;
      default:
        std::cerr << "Invalid option selected." << std::endl;
        break;
    }
  }

  return 0;
}
