#include "helpers.h"
//AVL tree from GeeksForGeeks.org/insertion-in-an-avl-tree/
//added functionality for sorting using contact names
int height(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return N->height; 
}  
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;
}

int getBalance(Node *N) {
    return (N == nullptr) ? 0 : height(N->left) - height(N->right);
}

Node *insert(Node *node, Contact contact) {
    if (node == nullptr)
        return new Node(contact);

    if (contact.getFullName() < node->contact.getFullName())
        node->left = insert(node->left, contact);
    else if (contact.getFullName() > node->contact.getFullName())
        node->right = insert(node->right, contact);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && contact.getFullName() < node->left->contact.getFullName())
        return rightRotate(node);

    if (balance < -1 && contact.getFullName() > node->right->contact.getFullName())
        return leftRotate(node);

    if (balance > 1 && contact.getFullName() > node->left->contact.getFullName()) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && contact.getFullName() < node->right->contact.getFullName()) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root) {
    if (root != nullptr) {
        root->contact.printContact();
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root->left);
        root->contact.printContact();
        inOrder(root->right);
    }
}

int promptChoice() {
    int choice;
    std::cout << "\nMenu Options:\n"
              << "1. View All Contacts\n"
              << "2. Search for a Contact\n"
              << "0. Exit\n"
              << "Enter your choice: ";
    while (true) {
        std::cin >> choice;
        if(choice < 2 && choice >= 0){
            return choice;
        } else{
            std::cout << "Invalid option. Choose again: " << std::endl;
        }
    }
}
void searchForContact(Node *root){
    if (root == nullptr) {
        std::cout << "No contacts available to search.\n";
        return;
    }

    std::string query;
    std::cout << "Enter the name or part of the name to search: ";
    std::getline(std::cin, query);

    bool found = false;

    // Helper function to perform an in-order traversal and search
    auto searchInOrder = [&](Node *node, const std::string &query, bool &found) {
        if (node == nullptr) return;

        searchInOrder(node->left, query, found);

        std::string contactName = node->contact.getFullName();
        if (contactName.find(query) != std::string::npos) {
            found = true;
            std::cout << "Found Contact:\n";
            node->contact.printContact();
            std::cout << "------------------------\n";
        }

        searchInOrder(node->right, query, found);
    };

    searchInOrder(root, query, found);

    if (!found) {
        std::cout << "No contact matches the search query: " << query << "\n";
    }
}

void importContacts(Node& root) {
    std::ifstream file("contacts.txt");
    if (!file) {
        std::cerr << "Error: Unable to open the file 'contacts.txt'.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string fullName, company, number, email, address, note;

        std::getline(ss, fullName, ',');
        std::getline(ss, company, ',');
        std::getline(ss, number, ',');
        std::getline(ss, email, ',');
        std::getline(ss, address, ',');
        std::getline(ss, note, ',');

        Contact contact(fullName, company, number, email, address, note);
        Node* rootPtr = &root;
        rootPtr = insert(rootPtr, contact);
    }

    file.close();
}