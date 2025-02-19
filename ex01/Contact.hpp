#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <ctime> // Allow us to use timers, to swithc old contacts to new ones

class Contact
{ 
  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    std::time_t _creationDate;

  public:
  
    // Constructors
    Contact();
    ~Contact();
    Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

    // Contact functions
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    std::time_t getCreationDate() const;
}

#endif