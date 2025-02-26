#include "Contact.hpp"
#include "Phonebook.hpp"

#include <iostream>
#include <limits>
#include <ctype.h>

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

bool isValidPhoneNumber(const std::string &phone) {
    return !phone.empty() && std::all_of(phone.begin(), phone.end(), ::isdigit);
}

std::string getInput(const std::string &prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << "\033[1;31mEOF detected. Exiting phonebook...\033[0m" << std::endl;
            exit(0);
        }
        if (!input.empty()) break;
        std::cout << "\033[1;31mInput cannot be empty. Please try again.\033[0m" << std::endl;
    }
    return input;
}

int main() {
    Phonebook phonebook;
    std::string option;

    std::cout << "Welcome to the phonebook!" << std::endl;

    while (true) {
        std::cout << "\033[1;36mChoose an option: ADD, SEARCH, EXIT\033[0m" << std::endl;
        if (!std::getline(std::cin, option)) {
            std::cout << "\033[1;31mEOF detected. Exiting phonebook...\033[0m" << std::endl;
            break;
        }

        if (option == "EXIT") {
            std::cout << "\033[1;31mExiting phonebook...\033[0m" << std::endl;
            break;
        }
        else if (option == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            do {
                firstName = getInput("Enter the first name: ");
                lastName = getInput("Enter the last name: ");
                nickname = getInput("Enter the nickname: ");

                do {
                    phoneNumber = getInput("Enter the phone number: ");
                    if (!isValidPhoneNumber(phoneNumber)) {
                        std::cout << "\033[1;31mInvalid phone number. Only digits are allowed.\033[0m" << std::endl;
                    }
                } while (!isValidPhoneNumber(phoneNumber));

                darkestSecret = getInput("Enter the darkest secret: ");

            } while (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty());

            phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            std::cout << "\033[1;32mContact saved successfully!\033[0m" << std::endl;
        }
        else if (option == "SEARCH") {
            std::string index = getValidIndex();
            phonebook.displayContact(std::stoi(index));
        }
        else if (option == "DISPLAY") {
            phonebook.displayContacts();
        }
        else {
            std::cout << "\033[1;31mInvalid option\033[0m" << std::endl;
        }
    }

    return 0;
}
