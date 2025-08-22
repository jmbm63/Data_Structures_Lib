#include <iostream>
using namespace std;

/**
 * @brief Vector library
 *
 * Works as a resizeable array
 * The difference between a vector and a regular array is that a vector...
 * can change its size dynamically.
 *
 * By using only the vector function itself we can observe the front of the vector (vector.front()),
 * a certain value on position vector[i] (where i is the index), the back of the vector (vector.back()),
 * and the size of the vector (vector.size()), capacity (vector.capacity() that is the number of values the vector can hold.
 *
 * vector.push_back(value) adds a new element to the end of the vector.
 * vector.pop_back() removes the last element of the vector.
 * vector.insert(position, value) inserts a new element at the specified position.
 * vector.erase(position) removes the element at the specified position.
 */

template <typename T>
class Vector {

    private:
        // var
        T* data;        // pointer to the actual array
        size_t sz;      // number of elements currently in use
        size_t cap;     // total allocated capacity

        //fun
        void resize(size_t new_cap);

    public:
        Vector() : data(nullptr), sz(0), cap(0) {} // constructor

        ~Vector() { // destructor
            delete[] data;
        }

        //fun
        void push_back(const T& value);
        T& operator[](size_t index);
        size_t size() const;

};


template <typename T>
void Vector<T>::resize(size_t new_cap) {
    T* new_data = new T[new_cap];
    for (size_t i = 0; i < sz; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    cap = new_cap;
}


template <typename T>
void Vector<T>::push_back(const T& value) {
    if (sz == cap) {
        resize((cap == 0) ? 1 : cap * 2);
    }
    data[sz++] = value;
}


template <typename T>
T& Vector<T>::operator[](size_t index) {
    return data[index];
}


template <typename T>
size_t Vector<T>::size() const {
    return sz;
}