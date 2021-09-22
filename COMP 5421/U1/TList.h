#ifndef TLIST_H
#define TLIST_H

#include "Token.h"

using std::ostream;


class TList {
    struct TNode {
        Token theToken = Token{}; // node data
        TNode* prev; // previous node in list
        TNode* next; // next node in list
        TNode(const Token& token = Token{}, TNode* p = nullptr, TNode* n = nullptr)
            : theToken{ token }, prev{ p }, next{ n } {}

        TNode(Token&& token, TNode* p = nullptr, TNode* n = nullptr)
            : theToken{ std::move(token) }, prev{ p }, next{ n } {}

        TNode& operator=(const TNode&) = delete; // copy assignment
        TNode& operator=(TNode&&) = delete; // move assignment
        ~TNode() = default;
        //void TNode::print(ostream& sout) const{ sout << theToken.print(cout);}
    };


private:
    TNode* headerPtr; // A pointer to the sentinel header node at the front of the list
    TNode* trailerPtr; // A pointer to the sentinel trailer node at the back of the list
    int theSize; // Stores the number of nodes in this list

public:
    TList() noexcept; // Default constructor, creates an list
    TList(const TList& list) noexcept; // Copy constructor
    TList(TList&& list) noexcept; //Move constructor
    TList& operator=(const TList& rhs) noexcept; // Copy assignment operator
    TList& operator=(TList&& rhs) noexcept; // Move assignment operator
    virtual ~TList() noexcept; // Destructor (and a virtual one in this example)

    bool empty() const; // Determines whether this list is empty
    const Token& front() const; // Retruns the token at the front of this list
    const Token& back() const; // Retruns the token at the back of this list
    void addSorted(const Token& aToken); // Adds aToken at its sorted position into the list so as
                                        // to maintain the ascending order of the list
    bool removeFront(); // if the list is nonempty, removes the node at the front
                        // of the listand returns true; otherwise, returns false
    bool removeBack(); // if the list is nonempty, removes the node at the end
                       // of the listand returns true; otherwise, returns false

    int size() const; // Returns theSize
    void print(ostream& sout) const; // Prints the entire list
    bool search(const Token& aToken); // Determines whether aToken is in the list.
    TNode* lookup(const Token& aToken); // Determines whether aToken is in the list. If false,
                                        // it returns trailerPtr; otherwise, it either returns a
                                        // pointer to the node that is equal to aToken, or returns
                                        // a pointer to the node that would appar after aToken,
                                        // if aToken already existed in the list
    void init(); // Initializes this list to an empty list at construction
    void addBefore(TNode* p, const Token& t); //  Inserts a new node before the node p points to
    void remove(TNode* nodePtr); // Removes the node nodePtr points to

};





#endif // TLIST_H
