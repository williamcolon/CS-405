// IT-499 Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

            // William Colon
            // CS-499
            //Verrsion 4.1  2024/9/24

#include <iostream>
#include <string>
#include <vector>
#include <regex>


             //Inbound API's
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
   // Here the system will ask to enter the information required for the appoitment 
  // which include the name, date, time, and a brief description
    void addAppointment() {
        Appointment appointment;
        std::cout << "Enter name: ";
        std::getline(std::cin, appointment.name);

        std::string date;
        while (true) {
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            if (std::regex_match(date, std::regex(R"(\d{4}-\d{2}-\d{2})"))) {
                appointment.date = date;
                break;
            }
            std::cout << "Invalid date format. Please try again.\n";
        }

        std::string time;
        while (true) {
            std::cout << "Enter time (HH:MM): ";
            std::getline(std::cin, time);
            if (std::regex_match(time, std::regex(R"(\d{2}:\d{2})"))) {
                appointment.time = time;
                break;
            }
            std::cout << "Invalid time format. Please try again.\n";
        }

        std::cout << "Enter description: ";
        std::getline(std::cin, appointment.description);

        appointments.push_back(appointment);
        std::cout << "Appointment added successfully!\n";
    }

    void displayAppointments() const {
        if (appointments.empty()) {
            std::cout << "No appointments scheduled.\n";
            return;
        }
        std::cout << "Scheduled Appointments:\n";
        for (const auto& appointment : appointments) {
            std::cout << "Name: " << appointment.name
                << ", Date: " << appointment.date
                << ", Time: " << appointment.time
                << ", Description: " << appointment.description << "\n";
        }
    }

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
        std::cin.ignore(); // Ignore the newline character

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

