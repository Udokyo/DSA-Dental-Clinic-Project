#ifndef DENTISTLIST_H
#define DENTISTLIST_H

#include "dentist.h"
#include <iostream>
#include <string>
#include <vector>

class DentistList {
private:
  // Multidimensional array (2D vector) to store dentist information
  std::vector<std::vector<Dentist>> dentistGrid;
  // Dimensions of the dentist grid
  size_t rows;
  size_t cols;

public:
  // Constructor
  DentistList(size_t rows, size_t cols);
  // Function to add a dentist by inputting their information
  void addDentist(const Dentist &dentist);
  // Function to retrieve a dentist using their name and DOB
  Dentist *findDentist(const std::string &dentistID);
  // Dentist *findDentist(const std::string &firstName,
  //                      const std::string &lastName, const std::string &dob);
  // Function to display the dentists in the grid
  void displayDentists() const;
};

// Function to create and add a new dentist
void createAndAddDentist(DentistList &dentistList);
#endif // DENTISTLIST_H
