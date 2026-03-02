#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Member {
private:
    std::string memberID;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::vector<std::string> borrowedBookISBNs;
    int maxBooksAllowed;

public:
    // Constructor
    Member(const std::string& memberID, const std::string& name, int maxBooks = 5,
           const std::string& address = "", const std::string& phone = "")
        : memberID(memberID), name(name), address(address), phoneNumber(phone),
          maxBooksAllowed(maxBooks) {}

    // Getters
    std::string getMemberID() const { return memberID; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getPhoneNumber() const { return phoneNumber; }
    const std::vector<std::string>& getBorrowedBookISBNs() const { return borrowedBookISBNs; }
    int getMaxBooksAllowed() const { return maxBooksAllowed; }
    int getBorrowedBooksCount() const { return static_cast<int>(borrowedBookISBNs.size()); }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setAddress(const std::string& newAddress) { address = newAddress; }
    void setPhoneNumber(const std::string& newPhone) { phoneNumber = newPhone; }
    void setMaxBooksAllowed(int maxBooks) {
        if (maxBooks >= 0) {
            maxBooksAllowed = maxBooks;
        }
    }

    // Borrowing-related methods
    bool canBorrowMoreBooks() const {
        return getBorrowedBooksCount() < maxBooksAllowed;
    }

    bool borrowBookISBN(const std::string& isbn) {
        if (!canBorrowMoreBooks()) {
            return false;
        }
        // Avoid duplicate ISBNs
        if (std::find(borrowedBookISBNs.begin(), borrowedBookISBNs.end(), isbn) != borrowedBookISBNs.end()) {
            return false;
        }
        borrowedBookISBNs.push_back(isbn);
        return true;
    }

    bool returnBookISBN(const std::string& isbn) {
        auto it = std::find(borrowedBookISBNs.begin(), borrowedBookISBNs.end(), isbn);
        if (it != borrowedBookISBNs.end()) {
            borrowedBookISBNs.erase(it);
            return true;
        }
        return false;
    }

    // Display method
    void displayDetails() const {
        std::cout << "Member ID: " << memberID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Phone: " << phoneNumber << std::endl;
        std::cout << "Max Books Allowed: " << maxBooksAllowed << std::endl;
        std::cout << "Books Borrowed: " << getBorrowedBooksCount() << std::endl;
        std::cout << "Borrowed ISBNs: ";
        for (size_t i = 0; i < borrowedBookISBNs.size(); ++i) {
            std::cout << borrowedBookISBNs[i];
            if (i != borrowedBookISBNs.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

// Helper function used in main to print borrowed ISBNs from main
void printBorrowedISBNsFromMain(const Member& member) {
    const auto& isbns = member.getBorrowedBookISBNs();
    std::cout << "Borrowed ISBNs (checked from main): ";
    for (size_t i = 0; i < isbns.size(); ++i) {
        std::cout << isbns[i];
        if (i != isbns.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

