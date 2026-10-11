#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0)
{
}
PhoneBook::~PhoneBook()
{
}

static std::string truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static bool isValidPhoneNumber(const std::string &phone)
{
    if (phone.empty())
        return false;
    
    for (size_t i = 0; i < phone.length(); i++)
    {
        char c = phone[i];
        if (!(c >= '0' && c <= '9') && (c != '+' && c != '-' &&
            c != '(' && c != ')' && c != ' ' && c != '.'))
            return false;
    }
    return true;
}

static std::string getInput(const std::string &prompt)
{
    std::string input;
    
    while (input.empty())
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            exit(0);
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    return input;
}

static std::string getPhoneNumber(const std::string &prompt)
{
    std::string input;
    
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            exit(0);
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
        else if (!isValidPhoneNumber(input))
            std::cout << "Invalid phone number. Only digits and +()-  are allowed." << std::endl;
        else
            break;
    }
    return input;
}

void PhoneBook::addContact()
{
    Contact newContact;
    
    std::cout << "Adding a new contact..." << std::endl;
    
    newContact.setFirstName(getInput("First name: "));
    newContact.setLastName(getInput("Last name: "));
    newContact.setNickname(getInput("Nickname: "));
    newContact.setPhoneNumber(getPhoneNumber("Phone number: "));
    newContact.setDarkestSecret(getInput("Darkest secret: "));
    
    if (contactCount < 8)
    {
        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
    {
        contacts[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContacts() const
{
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    displayContacts();
    std::string input;
    int index;
    std::cout << "Enter the index of the contact to display: ";
    if (!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        return;
    }
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
        index = input[0] - '0';
    else
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    if (index >= contactCount)
    {
        std::cout << "Contact not found!" << std::endl;
        return;
    }
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}
