#include <iostream>
template<typename T>
class MyVector{
    private:
        T* _data;
        size_t size;
        size_t capacity;
    public:
        MyVector(): _data(nullptr), size(0), capacity(0) {
            std::cout << "Default constructor called" << std::endl;
        }
        ~MyVector() {
            if(_data){
            delete[] data;
            }
            std::cout << "Destructor called" << std::endl;
        }
        void push_back(const T& value){
            if(size==capacity){
                size_t newCapacity= (capacity==0)? 1: capacity*2;
                T* newData= new T[newCapacity];
                for(size_t i=0; i<size; ++i){
                    newData[i]= data[i];
                }
                delete[] data;
                data= newData;
                capacity= newCapacity;
            }
            data[size]= value;
            ++size;
        }
        void pop_back(){
            if(size==0){
                throw std::out_of_range("Vector is empty");
            }
            --size;
            data[size].~T();
        }
        void resize(size_t newSize){}
        MyVector operator=(const MyVector& other){
            if(this =&other){
            return *this;
        }
        if (_data){
            delete[] _data;
        }
        size = other.size;
        capacity= other.capacity;
        _data= new T[capacity];
        for(size_t i=0; i<size; ++i){
            _data[i]= other._data[i];
        }
        return *this;
        }
        const T& at(size_t index) const{
            if(index >= size){
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }
};
int main() {

    std::cout << "This is a test file for C++17 standard." << std::endl;
    return 0;
}