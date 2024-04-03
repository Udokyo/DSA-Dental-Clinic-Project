#include "Patient.h"
#include <iomanip>
#include <sstream>

int patientCounter = 1; // Static counter to keep track of patients
Patient::Patient(const std::string &id, const std::string &fname,
                 const std::string &lname, const std::string &gender,
                 const std::string &dob, const std::string &phone,
                 const std::string &email)
    : id(generatePatientID()), firstName(fname), lastName(lname),
      gender(gender), dob(dob), phone(phone), email(email) {}

// Getters
std::string Patient::getId() const { return id; }
std::string Patient::getFirstName() const { return firstName; }
std::string Patient::getLastName() const { return lastName; }
std::string Patient::getGender() const { return gender; }
std::string Patient::getDOB() const { return dob; }
std::string Patient::getPhone() const { return phone; }
std::string Patient::getEmail() const { return email; }

// Setters
void Patient::setFirstName(const std::string &fname) { firstName = fname; }
void Patient::setLastName(const std::string &lname) { lastName = lname; }
void Patient::setGender(const std::string &gender) { this->gender = gender; }
void Patient::setDOB(const std::string &dob) { this->dob = dob; }
void Patient::setPhone(const std::string &phone) { this->phone = phone; }
void Patient::setEmail(const std::string &email) { this->email = email; }
std::string Patient::generatePatientID() const {
  // Generate patient ID with padding
  std::ostringstream oss;
  oss << "P" << std::setw(3) << std::setfill('0') << patientCounter++;
  return oss.str();
}
