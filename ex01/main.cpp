#include "Contact.hpp"
#include "Phonebook.hpp"

#include <iostream>
#include <limits>

std::string getValidIndex()
{
    std::string index;
    while (true)
    {
        std::cout << "Select any valid index: ";
        if (!std::getline(std::cin, index))
        {
            std::cout << "\nEOF detected. Exiting phonebook..." << std::endl;
            exit(0);
        }

        bool isNumber = true;
        for (size_t i = 0; i < index.length(); i++)
        {
            if (!isdigit(index[i]))
            {
                isNumber = false;
                break;
            }
        }

        if (isNumber && !index.empty())
            return index;

        std::cout << "\033[1;31mInvalid input. Please enter a valid number.\033[0m\n";
    }
}

int main()
{
    Phonebook phonebook;
    std::string option;

    std::cout << "Welcome to the phonebook!" << std::endl;

    while (true) 
    {
      std::cout << "\033[1;36mChoose an option: ADD, SEARCH, EXIT\033[0m" << std::endl;
        if (!std::getline(std::cin, option))
        {
            std::cout << "\033[1;31m" <<"EOF detected. Exiting phonebook..." << "\033[0m" <<std::endl;
            break;
        }

        if (option == "EXIT")
        {
          std::cout << "\033[1;31m" <<"Exiting phonebook..." << "\033[0m" <<std::endl;
          break;
        }
        else if (option == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "Enter the first name: ";
            if (!std::getline(std::cin, firstName)) { std::cout << "\033[1;31m" <<"EOF detected. Exiting phonebook..." << "\033[0m" <<std::endl; break; }

            std::cout << "Enter the last name: "; 
            if (!std::getline(std::cin, lastName)) { std::cout << "\033[1;31m" <<"EOF detected. Exiting phonebook..." << "\033[0m" <<std::endl; break; }

            std::cout << "Enter the nickname: ";
            if (!std::getline(std::cin, nickname)) { std::cout << "\033[1;31m" <<"EOF detected. Exiting phonebook..." << "\033[0m" <<std::endl; break; }

            std::cout << "Enter the phone number: ";
            if (!std::getline(std::cin, phoneNumber)) { std::cout << "\033[1;31m" <<"EOF detected. Exiting phonebook..." << "\033[0m" <<std::endl; break; }

            std::cout << "Enter the darkest secret: ";
            if (!std::getline(std::cin, darkestSecret)) { std::cout << "\033[1;31m" <<"EOF detected. Exiting phonebook..." << "\033[0m" <<std::endl; break; }

            phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        }
        else if (option == "SEARCH")
        {
            std::string index = getValidIndex();
            phonebook.displayContact(std::stoi(index));
        }
        else if (option == "DISPLAY")
        {
            phonebook.displayContacts();
        }
        else
        {
          std::cout << "\033[1;31mInvalid option\033[0m" << std::endl;
        }
    }

    return 0;
}
