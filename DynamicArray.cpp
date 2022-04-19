#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int capacity) {
    length = 0;
    this->capacity = capacity;
    data = new ElementType[capacity]();

    if (data == nullptr) {
        cerr << "DynamicArray(): failed to allocate memory" << endl;
        exit(-1);
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {

    if (this != &other) {
        length = other.length;
        capacity = other.capacity;

        delete[] this->data;
        data = new ElementType[other.capacity]();

        if (data == nullptr) {
            cerr << "operator=(): failed to allocate memory" << endl;
            exit(-1);
        }
        for (unsigned int i = 0; i < length; i++)
            data[i] = other.data[i];
    }
    return *this;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    length = other.length;
    capacity = other.capacity;

    data = new ElementType[other.capacity]();

    if (data == nullptr) {
        cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
        exit(-1);
    }
    for (unsigned int i = 0; i < length; i++)
        data[i] = other.data[i];
}

void DynamicArray::append(const ElementType& v, bool* err)
{
    if (length == capacity) {
        resize(capacity * 2);
    }
    Offer c{ v };
    data[length] = c;

    length++;
}

ostream& operator<<(ostream& s, const DynamicArray& arr) {
    for (unsigned int i = 0; i < arr.length; i++) {
        s << arr.data[i].to_string();
        s << "\n------------------------------\n";
    }
    return s;
}

ElementType& DynamicArray::get(unsigned int index) {

    if (index >= 0 && index < length) {
        return data[index];
    }
    else {
        cerr << "Precondition does not hold: get()" << endl;
        exit(-1);
    }
}

void DynamicArray::resize(unsigned int newCapacity) {

    this->capacity = newCapacity;

    ElementType* newData = new ElementType[newCapacity]();
    if (newData == nullptr) {
        cerr << "resize(): failed to allocate memory" << endl;
        exit(-1);
    }
    for (unsigned int i = 0; i < length; i++) {
        newData[i] = this->data[i];
    }

    delete[] this->data;
    this->data = newData;
}

