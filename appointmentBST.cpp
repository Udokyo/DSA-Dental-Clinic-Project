#include "appointmentBST.h"
#include <algorithm> // for std::swap

// BSTNode constructor
BSTNode::BSTNode(const Appointment &appointment)
    : appointment(appointment), left(nullptr), right(nullptr) {}

// AppointmentBST constructor
AppointmentBST::AppointmentBST() : root(nullptr) {}

// AppointmentBST destructor
AppointmentBST::~AppointmentBST() { clearTree(root); }

// Method to clear the tree and free memory
void AppointmentBST::clearTree(BSTNode *node) {
  if (node) {
    clearTree(node->left);
    clearTree(node->right);
    delete node;
  }
}

// Method to insert an appointment into the BST
void AppointmentBST::insertAppointment(const Appointment &appointment) {
  insertNode(root, appointment);
}

// Method to insert a node in the BST
void AppointmentBST::insertNode(BSTNode *&node,
                                const Appointment &appointment) {
  if (node == nullptr) {
    node = new BSTNode(appointment);
  } else {
    // Compare based on appointment date and time and patient ID
    if (appointment.getAppointmentDate() <
        node->appointment.getAppointmentDate()) {
      insertNode(node->left, appointment);
    } else if (appointment.getAppointmentDate() >
               node->appointment.getAppointmentDate()) {
      insertNode(node->right, appointment);
    } else {
      // Dates are equal, compare times
      if (appointment.getAppointmentTime() <
          node->appointment.getAppointmentTime()) {
        insertNode(node->left, appointment);
      } else if (appointment.getAppointmentTime() >
                 node->appointment.getAppointmentTime()) {
        insertNode(node->right, appointment);
      } else {
        // Dates and times are equal, compare patient ID
        if (appointment.getPatient().getId() <
            node->appointment.getPatient().getId()) {
          insertNode(node->left, appointment);
        } else {
          insertNode(node->right, appointment);
        }
      }
    }
  }
}

// Method to search for an appointment in the BST patient ID
Appointment *
AppointmentBST::searchNode(BSTNode *node,
                           const std::string &appointmentID) const {
  if (node == nullptr) {
    return nullptr;
  }
  // Compare based on patient ID
  if (node->appointment.getAppointmentId() == appointmentID) {
    return &node->appointment;
  } else if (appointmentID < node->appointment.getPatient().getId()) {
    return searchNode(node->left, appointmentID);
  } else if (appointmentID > node->appointment.getPatient().getId()) {
    return searchNode(node->right, appointmentID);
  }
  std::cout << "No Appointment with ID: " << appointmentID << std::endl;
  return nullptr;
}

// Method to delete an appointment from the BST by date, time, and patient ID
BSTNode *AppointmentBST::deleteNode(BSTNode *node,
                                    const std::string &appointmentID) {
  if (node == nullptr) {
    std::cout << "No appointments to delete." << std::endl;
    return nullptr;
  }

  // Compare based on appointment ID
  if (appointmentID < node->appointment.getAppointmentId()) {
    node->left = deleteNode(node->left, appointmentID);
  } else if (appointmentID > node->appointment.getAppointmentId()) {
    node->right = deleteNode(node->right, appointmentID);
  } else {
    // If appointment ID matches
    if (node->left == nullptr) {
      BSTNode *rightChild = node->right;
      delete node;
      std::cout << "Appointment with ID " << appointmentID
                << " deleted successfully." << std::endl;
      return rightChild;
    } else if (node->right == nullptr) {
      BSTNode *leftChild = node->left;
      delete node;
      std::cout << "Appointment with ID " << appointmentID
                << " deleted successfully." << std::endl;
      return leftChild;
    } else {
      // If the node has both left and right children
      BSTNode *minRightNode = findMinNode(node->right);
      node->appointment = minRightNode->appointment;
      node->right =
          deleteNode(node->right, minRightNode->appointment.getAppointmentId());
    }
  }
  return node;
}

// Method to find the minimum node in a given subtree
BSTNode *AppointmentBST::findMinNode(BSTNode *node) {
  while (node && node->left) {
    node = node->left;
  }
  return node;
}

// Method for in-order traversal of the BST
void AppointmentBST::inOrderTraversal(BSTNode *node) const {
  if (node) {
    inOrderTraversal(node->left);
    std::cout << "Appointment ID: " << node->appointment.getAppointmentId()
              << std::endl;
    std::cout << "Appointment Date: " << node->appointment.getAppointmentDate()
              << std::endl;
    std::cout << "Appointment Time: " << node->appointment.getAppointmentTime()
              << std::endl;
    std::cout << "Patient ID: " << node->appointment.getPatient().getId()
              << std::endl;
    std::cout << "Patient: " << node->appointment.getPatient().getFirstName()
              << " " << node->appointment.getPatient().getLastName()
              << std::endl;
    std::cout << "Dentist: " << node->appointment.getDentist().getFirstName()
              << " " << node->appointment.getDentist().getLastName()
              << std::endl;
    // Display other appointment details as needed
    inOrderTraversal(node->right);
  }
}

// Method to search for an appointment in the BST by appointment ID
Appointment *
AppointmentBST::searchAppointment(const std::string &appointmentID) const {
  return searchNode(root, appointmentID);
}

// Method to delete an appointment from the BST by appointment ID
void AppointmentBST::deleteAppointment(const std::string &appointmentID) {
  root = deleteNode(root, appointmentID);
}

// Method to display all appointments in sorted order (in-order traversal)
void AppointmentBST::displayAppointments() const { inOrderTraversal(root); }

void promptAppointmentDetails(Appointment &appointment,
                              patientList &patientList,
                              DentistList &dentistList) {
  // Prompt the user for appointment details
  std::string appointmentId, patientID, dentistID, appointmentDate,
      appointmentTime, reason;
  std::cout << "Enter Patient ID: ";
  std::cin >> patientID;
  std::cout << "Enter Dentist ID: ";
  std::cin >> dentistID;
  std::cout << "Enter Appointment Date (MM-DD-YYYY): ";
  std::cin >> appointmentDate;
  std::cout << "Enter Appointment Time (HH:MM): ";
  std::cin >> appointmentTime;
  std::cout << "Enter Reason for Appointment: ";
  std::cin.ignore(); // Clear the input buffer before reading a line
  std::getline(std::cin, reason);

  // Search for the patient and dentist using the provided names and DOB
  Patient *patient = patientList.searchForPatient(patientID);
  Dentist *dentist = dentistList.findDentist(dentistID);

  // Check if patient and dentist exist
  if (!patient) {
    std::cout << "Invalid Patient ID Please try again.\n";
    return;
  }
  if (!dentist) {
    std::cout << "Invalid Dentist ID. Please try again.\n";
    return;
  }
  appointment = Appointment(appointmentId, *patient, *dentist, appointmentDate,
                            appointmentTime, reason);
}

void addAppointmentToBST(AppointmentBST &appointmentTree,
                         patientList &patientList, DentistList &dentistList) {
  // Create a new Appointment object
  Appointment newAppointment;
  // Prompt the user for appointment details and populate the newAppointment
  // object
  promptAppointmentDetails(newAppointment, patientList, dentistList);
  if (!newAppointment.getPatient().getId().empty() &&
      !newAppointment.getDentist().getId().empty()) {
    appointmentTree.insertAppointment(newAppointment);
    std::cout << std::endl;
    std::cout << "Appointment " << newAppointment.getAppointmentId()
              << " added successfully." << std::endl;
  }
  return;
}

// Function to search appointments made by a specific patient and sort them by
// date using quicksort
void searchAndDisplayPatientAppointments(BSTNode *node,
                                         const std::string &patientID) {
  std::vector<Appointment> appointments;

  // Search for appointments made by the patient and store them in a vector
  searchAppointmentsByPatientID(node, patientID, appointments);

  // Sort the appointments by date using quicksort
  quickSortAppointmentsByDate(appointments, 0, appointments.size() - 1);

  // Display the sorted appointments
  displayPatientAppointments(appointments);
}

// Helper function to recursively search appointments by patient ID and store
// them in a vector
void searchAppointmentsByPatientID(BSTNode *node, const std::string &patientID,
                                   std::vector<Appointment> &appointments) {
  if (node == nullptr) {
    return;
  }

  // In-order traversal
  searchAppointmentsByPatientID(node->left, patientID, appointments);

  // Check if the current node matches the patient ID
  if (node->appointment.getPatient().getId() == patientID) {
    appointments.push_back(node->appointment);
  }

  searchAppointmentsByPatientID(node->right, patientID, appointments);
  if (appointments.empty()) {
    std::cout << "Patient with ID not found" << std::endl;
  }
}
// Helper function to partition the appointments array for quicksort
int partition(std::vector<Appointment> &appointments, int low, int high) {
  const std::string pivotDate = appointments[high].getAppointmentDate();
  int i = low - 1;

  for (int j = low; j < high; ++j) {
    if (appointments[j].getAppointmentDate() <= pivotDate) {
      ++i;
      std::swap(appointments[i], appointments[j]);
    }
  }
  std::swap(appointments[i + 1], appointments[high]);
  return i + 1;
}
// Helper function to perform quicksort on appointments by date
void quickSortAppointmentsByDate(std::vector<Appointment> &appointments,
                                 int low, int high) {

  if (low < high) {
    int partitionIndex = partition(appointments, low, high);
    quickSortAppointmentsByDate(appointments, low, partitionIndex - 1);
    quickSortAppointmentsByDate(appointments, partitionIndex + 1, high);
  }
}

// Function to display appointments
void displayPatientAppointments(const std::vector<Appointment> &appointments) {
  for (const auto &appointment : appointments) {
    std::cout << "Appointment ID: " << appointment.getAppointmentId()
              << std::endl;
    std::cout << "Appointment Date: " << appointment.getAppointmentDate()
              << std::endl;
    std::cout << "Appointment Time: " << appointment.getAppointmentTime()
              << std::endl;
    std::cout << "Patient ID: " << appointment.getPatient().getId()
              << std::endl;
    std::cout << "Patient: " << appointment.getPatient().getFirstName() << " "
              << appointment.getPatient().getLastName() << std::endl;
    std::cout << "Dentist: " << appointment.getDentist().getFirstName() << " "
              << appointment.getDentist().getLastName() << std::endl;
    std::cout << "Reason: " << appointment.getReason() << std::endl
              << std::endl;
  }
}
