#ifndef HELPERS_H
#define HELPERS_H

#include "contact.h"

struct Node { 
    Contact contact; 
    Node *left; 
    Node *right; 
    int height; 

    Node(Contact c) { 
        contact = c; 
        left = nullptr; 
        right = nullptr; 
        height = 1; 
    }
}; 

int height(Node *N);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node *insert(Node *node, Contact contact);
void preOrder(Node *root);
void inOrder(Node *root);
int promptChoice();
void viewAllContacts(Node *root);
void searchForContact(Node *root);
void importContacts(Node& root);

#endif