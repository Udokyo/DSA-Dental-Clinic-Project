#include "appointment.h"
#include <iomanip>
#include <sstream>

int appointmentCounter = 1; // Static counter to keep track of Appointments
Appointment::Appointment(const std::string &appointmentId,
                         const Patient &patient, const Dentist &dentist,
                         const std::string &appointmentDate,
                         const std::string &appointmentTime,
                         const std::string &reason)
    : appointmentId(generateAppointmentID()), patient(patient),
      dentist(dentist), appointmentDate(appointmentDate),
      appointmentTime(appointmentTime), reason(reason) {}

// Implement getters and setters for the appointment class
// Getters
std::string Appointment::getAppointmentId() const { return appointmentId; }
Patient Appointment::getPatient() const { return patient; }
Dentist Appointment::getDentist() const { return dentist; }
std::string Appointment::getAppointmentDate() const { return appointmentDate; }
std::string Appointment::getAppointmentTime() const { return appointmentTime; }
std::string Appointment::getReason() const { return reason; }

// Setters
void Appointment::setPatient(const Patient &patient) {
  this->patient = patient;
}
void Appointment::setDentist(const Dentist &dentist) {
  this->dentist = dentist;
}
void Appointment::setAppointmentDate(const std::string &appointmentDate) {
  this->appointmentDate = appointmentDate;
}
void Appointment::setAppointmentTime(const std::string &appointmentTime) {
  this->appointmentTime = appointmentTime;
}
void Appointment::setReason(const std::string &reason) {
  this->reason = reason;
}
std::string Appointment::generateAppointmentID() const {
  // Generate Appointment ID with padding
  std::ostringstream oss;
  oss << "A" << std::setw(3) << std::setfill('0') << appointmentCounter++;
  return oss.str();
}
