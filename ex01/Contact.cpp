#include CONTACT_HPP

// Basic constructor
Contact::Contact()
{
  _firstName = "";
  _lastName = "";
  time(&_creationDate);
}
// Basic destructor
Contact::~Contact()
{

}

// Constructor with parameters
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
  _firstName = firstName;
  _lastName = lastName;
  _nickname = nickname;
  _phoneNumber = phoneNumber;
  _darkestSecret = darkestSecret;
  time(&_creationDate);
}

// Getters for the Contact class
std::string getFirstName() const
{
  return _firstName;
}

std::string getLastName() const
{
  return _lastName;
}

str::string getNickName() const 
{
  return _nickname;
}

std::string getPhoneNumber() const 
{
  return _phoneNumber;
}

std::string getDarkestSecret() const 
{
  return _darkestSecret;
}

std:time_t getCreationDate() const 
{
  return _creationDate;
}