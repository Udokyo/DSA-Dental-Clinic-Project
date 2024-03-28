#include <iostream>
#include <string>
#include "Patient.h"

// Function to create a new patient by asking the user for input
Patient createPatientFromInput() {
  std::string fname, lname, dob, phone, email;

  std::cout << "Enter Patient First Name: ";
  std::cin >> fname;
  std::cout << "Enter Patient Last Name: ";
  std::cin >> lname;
  std::cout << "Enter Patient DOB (MM-DD-YYYY): ";
  std::cin >> dob;
  std::cout << "Enter Patient Phone Number: ";
  std::cin >> phone;
  std::cin >> phone;
  std::cout << "Enter Patient Email: ";
  std::cin >> email;

  return Patient(fname, lname, dob, phone, email);
}

int main() {
  int optionSelection;
  // patient data type
  // Patient patientID;
  std::cout << "Welcome to our Dental Clinic\n" 
    << "Select from the options below\n"
    << "1. Patient Registeration\n"
    << "2. Schedule an appointment\n"
    << "3. View available Dentists\n"
    << "4. View upcoming appointments\n"
    << "5. View Patient information and medical history";
  // implement try catch exception
  std::cin >> optionSelection;
  if (optionSelection == 1) {
    std::cout << "Please enter the patient's information below:\n";
    Patient newPatient = createPatientFromInput();
    // Further processing with newPatient can be done here, like adding to patient records.
  }
  else if (optionSelection == 2) {

  } 
  return 0;
}