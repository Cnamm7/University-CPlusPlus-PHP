#ifndef INTLIST_H
#define INTLIST_H

#include <ostream>
#include <iostream>


class IntList {
private:


    int capacity;
    int used;
    int* dynarray;

    void resize(); // Double the current capacity of the list

public:


    IntList() noexcept; // Default Constructor, a list of capacity 1, and used=0
    IntList(const IntList& array) noexcept; // Copy constructor
    IntList(IntList&& array) noexcept; // Move constructor
    IntList& operator=(const IntList& rhs) noexcept; // Copy assignment operator
    IntList& operator=(IntList&& rhs) noexcept; // Move assignment operator
    virtual ~IntList() noexcept; // Destructor (and a virtual one in this example)


    bool empty(); // Determines whether used equals zero
    bool full(); // Determines whether used equals capacity
    int size(); // Returns used
    void pushBack(int x); // Inserts x after the current last element in the list
    bool contains(int x); // Determines whether x occurs in the list
    bool get(int position, int& value); // Returns false if position is out of range;
                                        // otherwise, places the value stored at position
                                        // in the reference parameter value and then returns true

    int getCapacity(); // Return the allocated capacity of this list
    int getDynarray(int x) const; // I write this because we need access to dynarray in Token
    void print(std::ostream& sout); // Prints the numbers in the list to the sout stream,
                                    // separating them by a comma followed by a space   

};
#endif // INTLIST_H
