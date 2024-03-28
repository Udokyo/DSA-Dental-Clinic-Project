#include "Patient.h"

Patient::Patient(const std::string& fname, const std::string& lname,
    const std::string& dob, const std::string& phone, const std::string& email)
    : firstName(fname), lastName(lname), dob(dob), phone(phone), email(email) {
    patientID = generateNextID(); // Assign a unique ID to this instance
}

// Getters
int Patient::generateNextID() {
    return nextID++; // Return the current value of nextID, then increment it
}
int Patient::getPatientID() const {
    return patientID;
}
std::string Patient::getFirstName() const { return firstName; }
std::string Patient::getLastName() const { return lastName; }
std::string Patient::getDOB() const { return dob; }
std::string Patient::getPhone() const { return phone; }
std::string Patient::getEmail() const { return email; }

// Setters
void Patient::setFirstName(const std::string& fname) { firstName = fname; }
void Patient::setLastName(const std::string& lname) { lastName = lname; }
void Patient::setDOB(const std::string& dob) { this->dob = dob; }
void Patient::setPhone(const std::string& phone) { this->phone = phone; }
void Patient::setEmail(const std::string& email) { this->email = email; }
