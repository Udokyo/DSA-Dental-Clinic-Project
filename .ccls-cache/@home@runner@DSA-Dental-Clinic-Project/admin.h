#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <unordered_map>
#include "Patient.h"


#include <string>

class Admin {
private:
    std::string fullname;
    std::string username;
    std::string password;
    // Multidimensional array for storing patient information
    static const int MAX_PATIENTS = 100; // Example size
    Patient patientArray[MAX_PATIENTS][2]; // Assuming each patient has name and ID

public:
    Admin(const std::string& fullname, const std::string& username, const std::string& password);

//getters
    std::string getFullname() const;
    std::string getUsername() const;
    std::string getPassword() const;

//setters
    void setFullname(const std::string& fullname);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void adminMenu();
    void addPatient(const Patient& patient); // Add patient to multidimensional array and hashmap
// Add other menu option methods
};
#endif // ADMIN_H

