#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Assuming Book and Member classes are already defined from previous stages
// This implementation focuses on the Library class methods

class Library {
private:
    std::string libraryName;
    std::vector<std::unique_ptr<Book>> books;
    std::vector<std::unique_ptr<Member>> members;

public:
    // Constructor
    Library(const std::string& name) : libraryName(name) {
        // books and members vectors are automatically initialized as empty
    }

    // Disable copy constructor and copy assignment operator because std::unique_ptr is not copyable
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    // Getter for the library name
    std::string getLibraryName() const {
        return libraryName;
    }

    // Book management methods
    void addBook(std::unique_ptr<Book> book) {
        // Transfer ownership using std::move
        books.push_back(std::move(book));
    }

    Book* findBookByISBN(const std::string& isbn) const {
        // Iterate through all books to find matching ISBN
        for (const auto& book : books) {
            if (book->getISBN() == isbn) {
                return book.get(); // Return raw pointer, ownership stays with unique_ptr
            }
        }
        return nullptr; // Not found
    }

    void displayAllBooks() const {
        // Display details of all books (demonstrates polymorphism)
        for (const auto& book : books) {
            book->displayDetails();
            std::cout << std::endl;
        }
    }

    // Member management methods
    void registerMember(std::unique_ptr<Member> member) {
        // Transfer ownership using std::move
        members.push_back(std::move(member));
    }

    Member* findMemberByID(const std::string& memberID) const {
        // Iterate through all members to find matching ID
        for (const auto& member : members) {
            if (member->getMemberID() == memberID) {
                return member.get(); // Return raw pointer, ownership stays with unique_ptr
            }
        }
        return nullptr; // Not found
    }

    void displayAllMembers() const {
        // Display details of all members
        for (const auto& member : members) {
            member->displayDetails();
            std::cout << std::endl;
        }
    }
};