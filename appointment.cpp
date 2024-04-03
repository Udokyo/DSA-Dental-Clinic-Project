#include "appointment.h"

Appointment::Appointment(
    const Patient &patient, const Dentist &dentist, time_t appointmentTime,
    const std::string &appointmentId, const std::string &serviceName,
    const std::string &serviceType, const std::string &dentistNotes,
    const std::string &dentistPrescription, const std::string &cost,
    const std::string &patientFeedback, const std::string &appointmentDate,
    const std::string &appointmentStatus)
    : patient(patient), dentist(dentist), appointmentTime(appointmentTime),
      appointmentId(appointmentId), serviceName(serviceName),
      serviceType(serviceType), dentistNotes(dentistNotes),
      dentistPrescription(dentistPrescription), cost(cost),
      patientFeedback(patientFeedback), appointmentDate(appointmentDate),
      appointmentStatus(appointmentStatus) {}

// Implement getters and setters for the appointment class
// Getters
Patient Appointment::getPatient() const { return patient; }
Dentist Appointment::getDentist() const { return dentist; }
time_t Appointment::getAppointmentTime() const { return appointmentTime; }
std::string Appointment::getAppointmentId() const { return appointmentId; }
std::string Appointment::getServiceName() const { return serviceName; }
std::string Appointment::getServiceType() const { return serviceType; }
std::string Appointment::getDentistNotes() const { return dentistNotes; }
std::string Appointment::getDentistPrescription() const {
  return dentistPrescription;
}
std::string Appointment::getCost() const { return cost; }
std::string Appointment::getPatientFeedback() const { return patientFeedback; }
std::string Appointment::getAppointmentDate() const { return appointmentDate; }
std::string Appointment::getAppointmentStatus() const {
  return appointmentStatus;
}

// Setters
void Appointment::setPatient(const Patient &patient) {
  this->patient = patient;
}
void Appointment::setDentist(const Dentist &dentist) {
  this->dentist = dentist;
}
void Appointment::setAppointmentTime(time_t appointmentTime) {
  this->appointmentTime = appointmentTime;
}
void Appointment::setAppointmentId(const std::string &appointmentId) {
  this->appointmentId = appointmentId;
}
void Appointment::setServiceName(const std::string &serviceName) {
  this->serviceName = serviceName;
}
void Appointment::setServiceType(const std::string &serviceType) {
  this->serviceType = serviceType;
}
void Appointment::setDentistNotes(const std::string &dentistNotes) {
  this->dentistNotes = dentistNotes;
}
void Appointment::setDentistPrescription(
    const std::string &dentistPrescription) {
  this->dentistPrescription = dentistPrescription;
}
void Appointment::setCost(const std::string &cost) { this->cost = cost; }
void Appointment::setPatientFeedback(const std::string &patientFeedback) {
  this->patientFeedback = patientFeedback;
}
void Appointment::setAppointmentDate(const std::string &appointmentDate) {
  this->appointmentDate = appointmentDate;
}
void Appointment::setAppointmentStatus(const std::string &appointmentStatus) {
  this->appointmentStatus = appointmentStatus;
}
