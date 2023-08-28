#include <iostream>
#include <vector>
#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phone, const std::string& email)
        : name(name), phone(phone), email(email) {}

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }

private:
    std::string name;
    std::string phone;
    std::string email;
};

class ContactManager {
public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        std::cout << "Contact added successfully!" << std::endl;
    }

    void viewContacts() const {
        std::cout << "\n--- Contacts ---" << std::endl;
        for (size_t i = 0; i < contacts.size(); ++i) {
            const Contact& contact = contacts[i];
            std::cout << i + 1 << ". Name: " << contact.getName() << ", Phone: " << contact.getPhone()
                      << ", Email: " << contact.getEmail() << std::endl;
        }
    }

    void searchContacts(const std::string& query) const {
        std::cout << "\n--- Search Results ---" << std::endl;
        bool found = false;
        for (const Contact& contact : contacts) {
            if (contact.getName().find(query) != std::string::npos ||
                contact.getEmail().find(query) != std::string::npos) {
                std::cout << "Name: " << contact.getName() << ", Phone: " << contact.getPhone()
                          << ", Email: " << contact.getEmail() << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No matching contacts found." << std::endl;
        }
    }

private:
    std::vector<Contact> contacts;
};

int main() {
    ContactManager contactManager;

    while (true) {
        std::cout << "\nContact Management System" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. View Contacts" << std::endl;
        std::cout << "3. Search Contacts" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phone, email;
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                Contact newContact(name, phone, email);
                contactManager.addContact(newContact);
                break;
            }
            case 2:
                contactManager.viewContacts();
                break;
            case 3: {
                std::string query;
                std::cout << "Enter search query: ";
                std::cin.ignore();
                std::getline(std::cin, query);
                contactManager.searchContacts(query);
                break;
            }
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please choose again." << std::endl;
        }
    }

    return 0;
}
