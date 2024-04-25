#include "dentist.h"
#include <iomanip>
#include <sstream>

int dentistCounter = 1; // Static counter to keep track of Dentists
Dentist::Dentist(const std::string &id, const std::string &fname, const std::string &lname, const std::string &dob, const std::string &phone, const std::string &email)
    : id(generateDentistID()), firstName(fname), lastName(lname), dob(dob), phone(phone), email(email) {}

// Getters
std::string Dentist::getId() const { return id; }
std::string Dentist::getFirstName() const { return firstName; }
std::string Dentist::getLastName() const { return lastName; }
std::string Dentist::getDOB() const { return dob; }
std::string Dentist::getPhone() const { return phone; }
std::string Dentist::getEmail() const { return email; }

// Setters
void Dentist::setFirstName(const std::string &fname) { firstName = fname; }
void Dentist::setLastName(const std::string &lname) { lastName = lname; }
void Dentist::setDOB(const std::string &dob) { this->dob = dob; }
void Dentist::setPhone(const std::string &phone) { this->phone = phone; }
void Dentist::setEmail(const std::string &email) { this->email = email; }
std::string Dentist::generateDentistID() const {
  // Generate Dentist ID with padding
  std::ostringstream oss;
  oss << "D" << std::setw(3) << std::setfill('0') << dentistCounter++;
  return oss.str();
}
