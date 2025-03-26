#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>  // For std::stringstream

// Function to prompt the user and create a new contact
Contact createContact()
{
    Contact contact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);

    return contact;
}

void header(void)
{
    std::cout << "*******************************************************************************\n"
              << "  ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\n"
              << "  ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝ \n"
              << "  ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \n"
              << "  ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n"
              << "  ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗ \n"
              << "  ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ \n"
              << "********************************************************************************\n"
              << "\n"
              << "           Welcome to the pedmonte's PhoneBook App!   \n"
              << "           ****************************************\n"
              << "             Commands: 1-ADD | 2-SEARCH | 3-EXIT            \n"
              << "\n"
              << "********************************************************************************\n"
              << std::endl;
}

int main(void)
{
    PhoneBook   phoneBook;
    std::string command;

    header();
    while (true) {
        std::cout << "Enter a command: 1-ADD | 2-SEARCH | 3-EXIT\n";
        std::getline(std::cin, command);

        // Check if the input stream is in a fail state (e.g., EOF or invalid input)
        if (std::cin.eof()) {
            std::cout << "(Ctrl+D) detected. Exiting program." << std::endl;
            break;  // Exit the loop if EOF is detected
        }
        if (std::cin.fail()) {
            std::cout << "Input error. Exiting program." << std::endl;
            break;  // Exit the loop if there's a failure in reading input
        }
        if (command == "1" || command == "ADD")
        {
            Contact newContact = createContact();
            phoneBook.addContact(newContact);
        }
        else if (command == "2" || command == "SEARCH")
        {
            if (phoneBook.getContactCount() == 0)
            {
                std::cout << "No contacts available to search." << std::endl;
                continue;
            }
            phoneBook.displayContacts();
            std::cout << "Enter index of the contact to display: ";
            std::getline(std::cin, command);
            int index;
            std::stringstream ss(command);
            if (!(ss >> index))
            {
                std::cout << "Error: Invalid input!" << std::endl;
                continue;
            }

            phoneBook.displayContactDetails(index);
        }
        else if (command == "3" || command == "EXIT")
            break;
        else
            std::cout << "Invalid command!" << std::endl;
    }
    return (0);
}
