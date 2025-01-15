#include "contact.h"

Contact::Contact(){
    fullName = "";
    company = "";
    number = ""; 
    email = "";
    address = "";
    note = "";
}
Contact::Contact(std::string full, std::string comp, std::string num, std::string ema, std::string addre, std::string no){
    fullName = full;
    company = comp;
    number = num; 
    email = ema;
    address = addre;
    note = no;
}
Contact::Contact(const Contact& rhs){
    fullName = rhs.fullName;
    company = rhs.company;
    number = rhs.number; 
    email = rhs.email;
    address = rhs.address;
    note = rhs.note;
}
std::string Contact::getFullName() {
    return fullName;
}
void Contact::setFullName(std::string name) {
    fullName = name;
}
std::string Contact::getCompany() {
    return company;
}
void Contact::setCompany(std::string comp) {
    company = comp;
}
std::string Contact::getNumber() {
    return number;
}
void Contact::setNumber(std::string num) {
    number = num;
}
std::string Contact::getEmail() {
    return email;
}
void Contact::setEmail(std::string mail) {
    email = mail;
}
std::string Contact::getAddress() {
    return address;
}
void Contact::setAddress(std::string addr) {
    address = addr;
}
std::string Contact::getNote() {
    return note;
}
void Contact::setNote(std::string notes) {
    note = notes;
}
void Contact::printContact() {
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Company: " << company << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Note: " << note << std::endl;
}
Contact::~Contact() {

}

int Contact::getSortNum(int num) {
    return fullName.empty() ? 0 : static_cast<int>(tolower(fullName[num]));
}