#ifndef APPOINTMENT_BST_H
#define APPOINTMENT_BST_H

#include "appointment.h"
#include "dentistList.h"
#include "patientList.h"
#include <iostream>
#include <string>
#include <vector>

// Define the BST node structure
struct BSTNode {
  Appointment appointment; // Appointment data
  BSTNode *left;           // Left child
  BSTNode *right;          // Right child

  // Constructor for BSTNode
  BSTNode(const Appointment &appointment);
};

// Define the AppointmentBST class
class AppointmentBST {
private:
  BSTNode *root; // Root of the BST
  // Private methods for managing the BST
  void clearTree(BSTNode *node);
  void insertNode(BSTNode *&node, const Appointment &appointment);
  Appointment *searchNode(BSTNode *node,
                          const std::string &appointmentID) const;
  BSTNode *deleteNode(BSTNode *node, const std::string &appointmentID);
  BSTNode *findMinNode(BSTNode *node);
  void inOrderTraversal(BSTNode *node) const;

public:
  // Constructor and Destructor
  AppointmentBST();
  ~AppointmentBST();

  // Public methods for managing appointments in the BST
  BSTNode *getRoot() const { return root; }
  void insertAppointment(const Appointment &appointment);
  Appointment *searchAppointment(const std::string &appointmentID) const;
  // std::vector<Appointment>
  // searchAppointmentsByPatientID(BSTNode *node, const std::string &patientID);
  void deleteAppointment(const std::string &appointmentID);
  void displayAppointments() const;
};

// Function to prompt the user for appointment details and populate an Appointment object
void promptAppointmentDetails(Appointment &appointment,
                              patientList &patientList,
                              DentistList &dentistList);

// Function to add an Appointment object to the binary search tree (AppointmentBST)
void addAppointmentToBST(AppointmentBST &appointmentTree,
                         patientList &patientList, DentistList &dentistList);
void searchAndDisplayPatientAppointments(BSTNode *node, const std::string &patientID);
void searchAppointmentsByPatientID(BSTNode *node, const std::string &patientID, std::vector<Appointment> &appointments);
void quickSortAppointmentsByDate(std::vector<Appointment> &appointments, int low, int high);
int partition(std::vector<Appointment> &appointments, int low, int high);
void displayPatientAppointments(const std::vector<Appointment> &appointments);
// void bubbleSortAppointmentsByDate(std::vector<Appointment> &appointments);
// void displayAppointmentsByDate(const std::string &patientID,
//  AppointmentBST &appointmentTree);

#endif // APPOINTMENT_BST_H
