#ifndef DENTIST_H
#define DENTIST_H

#include <string>
#include <vector>

class Dentist {
private:
  std::string id;
  std::string firstName;
  std::string lastName;
  std::string dob; // Date of Birth
  std::string phone;
  std::string email;

public:
  Dentist() = default;
  Dentist(const std::string &id, const std::string &fname,
          const std::string &lname, const std::string &dob,
          const std::string &phone, const std::string &email);
  std::string generateDentistID() const;

  // Getters
  std::string getId() const;
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getDOB() const;
  std::string getPhone() const;
  std::string getEmail() const;

  // Setters
  void setFirstName(const std::string &fname);
  void setLastName(const std::string &lname);
  void setDOB(const std::string &dob);
  void setPhone(const std::string &phone);
  void setEmail(const std::string &email);
};

#endif // DENTIST_H
