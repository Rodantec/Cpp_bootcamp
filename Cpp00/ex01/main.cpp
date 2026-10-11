#include "phonebook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "Welcome to the PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl;
            break;
        }
        
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (!command.empty())
            std::cout << "Unknown command. Available commands: ADD, SEARCH, EXIT" << std::endl;
    }
    
    return 0;
}
