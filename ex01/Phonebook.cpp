#include "Phonebook.hpp"

int searchOldestContact(Contact contacts[MAX_CONTACTS], int contactsCount) 
{
    if (!contactsCount) 
      return -1;
    std::time_t oldest = contacts[0].getCreationDate();
    int oldestIndex = 0;

    for (int i = 1; i < contactsCount; i++)
    {
        if (contacts[i].getCreationDate() < oldest)
        {
            oldest = contacts[i].getCreationDate();
            oldestIndex = i;
        }
    }

    return oldestIndex;
}

Phonebook::Phonebook() 
{
    _contactsCount = 0;
}

Phonebook::~Phonebook() 
{

}

int Phonebook::getNumContacts() const 
{
    return _contactsCount;
}

void Phonebook::addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) 
{
    if (_contactsCount < MAX_CONTACTS) 
    {
      _contacts[_contactsCount] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        _contactsCount++;
        std::cout << "Contact added successfully" << std::endl;
    } 
    else 
    {
        int oldestIndex = searchOldestContact(_contacts, _contactsCount);
        _contacts[oldestIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        std::cout << "Contact added successfully" << std::endl;
    }
}

void Phonebook::displayContacts() const 
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < _contactsCount; i++) 
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _contacts[i].getFirstName() << "|";
        std::cout << std::setw(10) << _contacts[i].getLastName() << "|";
        std::cout << std::setw(10) << _contacts[i].getNickname() << std::endl;
    }
}
