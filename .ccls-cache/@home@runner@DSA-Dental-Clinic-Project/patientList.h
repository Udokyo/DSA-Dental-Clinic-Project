#ifndef PATIENTLIST_H
#define PATIENTLIST_H

#include "Patient.h"
#include <iostream>

class patientList {
private:
  class Node {
  public:
    Patient data;
    Node *next;

    Node(const Patient &data, Node *next = nullptr) : data(data), next(nullptr) {}
  };
  Node *head;

public:
  patientList();
  ~patientList();

  void addPatient(const Patient &item);
  void displayAllPatients() const;
  void addPatientFromInput();
  void addPatientFromFile(const std::string &filename);
  // // Method to search for a patient by name
  // Patient *searchForPatient(const std::string &firstName,
  //                           const std::string &lastName) const;
  // Method to search for a patient by id
  Patient *searchForPatient(const std::string &patientID) const; 
  // Method to delete a patient by name
  bool deletePatient(const std::string &patientID);
  // bool deletePatient(const std::string &firstName, const std::string &lastName);
};
void searchForPatientFromInput(patientList &patientList);

#endif // PATIENTLIST_H
