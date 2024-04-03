#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Patient.h"
#include "dentist.h"
#include <ctime>
#include <string>
#include <vector>

class Appointment {
private:
  Patient patient;
  Dentist dentist;
  time_t appointmentTime;
  std::string appointmentId;
  std::string serviceName;
  std::string serviceType;
  std::string dentistNotes;
  std::string dentistPrescription;
  std::string cost;
  std::string patientFeedback;
  std::string appointmentDate;
  std::string appointmentStatus;

  // Add more relevant attributes as needed

public:
  Appointment() = default;
  Appointment(const Patient &patient, const Dentist &dentist,
              time_t appointmentTime, const std::string &appointmentId,
              const std::string &serviceName, const std::string &serviceType,
              const std::string &dentistNotes,
              const std::string &dentistPrescription, const std::string &cost,
              const std::string &patientFeedback,
              const std::string &appointmentDate,
              const std::string &appointmentStatus);

  // Getters
  Patient getPatient() const;
  Dentist getDentist() const;
  time_t getAppointmentTime() const;
  std::string getAppointmentId() const;
  std::string getServiceName() const;
  std::string getServiceType() const;
  std::string getDentistNotes() const;
  std::string getDentistPrescription() const;
  std::string getCost() const;
  std::string getPatientFeedback() const;
  std::string getAppointmentDate() const;
  std::string getAppointmentStatus() const;

  // Setters
  void setPatient(const Patient &patient);
  void setDentist(const Dentist &dentist);
  void setAppointmentTime(time_t appointmentTime);
  void setAppointmentId(const std::string &appointmentId);
  void setServiceName(const std::string &serviceName);
  void setServiceType(const std::string &serviceType);
  void setDentistNotes(const std::string &dentistNotes);
  void setDentistPrescription(const std::string &dentistPrescription);
  void setCost(const std::string &cost);
  void setPatientFeedback(const std::string &patientFeedback);
  void setAppointmentDate(const std::string &appointmentDate);
  void setAppointmentStatus(const std::string &appointmentStatus);

  // Add getters and setters for other attributes
};

#endif // APPOINTMENT_H
