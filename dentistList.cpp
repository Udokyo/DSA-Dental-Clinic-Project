#include "dentistList.h"

// Constructor
DentistList::DentistList(size_t rows, size_t cols) : rows(rows), cols(cols) {
  // Initialize the 2D vector with the specified dimensions
  dentistGrid.resize(rows);
  for (size_t i = 0; i < rows; i++) {
    dentistGrid[i].resize(cols);
  }
}

// Function to add a dentist by inputting their information
void DentistList::addDentist(const Dentist &dentist) {
  // insertion approach (first empty position in the 2D grid).
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      // Check if the current position is empty
      if (dentistGrid[i][j].getFirstName().empty() &&
          dentistGrid[i][j].getLastName().empty()) {
        dentistGrid[i][j] = dentist;
        std::cout << std::endl;
        std::cout << "Dentist added successfully.\n" << std::endl;
        std::cout << dentist.getFirstName() << " " << dentist.getLastName()
                  << ". ID: " << dentist.getId()
                  << " added successfully at position (" << i << ", " << j
                  << ").\n";
        return;
      }
    }
  }
  std::cerr << "Dentist grid is full. Cannot add more dentists.\n";
}

// Function to retrieve a dentist using their name and DOB
Dentist *DentistList::findDentist(const std::string &dentistID) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      Dentist &dentist = dentistGrid[i][j];
      // Compare the first name, last name, and DOB
      if (dentist.getId() == dentistID) {
        return &dentist;
      }
    }
  }
  std::cout << "Dentist not found with the provided ID\n";
  return nullptr;
}

// Function to display the dentists in the grid
void DentistList::displayDentists() const {
  bool dentistFound = false;
  std::cout << "\nDentists in the grid:\n";
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      const Dentist &dentist = dentistGrid[i][j];
      if (!dentist.getFirstName().empty() && !dentist.getLastName().empty()) {
        dentistFound = true;
        std::cout << "Position (" << i << ", " << j << "):\n";
        std::cout << "  ID: " << dentist.getId() << "\n";
        std::cout << "  First Name: " << dentist.getFirstName() << "\n";
        std::cout << "  Last Name: " << dentist.getLastName() << "\n";
        std::cout << "  DOB: " << dentist.getDOB() << "\n";
        // Display other dentist information as needed (e.g., specialty)
      }
    }
  }
  if (!dentistFound) {
    std::cout << "No dentists added.\n";
  }
}

void createAndAddDentist(DentistList &dentistList) {
  // Variables to store dentist information
  std::string id, firstName, lastName, dob, phone, email;

  // Prompt the user to input dentist information
  std::cout << "Enter Dentist First Name: ";
  std::cin >> firstName;
  std::cout << "Enter Dentist Last Name: ";
  std::cin >> lastName;
  std::cout << "Enter Dentist Date of Birth (DOB) (e.g., MM-DD-YYYY): ";
  std::cin >> dob;
  std::cout << "Enter Dentist Phone Number: ";
  std::cin >> phone;
  std::cout << "Enter Dentist Email: ";
  std::cin >> email;

  // Create a new Dentist instance using the input information
  Dentist newDentist(id, firstName, lastName, dob, phone, email);

  // Add the newly created dentist to the dentist grid
  dentistList.addDentist(newDentist);
}
