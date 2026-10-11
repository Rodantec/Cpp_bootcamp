#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
class PhoneBook
{
    private:
        Contact contacts[8];
        int contactCount;
        int oldestIndex;

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact() const;
        void displayContacts() const;
};
#endif