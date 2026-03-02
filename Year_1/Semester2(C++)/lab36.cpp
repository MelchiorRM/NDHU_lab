#include <iostream>
#include <string>

class Book {
protected:
    std::string isbn;
    std::string title;
    std::string author;
    std::string publisher;
    int publicationYear;
    bool isBorrowed;
    std::string borrowedByMemberID;

public:
    // Constructor
    Book(const std::string& isbn, const std::string& title, const std::string& author,
         const std::string& publisher, int publicationYear)
        : isbn(isbn), title(title), author(author), publisher(publisher),
          publicationYear(publicationYear), isBorrowed(false), borrowedByMemberID("") {}

    // Virtual Destructor
    virtual ~Book() {}

    // Getter methods (all const)
    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getPublisher() const { return publisher; }
    int getPublicationYear() const { return publicationYear; }
    bool getIsBorrowed() const { return isBorrowed; }
    std::string getBorrowedByMemberID() const { return borrowedByMemberID; }

    // Setter method
    void setBorrowed(bool borrowed, const std::string& memberID = "") {
        if (borrowed) {
            isBorrowed = true;
            borrowedByMemberID = memberID;
        } else {
            isBorrowed = false;
            borrowedByMemberID = "";
        }
    }

    // Virtual display method (const)
    virtual void displayDetails() const {
        std::cout << "ISBN: " << isbn << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Publisher: " << publisher << std::endl;
        std::cout << "Publication Year: " << publicationYear << std::endl;
        if (isBorrowed) {
            std::cout << "Status: Borrowed by " << borrowedByMemberID << std::endl;
        } else {
            std::cout << "Status: In Library" << std::endl;
        }
    }
};