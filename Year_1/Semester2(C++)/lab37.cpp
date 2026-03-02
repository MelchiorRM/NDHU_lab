// 定義小說類型列舉 (Define fiction genre enum)
enum class FictionGenre {
    SCIENCE_FICTION,
    FANTASY,
    MYSTERY,
    THRILLER,
    ROMANCE,
    HISTORICAL_FICTION,
    HORROR,
    OTHER
};

// Helper function to convert FictionGenre to string
std::string genreToString(FictionGenre genre) {
    switch (genre) {
        case FictionGenre::SCIENCE_FICTION:
            return "Science Fiction";
        case FictionGenre::FANTASY:
            return "Fantasy";
        case FictionGenre::MYSTERY:
            return "Mystery";
        case FictionGenre::THRILLER:
            return "Thriller";
        case FictionGenre::ROMANCE:
            return "Romance";
        case FictionGenre::HISTORICAL_FICTION:
            return "Historical Fiction";
        case FictionGenre::HORROR:
            return "Horror";
        case FictionGenre::OTHER:
            return "Other";
        default:
            return "Unknown";
    }
}

class FictionBook : public Book { // 公開繼承 Book (Publicly inherit from Book)
private:
    FictionGenre genre;

public:
    // Constructor
    FictionBook(const std::string& isbn, const std::string& title, const std::string& author,
                const std::string& publisher, int publicationYear, FictionGenre genre)
        : Book(isbn, title, author, publisher, publicationYear), genre(genre) {}

    // Getter
    FictionGenre getGenre() const {
        return genre;
    }

    // Setter
    void setGenre(FictionGenre genre) {
        this->genre = genre;
    }

    // Overridden displayDetails method
    void displayDetails() const override { // 使用 override 關鍵字 (Use the override keyword)
        Book::displayDetails(); // Call parent class method first
        std::cout << "Genre: " << genreToString(genre) << std::endl;
    }
};

class NonFictionBook : public Book { // 公開繼承 Book (Publicly inherit from Book)
private:
    std::string deweyDecimalNumber;
    std::string subjectArea;

public:
    // Constructor
    NonFictionBook(const std::string& isbn, const std::string& title, const std::string& author,
                   const std::string& publisher, int publicationYear,
                   const std::string& dewey, const std::string& subject)
        : Book(isbn, title, author, publisher, publicationYear), 
          deweyDecimalNumber(dewey), subjectArea(subject) {}

    // Getters
    std::string getDeweyDecimalNumber() const {
        return deweyDecimalNumber;
    }

    std::string getSubjectArea() const {
        return subjectArea;
    }

    // Setters
    void setDeweyDecimalNumber(const std::string& dewey) {
        deweyDecimalNumber = dewey;
    }

    void setSubjectArea(const std::string& subject) {
        subjectArea = subject;
    }

    // Overridden displayDetails method
    void displayDetails() const override { // 使用 override 關鍵字 (Use the override keyword)
        Book::displayDetails(); // Call parent class method first
        std::cout << "Dewey Decimal: " << deweyDecimalNumber << std::endl;
        std::cout << "Subject Area: " << subjectArea << std::endl;
    }
};