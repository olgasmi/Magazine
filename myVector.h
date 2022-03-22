#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstring> //size_t
#include <algorithm> // move
#include <stdexcept>
#include "product.h"

template<typename T>
class myVector{

    T* ptr = nullptr; // ptr to an array
    size_t vector_size = 0; // size_t can store the maximum size of a theoretically possible object of any type
    // vector_size - the number of elements contained in a vector
    size_t vector_capacity = 0; // vector_capacity - number of elements that can be added to a vector before the memory reallocation

    void reallocation(size_t new_vector_capacity)
    {
        T* n_ptr = new T[new_vector_capacity];

        for(size_t i = 0; i < vector_size; i++)
        {
            n_ptr[i] = std::move(ptr[i]);
        }

        delete [] ptr;
        ptr = n_ptr;
        vector_capacity = new_vector_capacity;
    }

public:

    size_t size() const { return vector_size; }
    T& operator[](size_t index) const { return ptr[index];}

    T& at(size_t index) const
    {
        if( index < 0 || index >= vector_size) throw std::out_of_range("Vector is out of range");
        else return ptr[index];
    }

    void push_back(T& something)
    {
        if( vector_size > vector_capacity)
            reallocation(2*vector_capacity); // reallocating memory through doubling the capacity

        ptr[vector_size] = something; //if push_back something size increments until reaches capacity
        vector_size++;
    }

    void erase(size_t index)
    {
        for( size_t i = index; i < vector_size; i++) ptr[i] = ptr[i+1];
        vector_size--;
    }


    myVector() { reallocation(3); }
    ~myVector() { delete [] ptr; }

};


#endif
