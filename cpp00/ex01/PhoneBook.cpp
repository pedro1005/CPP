#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Constructor
PhoneBook::PhoneBook()
    : count(0), oldestIndex(0) {}

//Destructor
PhoneBook::~PhoneBook(void) {
    return;
}

// Format field to 10 characters (truncated with '.')
std::string PhoneBook::formatField(const std::string &str) const {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

int PhoneBook::getContactCount() const {
    return (count);
}


// Add a contact to the phonebook
void PhoneBook::addContact(const Contact &contact) {
    if (contact.isEmpty()) {
        std::cout << "Error: Contact fields cannot be empty!" << std::endl;
        return;
    }

    if (count < MAX_CONTACTS) {
        this->contacts[this->count] = contact;
        this->count++;
    } else {
        this->contacts[this->oldestIndex] = contact;
        this->oldestIndex = (this->oldestIndex + 1) % MAX_CONTACTS;
    }

    std::cout << "Contact added successfully!" << std::endl;
}

// Display list of contacts
void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }
}

// Display detailed contact by index
void PhoneBook::displayContactDetails(int index) const {
    if (index < 0 || index >= count) {
        std::cout << "Error: Invalid index!" << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
