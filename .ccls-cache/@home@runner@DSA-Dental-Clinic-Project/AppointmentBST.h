#ifndef APPOINTMENT_BST_H
#define APPOINTMENT_BST_H

#include <iostream>
#include <string>
#include "appointment.h"

class BSTNode {
public:
    Appointment appointment;
    BSTNode* left;
    BSTNode* right;

    // Constructor for BSTNode
    BSTNode(const Appointment& appointment);
};

class AppointmentBST {
private:
    BSTNode* root;

    // Private methods for inserting, searching, deleting, and in-order traversal
    void insertNode(BSTNode*& node, const Appointment& appointment);
    Appointment* searchNode(BSTNode* node, const std::string& time) const;
    void inOrderTraversal(BSTNode* node) const;
    BSTNode* deleteNode(BSTNode* node, const std::string& time);
    BSTNode* findMinNode(BSTNode* node);
    void clearTree(BSTNode* node);

public:
    // Constructor and Destructor
    AppointmentBST();
    ~AppointmentBST();

    // Public methods for inserting, searching, deleting, and displaying appointments
    void insertAppointment(const Appointment& appointment);
    Appointment* searchAppointment(const std::string& time) const;
    void deleteAppointment(const std::string& time);
    void displayAppointments() const;
};

#endif // APPOINTMENT_BST_H
