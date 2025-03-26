#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int count;
    int oldestIndex;

    std::string formatField(const std::string &str) const;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void addContact(const Contact &contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
	int getContactCount() const;
};

#endif

