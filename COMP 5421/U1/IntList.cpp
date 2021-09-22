#include "IntList.h"
#include <iostream>

using std::endl;
using std::ostream;
using std::cout;
/**
* Default Constructor, a list of capacity 1, and used=0
* declared as noexcept because the implementation should be reliable
*/
IntList::IntList() noexcept
{
    this->capacity = 1; // setting the capacity to 1
    this->used = 0; // setting the used to 0
    this->dynarray = new int[this->capacity]; //pointing dynarray to an array size intialized to capacity
}
/**
* copy constructor
* @param: const IntList&
* declared as noexcept because the implementation should be reliable
*/
IntList::IntList(const IntList& array) noexcept
{
    this->capacity = array.capacity; // assigning the rhs(array) capacity to invoking object capacity
    this->used = array.used; // assigning the rhs(array) used to invoking object used
    this->dynarray = new int[array.capacity]; // pointing dynarray to new array with size of rhs capacity
    for (size_t i = 0; i < unsigned(capacity); i++) // copying the rhs dynarray resources to lhs
        this->dynarray[i] = array.dynarray[i];
}
/**
* Move constructor
* @param: IntList&&
* declared as noexcept because the implementation should be reliable
*/
IntList::IntList(IntList&& array) noexcept
{
    this->capacity = array.capacity; // assigning the capacity of rhs to lhs(invoking object) capacity
    this->used = array.used; // assigning the used of rhs to lhs(invoking object) used
    this->dynarray = array.dynarray; // pointing the dynarray of lhs to rhs object, in other word stealing resources of rhs
    array.dynarray = nullptr; // pointing the rhs(array) dynarray pointer to null
}
/**
* Copy assignment operator, the parameter should be used const simply to dont let the function change the rhs object
* @param: const IntList&
* declared as noexcept because the implementation should be reliable
*/
IntList& IntList::operator=(const IntList& rhs) noexcept
{
    if (this != &rhs)  // checks whether the rhs is not equal to lhs
        delete[] dynarray; // freeing the dynarray space
        this->capacity = rhs.capacity; // assigning the capacity of rhs to lhs(invoking object) capacity 
        this->used = rhs.used; // assigning the used of rhs to lhs(invoking object) used
        this->dynarray = new int[rhs.capacity]; // pointing dynarray to new array with size of rhs capacity
        for (size_t i = 0; i < unsigned(capacity); ++i) // copying the rhs dynarray resources to lhs
            this->dynarray[i] = rhs.dynarray[i];
    return *this; 
}
/**
* Move assignment operator
* @param: IntList&&
* declared as noexcept because the implementation should be reliable
*/
IntList& IntList::operator=(IntList&& rhs) noexcept
{
    if (this != &rhs) // checks whether the rhs is not equal to lhs
        delete[] dynarray; // freeing the dynarray space
        this->capacity = rhs.capacity; // assigning the capacity of rhs to lhs(invoking object) capacity 
        this->used = rhs.used; // assigning the used of rhs to lhs(invoking object) used
        this->dynarray = rhs.dynarray; // pointing the dynarray of lhs to rhs object, in other word stealing resources of rhs
        rhs.dynarray = nullptr; // pointing the rhs(array) dynarray pointer to null
    return *this;
}
/**
* Deconstructor
* declared as noexcept because the implementation should be reliable
*/
IntList::~IntList() noexcept
{
    delete[] dynarray; // deleting the dynarray from heap memory in case of creating new dynarray
}
/**
* Determines whether used equals zero
* @return: bool(true,false)
*/
bool IntList::empty()
{
    if (this->used == 0) { return true; }
    return false;
}
/**
* Determines whether used equals capacity
* @return: bool(true,false)
*/
bool IntList::full() // Determines whether used equals capacity
{
    if (this->used == this->capacity) { return true; }
    return false;
}
/**
* A function to return used
* @return: Int
*/
int IntList::size()
{
    return this->used;
}
/**
* Determines whether used equals zero
* @return: void
*/
void IntList::resize() // double current capacity of the list
{
    IntList temp{ (*this) }; // copying the invoking object to a temporary IntList
    dynarray = new int[capacity *= 2]; // ponting the dynarray of invoking object to a new array with size of double the capacity
    for (size_t i = 0; i < unsigned(temp.size()); i++) // copying temp array to lhs(invoking object) array
    {
        this->dynarray[i] = temp.dynarray[i];
    }
}
/**
* Inserts x after the current last element in the list
* @param: int
* @return: void
*/
void IntList::pushBack(int x) 
{
    if ((*this).full()) { (*this).resize(); }// checks whether the invoking object's array is full, in that case it resize the array
    dynarray[this->used] = x; // inserting x at the end
    this->used++; // increasing the invoking object used
}
/**
* Determines whether x occurs in the list
* @param: int
* @return: bool(true or false)
*/
bool IntList::contains(int x) 
{
    for (size_t i = 0; i < unsigned(this->used); ++i) // traversing through the array to see whether x is in dynnarry or not
    {
        if (dynarray[i] == x) { return true; }
    }
    return false;


}
/**
* Returns false if position is out of range,
* otherwise, places the value stored at position
* in the reference parameter value and then returns true
* @param: int , int
* @return: bool(true or false)
*/
bool IntList::get(int position, int& value) 
{
    if (position <= used) // checking if object is in range or not
    {
        value = dynarray[position]; // placing the value at position
        return true;
    }
    return false;
}
/**
*  Return the allocated capacity of this list
* @return: int
*/
int IntList::getCapacity()
{
    return this->capacity;
}
/**
*  Prints the numbers in the list to the sout stream,
*  separating them by a comma followed by a space
* @param: ostream&
* @return: void
*/
void IntList::print(ostream& sout) // 
{
    for (int i = 0; i < used; i++) // traversing through dynarry
    {
        sout << dynarray[i] << ", "; // extracting dynarray members to ostream object
    } 
    sout << endl;
}
/**
*  a function to get access to private member dynarray at index of x
* @param: int
* @return: int
*/
int IntList::getDynarray(int x) const {
    return this->dynarray[x];
}

