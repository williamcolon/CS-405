// IT-499 Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Appointment {
    std::string name;
    std::string date;
    std::string time;
    std::string description;
};

class AppointmentService {
private:
    std::vector<Appointment> appointments;

public:
    // Function to add a new appointment
    void addAppointment() {
        Appointment appointment;
        std::cout << "Enter name: ";
        std::getline(std::cin, appointment.name);
        std::cout << "Enter date (YYYY-MM-DD): ";
        std::getline(std::cin, appointment.date);
        std::cout << "Enter time (HH:MM): ";
        std::getline(std::cin, appointment.time);
        std::cout << "Enter description: ";
        std::getline(std::cin, appointment.description);

        appointments.push_back(appointment);
        std::cout << "Appointment added successfully!\n";
    }

    // Function to display all appointments
    void displayAppointments() {
        if (appointments.empty()) {
            std::cout << "No appointments scheduled.\n";
            return;
        }
        std::cout << "Scheduled Appointments:\n";
        for (const auto& appointment : appointments) {
            std::cout << "Name: " << appointment.name << ", Date: " << appointment.date
                << ", Time: " << appointment.time << ", Description: " << appointment.description << "\n";
        }
    }

    // Function to clear all appointments
    void clearAppointments() {
        appointments.clear();
        std::cout << "All appointments cleared.\n";
    }
};

int main() {
    AppointmentService service;
    int choice;

    do {
        std::cout << "1. Add Appointment\n2. Display Appointments\n3. Clear Appointments\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
        case 1:
            service.addAppointment();
            break;
        case 2:
            service.displayAppointments();
            break;
        case 3:
            service.clearAppointments();
            break;
        case 4:
            std::cout << "Exiting the appointment service.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
