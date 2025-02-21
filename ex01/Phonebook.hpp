#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#define MAX_CONTACTS 8

class Phonebook
{
  private:
    Contact _contacts[MAX_CONTACTS];
    int _contactsCount;

  public:
    Phonebook();
    ~Phonebook();

    int getNumContacts() const;
    void addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
    void displayContacts() const;
    void displayContact(int index) const;
};

int searchOldestContact(Contact contacts[MAX_CONTACTS], int contactsCount);

#endif