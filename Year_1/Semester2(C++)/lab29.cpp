class container {
private:
    int *box;    // Pointer to an integer array
    int len;     // Length of the array
    int index;   // Current index

public:
    // Default constructor
    container(void) : box(NULL), len(0), index(-1) {}

    // Get length of the array
    int getLen() {
        return len;
    }

    // Get current index
    int getIndex() {
        return index;
    }
};