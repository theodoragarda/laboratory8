#pragma once
#include <string>
#include <ostream>
#include "Offer.h"
using namespace std;

typedef Offer ElementType;

class DynamicArray
{
public:
    DynamicArray(int capacity = 100);

    ~DynamicArray();

    DynamicArray(const DynamicArray& other);

    DynamicArray& operator=(const DynamicArray& other);

    inline unsigned int getLength() const { return length; }
    inline unsigned int getCapacity() const { return capacity; }
    void append(const ElementType& v, bool* err = nullptr);

    ElementType popBack();
    ElementType remove(unsigned int index);
    ElementType& get(unsigned int index);

    friend ostream& operator<<(ostream& s, const DynamicArray& arr);
private:
    static int count;
    unsigned int length;
    unsigned int capacity;
    ElementType* data;

    void resize(unsigned int newCapacity);
};

