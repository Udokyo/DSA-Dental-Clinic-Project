#include "admin.h"
#include "dentist.h"
#include "appointment.h"
#include <iostream>
#include <string>

Admin::Admin(const std::string& fullname, const std::string& username, const std::string& password) : username(username), password(password) {}

// Getters
std::string Admin::getFullname() const { return fullname; }
std::string Admin::getUsername() const { return username; }
std::string Admin::getPassword() const { return password; }

// Setters
void Admin::setFullname(const std::string& fullname) {this->fullname = fullname; }
void Admin::setUsername(const std::string& username) { this->username = username; }
void Admin::setPassword(const std::string& password) { this->password = password; }
void Admin::adminMenu() {
  // Display the admin menu options
  std::cout << "Admin Menu:\n";
  std::cout << "1. Register patient\n";
  std::cout << "2. Make appointment\n";
  std::cout << "3. Cancel appointment\n";
  std::cout << "4. Patient check-in and check-out\n";
  std::cout << "5. View waiting room\n";
  std::cout << "7. Update patient information\n";
  std::cout << "8. Register/Add Dentist\n";
  std::cout << "9. Add/update Dentist availability slots\n";
  std::cout << "10. View patient records\n";
  std::cout << "11. View payment record and summaries\n";
  std::cout << "12. View Dentist bookings\n";
  std::cout << "13. View Dentist patient/appointment queue\n";
  std::cout << "14. Update appointments\n";
  std::cout << "15. View appointment history by Patient, Dentist, Date\n";  // Add more menu options as needed

  int choice;
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  
//   switch (choice) { // Cases for menu options
//       case 1:
//           addPatient();
//           break;
//       case 2:
//           makeAppointment();
//           break;
//       case 3:
//           cancelAppointment();
//           break;
//       case 4:
//           patientCheckIn();
//           break;
//       case 5:
//           patientCheckOut();
//           break; 
//       case 6:
//           patientWaitingRoom();
//           break;
//       case 7:
//           updatePatientInformation();
//           break;
//       case 8:
//           addDentist();
//           break;
//       case 9:
//           addDentistAvailability();
//           break;
//       case 10:
//           viewPatientRecords();
//           break;
//       case 11:
//           viewPaymentRecord();
//           break;
//       case 12:
//           viewDentistBookings();
//           break;
//       case 13:
//           viewDentistPatientQueue();
//           break;
//       case 14:
//           updateAppointments();
//           break;
//       case 15:
//           viewAppointmentHistory();
//           break;
//       default:
//           std::cout << "Invalid choice\n";
//           break;
//   }
// }
// void Admin::addPatient(const Patient& patient) {
//     // Add patient to the multidimensional array
//     for (int i = 0; i < MAX_PATIENTS; ++i) {
//         if (patientArray[i][0].getId().empty()) { // Check for an empty slot
//             patientArray[i][0] = patient;
//             break;
//         }
//     }

//     // Add patient to the hashmap
//     patientHashMap[patient.getId()] = patient;
// }
// void Admin::makeAppointment(const std::string& patientId, const std::string& dentistId, const std::string& date){
//   // Check if the patient and dentist are registered
//   if (patientHashMap.find(patientId) == patientHashMap.end() || dentistHashMap.find(dentistId) == dentistHashMap.end()) 
// }
// void Admin::cancelAppointment(const std::string& appointmentId){
//   // Find the appointment in the appointment array
//   for (int i = 0; i < MAX_APPOINTMENTS; ++i){
//     if (appointmentArray[i].getId() == appointmentId){
//       // Mark the appointment as canceled
//       appointmentArray[i].setStatus("Canceled");
//       break;
//     }
//   }
// }
// void Admin::patientCheckIn(const std::string& patientId){
//   // Find the patient in the patient array
//   for (int i = 0; i < MAX_PATIENTS; ++i){
//     if (patientArray[i][0].getId() == patientId){
//       // Mark the patient as checked in
//       patientArray[i][0].setStatus("Checked In");
//       break;
//     }
//   }
}