#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact{

    std::string fullName, company, number, email, address, note;
    
    public:
        Contact();
        Contact(std::string, std::string, std::string, std::string, std::string, std::string);
        Contact(const Contact& rhs);
        
        std::string getFullName();
        void setFullName(std::string);
        std::string getCompany();
        void setCompany(std::string);
        std::string getNumber();
        void setNumber(std::string);
        std::string getEmail();
        void setEmail(std::string);
        std::string getAddress();
        void setAddress(std::string);
        std::string getNote();
        void setNote(std::string);

        void printContact();
        void editContact(Node);
        ~Contact();

        int getSortNum(int);



};

#endif