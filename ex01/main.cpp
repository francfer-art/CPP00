#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std::string option;

    std::cout << "Welcome to the phonebook!" << std::endl;

    while (true) 
    {
        std::cout << "Choose an option: ADD, SEARCH, EXIT" << std::endl;
        if (!std::getline(std::cin, option))
        {
            std::cout << "\nEOF detected. Exiting phonebook..." << std::endl;
            break;
        }

        if (option == "EXIT")
        {
            std::cout << "Exiting phonebook..." << std::endl;
            break;
        }
        else if (option == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "Enter the first name: ";
            if (!std::getline(std::cin, firstName)) { std::cout << "\nEOF detected. Exiting phonebook..." << std::endl; break; }

            std::cout << "Enter the last name: "; 
            if (!std::getline(std::cin, lastName)) { std::cout << "\nEOF detected. Exiting phonebook..." << std::endl; break; }

            std::cout << "Enter the nickname: ";
            if (!std::getline(std::cin, nickname)) { std::cout << "\nEOF detected. Exiting phonebook..." << std::endl; break; }

            std::cout << "Enter the phone number: ";
            if (!std::getline(std::cin, phoneNumber)) { std::cout << "\nEOF detected. Exiting phonebook..." << std::endl; break; }

            std::cout << "Enter the darkest secret: ";
            if (!std::getline(std::cin, darkestSecret)) { std::cout << "\nEOF detected. Exiting phonebook..." << std::endl; break; }

            phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        }
        else if (option == "SEARCH")
        {
            std::cout << "Searching Contact" << std::endl;
        }
        else if (option == "DISPLAY")
        {
            phonebook.displayContacts();
        }
        else
        {
            std::cout << "Invalid option. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}
