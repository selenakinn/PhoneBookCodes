#include <iostream>
#include <map>
#include <algorithm>

class PhoneBook {
private:
    std::map<std::string, std::string> contacts;

public:
    void insertContact(const std::string& name, const std::string& number) {
        contacts[name] = number;
    }
    // Creating a function to insert a new person name and contact number into this phonebook.

    std::string searchContact(const std::string& name) {
        auto it = contacts.find(name);
        return (it != contacts.end()) ? it->second : "Contact not found";
    }
    // Creating a function to search this phonebook for a contact number efficiently.

    void listContacts() {
        for (const auto& contact : contacts) {
            std::cout << contact.first << ": " << contact.second << std::endl;
        }
    }
    // Creating a function to list whole contact names in the phonebook according to alphabetical order.

    void listContactsInInterval(const std::string& start, const std::string& end) {
        auto startIt = contacts.lower_bound(start);
        auto endIt = contacts.upper_bound(end);

        for (auto it = startIt; it != endIt && it != contacts.end(); ++it) {
            std::cout << it->first << ": " << it->second << std::endl;
        }
    }
    // Creating a function to search and list efficiently a group of contact persons given an interval of two contact names.

    void deleteContact(const std::string& name) {
        contacts.erase(name);
    }
    // Creating a function to delete a contact name and its contact number from the phonebook.

    void updateContact(const std::string& name, const std::string& newNumber) {
        contacts[name] = newNumber;
    }
    // Creating a function to update the contact number of a contact name in the phonebook.

    int countContacts() {
        return contacts.size();
    }
	// Creating a function to list the count of persons in the phonebook.
};

int main() {
    PhoneBook phoneBook;
    phoneBook.insertContact("Ayse", "534 456 7890");
    phoneBook.insertContact("Beyza", "542 654 3210");
    phoneBook.insertContact("Cenk", "544 563 2345");
    phoneBook.insertContact("Hasan", "532 342 4234");
    phoneBook.insertContact("Derya", "543 950 4590");
	//Creating a phonebook list.
	
    std::cout << "Search Beyza: " << phoneBook.searchContact("Beyza") << std::endl<<std::endl;
	//Searching for Beyza from the list.
	
    std::cout << "All Contacts:" << std::endl;
    phoneBook.listContacts();
	std::cout<<std::endl;
	//Printing the entire list on the screen.
	
	std::cout << "Communication from Hasan to Ayse:" << std::endl;
	phoneBook.listContactsInInterval("Hasan", "Ayse");
	std::cout << std::endl;
	//Communication from Hasan to Ayþe
	
    phoneBook.deleteContact("Cenk");
    std::cout << "After Deleting Cenk:" << std::endl;
	phoneBook.listContacts();
	std::cout<<std::endl;
	//Deleting Cenk's number and then wrote the list.
	
    phoneBook.updateContact("Derya", "555 123 4567");
	std::cout << "After Updating Derya's Number:" << std::endl;
	phoneBook.listContacts();
	std::cout << std::endl;
	//Deleting Derya's number and then wrote her new number.
    
    std::cout << "Total Contacts: " << phoneBook.countContacts() << std::endl;
	//Printing out how many people are registered in the list.
	
    return 0;
}
