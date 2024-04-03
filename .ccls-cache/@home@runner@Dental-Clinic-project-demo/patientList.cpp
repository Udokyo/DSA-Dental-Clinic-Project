#include "patientList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

patientList::patientList() : head(nullptr) {}
 
patientList::~patientList() {
  Node *current = head;
  while (current) {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
}

void patientList::addPatient(const Patient &item) {
  Node *newNode = new Node(item);
  newNode->next = head;
  head = newNode;
}
 
void patientList::displayAllPatients() const {
  Node *current = head;
  while (current) {
    std::cout << "Name: " << current->data.getFirstName() << " "
      << current->data.getLastName() << std::endl;
    std::cout << "Gender: " << current->data.getGender() << std::endl;
    std::cout << "DOB: " << current->data.getDOB() << std::endl;
    std::cout << "Phone Number: " << current->data.getPhone() << std::endl;
    std::cout << "Email: " << current->data.getEmail() << std::endl;
    std::cout << std::endl;
    // Add more information as needed
    current = current->next;
  }
}

Patient* patientList::searchForPatient(const std::string &firstName, const std::string &lastName) const {
  Node *current = head;
  while (current) {
      if ((current->data.getFirstName() == firstName && current->data.getLastName() == lastName) ||
      (current->data.getFirstName() == lastName && current->data.getLastName() == firstName)) {
      std::cout << "Patient found:\n";
      std::cout << "Name: " << current->data.getFirstName() << " "
                << current->data.getLastName() << std::endl;
      std::cout << "Gender: " << current->data.getGender() << std::endl;
      std::cout << "DOB: " << current->data.getDOB() << std::endl;
      std::cout << "Phone Number: " << current->data.getPhone() << std::endl;
      std::cout << "Email: " << current->data.getEmail() << std::endl;
      // Add more information as needed
      return &(current->data); // Return pointer to the patient
    }
    current = current->next;
  }
  std::cout << "Patient not found." << std::endl;
  return nullptr; // Patient not found
}

bool patientList::deletePatient(const std::string &firstName, const std::string &lastName) {
  Node *current = head;
  Node *prev = nullptr;

  while (current) {
    if ((current->data.getFirstName() == firstName && current->data.getLastName() == lastName) ||
        (current->data.getFirstName() == lastName && current->data.getLastName() == firstName)) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      delete current;
      std::cout << "Patient deleted." << std::endl;
      return true; // Patient deleted successfully
    }
    prev = current;
    current = current->next;
  }
  std::cout << "Patient not found." << std::endl;
  return false; // Patient not found
}

void patientList::addPatientFromInput(){
  std::string id, fname, lname, gender, dob, phone, email;
  std::cout << "Enter Patient First Name: ";
  std::cin >> fname;
  std::cout << "Enter Patient Last Name: ";
  std::cin >> lname;
  std::cout << "Enter Patient Gender: ";
  std::cin >> gender;
  std::cout << "Enter Patient DOB (MM-DD-YYYY): ";
  std::cin >> dob;
  std::cout << "Enter Patient Phone Number: ";
  std::cin >> phone;
  std::cout << "Enter Patient Email: ";
  std::cin >> email;
  Patient newPatient(id, fname, lname, gender, dob, phone, email);
  addPatient(newPatient);
  std::cout << "Patient added successfully." << std::endl;
}

void patientList::addPatientFromFile(const std::string &filename){
  std::ifstream file(filename);
if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, fname, lname, gender, dob, phone, email;

        if (std::getline(iss, fname, ',') &&
            std::getline(iss, lname, ',') &&
            std::getline(iss, gender, ',') &&
            std::getline(iss, dob, ',') &&
            std::getline(iss, phone, ',') &&
            std::getline(iss, email, ',')) {
            Patient patient(id, fname, lname, gender, dob, phone, email);
            addPatient(patient);
        }
    }
    file.close();
}
