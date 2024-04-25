#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Patient.h"
#include "dentist.h"
#include <string>
#include <vector>

class Appointment {
private:
  std::string appointmentId;
  Patient patient;
  Dentist dentist;
  std::string appointmentDate;
  std::string appointmentTime;
  std::string reason;

public:
  Appointment() = default;
  Appointment(const std::string &appointmentId, const Patient &patient,
              const Dentist &dentist, const std::string &appointmentDate,
              const std::string &appointmentTime,
              const std::string &reason);
  std::string generateAppointmentID() const;

  // Getters
  std::string getAppointmentId() const;
  Patient getPatient() const;
  Dentist getDentist() const;
  std::string getAppointmentDate() const;
  std::string getAppointmentTime() const;
  std::string getReason() const;

  // Setters
  void setPatient(const Patient &patient);
  void setDentist(const Dentist &dentist);
  void setAppointmentDate(const std::string &appointmentDate);
  void setAppointmentTime(const std::string &appointmentTime);
  void setReason(const std::string &reason);
};

#endif // APPOINTMENT_H
