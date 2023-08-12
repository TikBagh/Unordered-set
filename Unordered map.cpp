#include <iostream>
#include <unordered_set>


template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[newCapacity];

            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        data[size++] = value;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

};

int main() {
    
    Vector<int> intVector;

    intVector.push_back(5);
    intVector.push_back(10);
    intVector.push_back(15);
    intVector.push_back(5);
    intVector.push_back(11);
    intVector.push_back(12);

    std::unordered_set<int> intSet(std::make_move_iterator(intVector.begin()), std::make_move_iterator(intVector.end()));

    for (int num : intSet) {
        std::cout << num << " ";
    }

    

    return 0;
}

