//Project: Address Book
//Time: Winter 2025
//Author: Aidan Madonna

#include "helpers.h" 

int main(){
    int choice;
    Node root;
    importContacts(root);
    do{
        Node* rootPointer = &root;
        std::cout << "Address Book" << std::endl << "Created by Aidan Madonna" << std::endl;
        choice = promptChoice();
        switch (choice){
            case 1: //view
                viewAllContacts(rootPointer);
                break;
            case 2: //search
                searchForContact(rootPointer);
                break;
            case 0: //close
                break;
            default:
                std::cout << "Invalid Choice. Try again." << std::endl;
        }
    }while (choice != 0);
}