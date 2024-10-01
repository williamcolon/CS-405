/// cpp
// IT-499 Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// William Colon
// william.colon@snhu.edu
// CS-499
// Version 4.5  2024/10/1
// This Appointment scheduling software 
// is to automate and organize appointments by allowing 
// customers to book appointments with service providers 
// via an app, or website in the form of an online scheduler or kiosk.

#include <iostream>
#include <string>
#include <vector>
#include <regex>

// Struct to represent an Appointment with relevant details
struct Appointment {
    std::string name;        // Name of the person for the appointment
    std::string date;        // Date formatted as YYYY-MM-DD
    std::string time;        // Time formatted as HH:MM
    std::string description; // Brief description of the appointment
};

// The AppointmentService class manages a collection of appointments
class AppointmentService {
private:
    std::vector<Appointment> appointments; // Vector to store added appointments

public:
    // Function to add a new appointment
    // This function prompts the user for appointment details and validates the input
    //In this part of the code, a dictionary called appointment is used to store each appointment
    // and the corresponding activities as lists of strings. 
    // The displayAppointments function iterates through the dictionary, printing each day and its activities. 
    // The use of loops allows us to effectively organize and display the appointment in a clear format.
    void addAppointment() {
        Appointment appointment; // Create an Appointment object to store user input

        // Prompt user for the name associated with the appointment
        std::cout << "Enter name: ";
        std::getline(std::cin, appointment.name);

        // Input validation for the appointment date
        std::string date;
        while (true) {
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            // Regular expression to ensure date format is correct
            if (std::regex_match(date, std::regex(R"(\d{4}-\d{2}-\d{2})"))) {
                appointment.date = date; // Assign valid date to the appointment
                break; // Exit loop if valid date is provided
            }
            std::cout << "Invalid date format. Please try again.\n"; // Prompt for re-entry
        }

        // Input validation for the appointment time
        std::string time;
        while (true) {
            std::cout << "Enter time (HH:MM): ";
            std::getline(std::cin, time);
            // Regular expression to ensure time format is correct
            if (std::regex_match(time, std::regex(R"(\d{2}:\d{2})"))) {
                appointment.time = time; // Assign valid time to the appointment
                break; // Exit loop if valid time is provided
            }
            std::cout << "Invalid time format. Please try again.\n"; // Prompt for re-entry
        }

        // Prompt user for appointment description
        std::cout << "Enter description: ";
        std::getline(std::cin, appointment.description);

        // Add the new appointment to the vector of appointments
        appointments.push_back(appointment);
        std::cout << "Appointment added successfully!\n"; // Confirmation message
    }

    // Function to display all scheduled appointments
    // This function iterates over the vector and prints out the details for each appointment
    void displayAppointments() const {
        // Check if there are any appointments to display
        if (appointments.empty()) {
            std::cout << "No appointments scheduled.\n"; // Inform the user if none
            return;
        }
        std::cout << "Scheduled Appointments:\n"; // Header for the list
        // Loop through each appointment and print its details
        for (const auto& appointment : appointments) {
            std::cout << "Name: " << appointment.name
                << ", Date: " << appointment.date
                << ", Time: " << appointment.time
                << ", Description: " << appointment.description << "\n";
        }
    }

    // Function to clear all scheduled appointments
    // This function clears the vector of appointments and notifies the user
    void clearAppointments() {
        appointments.clear(); // Clear the vector to remove all appointments
        std::cout << "All appointments cleared.\n"; // Confirmation message
    }
};

// The main function provides a basic menu-driven interface for the appointment service
//In this program, we define two classes: Appointment, which stores details of an individual appointment (title and date),
// and AppointmentService, which manages a collection of appointments.
// The AppointmentService class provides two key methods:
// addAppointment to append a new appointment to the list and displayAppointments to output all scheduled appointments to the console. 
//In the main function, we instantiate the AppointmentService, add some sample appointments, 
// and display them, showcasing how the service can be effectively used for appointment management.
int main() {
    AppointmentService service; // Create an instance of the AppointmentService
    int choice; // Variable to store user menu choice
    // Menu loop to allow the user to continuously interact with the service
    do {
        // Display menu options to the user
        std::cout << "1. Add Appointment\n2. Display Appointments\n3. Clear Appointments\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Get user input for menu choice
        std::cin.ignore(); // Ignore the newline character after input

        // Process the user's choice
        switch (choice) {
        case 1: // Option to add an appointment
            service.addAppointment();
            break;
        case 2: // Option to display appointments
            service.displayAppointments();
            break;
        case 3: // Option to clear appointments
            service.clearAppointments();
            break;
        case 4: // Exit the appointment service
            std::cout << "Exiting the appointment service.\n";
            break;
        default: // Handle invalid menu choices
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0; // Indicate that the program completed successfully
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

