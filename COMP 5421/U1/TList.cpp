#include "TList.h"
#include <iostream>

using std::cout;
using std::endl;
/**
* initializes this list to an empty list at construction
* @return: void
*/
void TList::init()
{
    // initialize to an empty list
    this->theSize = 0;
    headerPtr = new TNode{}; // headerPtr will always point to this
    // allocated fixed header node

    trailerPtr = new TNode{}; // trailerPtr will always point to this
    // allocated fixed header node

    headerPtr->next = trailerPtr; // header node’s next points to the trailer node
    trailerPtr->prev = headerPtr; // trailer node’s prev points to the header node

}
/**
* Default constructor, creates an empty list
* declared as noexcept because the implementation should be reliable
*/
TList::TList() noexcept
{
    init();
}
/**
* Copy constructor
* @param: const TList&
* declared as noexcept because the implementation should be reliable
*/
TList::TList(const TList& list) noexcept 
{
    init(); // creat an empty list
    if (list.empty()) { return; } // if list is equal to empty simply return

    TNode* current = list.headerPtr->next; // point to first node in original list
    while (current != list.trailerPtr) {
        TNode* newNode = new TNode{current->theToken, trailerPtr->prev,
                                   trailerPtr}; // point new node prev to last node and new node next to trailer
        trailerPtr->prev->next = newNode; // point last node next to new node
        trailerPtr->prev = newNode;   // point dummytail prev to new node
        ++theSize; // increase the size by 1
        current = current->next; // point to the following node in original list
    }
}
/**
* Move constructor
* @param: TList&&
* declared as noexcept because the implementation should be reliable
*/
TList::TList(TList&& list) noexcept
{
    // move resources from list:
    this->theSize = list.size(); // assign the rhs size to lhs size
    this->headerPtr = list.headerPtr; // assign the rhs header pointer to lhs header pointer
    this->trailerPtr = list.trailerPtr; // assign the rhs trailer pointer to lhs header pointer

    // leave list in stable state (here an empty list)
    list.theSize = 0; // assigning the size of rhs to 0
    list.headerPtr = new TNode{}; // assigning the header pointer to a new empty node
    list.trailerPtr = new TNode{}; // assigning the trailer pointer to a new empty node
    list.headerPtr->next = trailerPtr; // pointing the next ponter of header to trailer node
    list.trailerPtr->prev = headerPtr; // pointing the previous pointer of trailer to header node
}
/**
* Copy assignment operator, the parameter should be used const simply to dont let the function change the rhs object
* @param: const IntList&
* declared as noexcept because the implementation should be reliable
*/
TList& TList::operator=(const TList& rhs) noexcept
{
    if (this == &rhs) // checkes whether the lhs is equal to rhs, and in case of equality, return self
    {
        return *this;
    }
    while (!(this->empty())) // removing the lhs list incase of not being empty
    {
        this->removeFront(); // using the removeFront function to empty the list
    }
    TNode* current = rhs.headerPtr->next; // point to first node in original list
    while (current != rhs.trailerPtr) {
        TNode* newNode = new TNode{ current->theToken, trailerPtr->prev,
                                   trailerPtr }; // point new node prev to last node and new node next to trailer
        trailerPtr->prev->next = newNode; // point last node next to new node
        trailerPtr->prev = newNode;   // point dummytail prev to new node
        ++theSize;
        current = current->next; // point to the following node in original list
    }  
}
/**
* Move assignment operator
* @param: IntList&&
* declared as noexcept because the implementation should be reliable
*/
TList& TList::operator=(TList&& rhs) noexcept //Move assignment operator
{
    if (this == &rhs) // checkes whether the lhs is equal to rhs, and in case of equality, return self
    {
        return *this;
    }
    while (!(this->empty())) // removing the lhs list incase of not being empty
    {
        this->removeFront(); // using the removeFront function to empty the list
    }
    // the header and trailer nodes are left behind

    // move rhs's list element (not rhs's header and trailer nodes)
    this->theSize = rhs.size(); // assigning the rhs size to lhs size
    (this->headerPtr)->next = (rhs.headerPtr)->next; // assigning the next pointer of lhs to the node which the next pointer of rhs points to
    (this->trailerPtr)->prev = (rhs.trailerPtr)->prev; // assigning the previous pointer of lhs to the node which the previous pointer of rhs points to

    // leave list in stable state (here an empty list)
    rhs.theSize = 0; // assigning the size of rhs to 0
    rhs.headerPtr->next = rhs.trailerPtr; // pointing the next pointer of header to trailer node
    rhs.trailerPtr->prev = rhs.headerPtr; // pointing the previous pointer of trailer to header node

    return *this;
}
/**
* Destructor (and a virtual one in this example)
* declared as noexcept because the implementation should be reliable
*/
TList::~TList() noexcept
{
    while (!empty()) {removeFront(); } // removing the list using removeFront function
    delete headerPtr; // deleting the header pointer
    delete trailerPtr; // deleting the trailer pointer
}
/**
* Determines whether this list is empty
* @return: bool(true,false)
*/
bool TList::empty() const
{
    if (headerPtr->next == trailerPtr && trailerPtr->prev == headerPtr && theSize == 0) return true; // checks if header next point is pointing to trailer and trailer previous point is ponting to header and if the size is equal to 0
                                                                                                     // so by these conditions, return true
    return false;
}
/**
* Retruns the token at the front of this list
* @return: const Token&
*/
const Token& TList::front() const
{
    if(this->empty() != true) return headerPtr->next->theToken; // returning the token after the header pointer, by validating the emptiness of the invoking object list
    throw std::invalid_argument("the list is empty."); // in case of invoking object list is being empty, it simply throws an exception
}
/**
* Retruns the token at the back of this list
* @return: const Token&
*/
const Token& TList::back() const
{
    if (this->empty() != true) return trailerPtr->prev->theToken; // returning the token before the trailer pointer, by validating the emptiness of the invoking object list
    throw std::invalid_argument("the list is empty."); // in case of invoking object list is being empty, it simply throws an exception
}
/**
* Adds aToken at its sorted position into the list so as
* to maintain the ascending order of the list
* @param: const Token&
* @return: void
*/
void TList::addSorted(const Token& aToken)
{
    TNode* nodePtr = lookup(aToken); // pointing a pointer to aToken, by validating if aToken is in the list it points to aToken pointing object, and if its not, points in to trailer pointer
    if (nodePtr == trailerPtr) { // in case of not finding the aToken in the list, it simply add aToken to the before of trailer pointer

        addBefore(trailerPtr, aToken);

    }
    else if ((nodePtr->theToken).compare(aToken) == 0) { // in case of finding aToken in the list, appending the line number to the nmuberlist of existing object

        int lineNum = aToken.getLineNumber();
        (nodePtr->theToken).addLineNumber(lineNum);
    }
    else {

        addBefore(nodePtr, aToken); 
    }
    return;
}
/**
* if the list is nonempty, removes the node at the front
* of the list and returns true; otherwise, returns false
* @return: bool (true, false)
*/
bool TList::removeFront() 
{
    if (theSize != 0) // checks whether the object size is not equal to zero or in other word if list is empty or not
    {
        TNode* Pointer = headerPtr->next; // creats a TNode pointer and point it to the first Node in the list
        (Pointer->next)->prev = headerPtr; // points the previous pointer of created object to the header pointer
        headerPtr->next = Pointer->next; // points the header pointer next to created object next
        delete Pointer; // here simply delete the pointer object, infact deleting the object which it points to
        --theSize; // reducing the size by 1
        return true;
    }
    return false;
}
/**
* if the list is nonempty, removes the node at the end
* of the list and returns true; otherwise, returns false
* @return: bool (true, false)
*/
bool TList::removeBack() 

{
    if (theSize != 0)
    {
        TNode* Pointer = trailerPtr->prev; // creats a TNode pointer and point it to the last Node in the list
        (Pointer->prev)->next = trailerPtr; // points the previous pointer of created object to the trailer pointer
        trailerPtr->prev = Pointer->prev; // points the header pointer next to created object next
        delete Pointer; // here simply delete the pointer object, infact deleting the object which it is points to
        --theSize; // reducing the size by 1
        return true;
    }
    return false;
}
/**
* Returns theSize
* @return: int
*/
int TList::size() const 
{
    return this->theSize;
}
/**
* Prints the entire list
* @param: ostream&
* @return: void
*/
void TList::print(ostream& sout) const
{
    TNode* temp = headerPtr->next; // creating a TNode pointer which is pointing to the first object of the list
    while (temp != trailerPtr) { // checking whether if temp(created pointer) is pointing to the trailer pointer or not, using while loop, for traversing through list
        sout << "->         ";
        temp->theToken.print(cout); // using the print function of Token to print each Token
        temp = temp->next; // going to next node in each traverse
    }
}
/**
* Determines whether aToken is in the list.
* @param: const Token&
* @return: bool
*/
bool TList::search(const Token& aToken)
{
    TNode* current = headerPtr->next; // creat a TNode pointer and points it to the first node of the list
    while (current != trailerPtr) // for traversing through list, we set a condistion to not being equal to the trailer pointer
    {
        if (aToken.compare(current->theToken) == 0) // checks whether the the token of list is equal to aToken
        {
            return true;
            break;
        }
        current = current->next; // setting the pointer to the next node in order to traverse through the list
    }
    return false;
}
/**
* Determines whether aToken is in the list.If false,
* it returns trailerPtr; otherwise, it either returns a
* pointer to the node that is equal to aToken, or returns
* a pointer to the node that would appear after aToken,
* if aToken already existed in the list
* @param: const Token&
* @return: TNode*
*/
TList::TNode* TList::lookup(const Token& aToken)  
{
    TNode* head = this->headerPtr->next; // creat a TNode pointer and points it to the first node of the list 
    while (head != this->trailerPtr) { // for traversing through list, we set a condistion to not being equal to the trailer pointer
        if (((head->theToken).compare(aToken)) >= 0) { // checks whether the the token of list is equal to aToken
            //return head;
            break;
        }
        head = head->next; // setting the pointer to the next node in order to traverse through the list
    }
    return head;
}
/**
* Inserts a new node before the node p points to
* @param: TNode*, const Token&
* @return: void
*/
void TList::addBefore(TNode* q, const Token& aToken) // 
{
    ++this->theSize; // increasing the size because we are using addBefore function to add an elemnt to list
    TNode* p = new TNode{ aToken }; // creats a TNode pointer and point it to a new TNode with the Token initialized to aToken

    // link p between q->prev and q
    p->next = q;
    p->prev = q->prev;

    // now that p can see q->prev and q,
    // we let q->prev and q see p to complete the insertion
    q->prev = (q->prev)->next = p;
}
/**
* Removes the node nodePtr points to
* @param: TNode*
* @return: void
*/
void TList::remove(TNode* nodePtr)
{
    if(this->empty() == false){
        (nodePtr->next)->prev = nodePtr->prev; // exchanging the pointer of next object to previous
        (nodePtr->prev)->next = nodePtr->next; // exchanging the pointer of previous object to next
        delete nodePtr; // deleting the pointer and the object which it points to in heap memory
        theSize--; // reducing the size by 1 because we delete the object from list
    }
    throw std::invalid_argument("the list is empty."); // throw an exeption in case that list is empty
}
