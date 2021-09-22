#ifndef TOKEN_H
#define TOKEN_H
#define _CRT_SECURE_NO_WARNINGS
#include "IntList.h"


class Token {
private:
    char* text;
    IntList number_list;
public:
    explicit Token(const char* cstr, int line_num); //explicit normal constructor, creates a new token
                                            //using the supplied C-string and line number
    Token() noexcept; //Default Constructor, creates an empty C-string
    Token(const Token& token) noexcept; //Copy constructor
    Token(Token&& token) noexcept; //Move constructor
    Token& operator=(const Token& rhs) noexcept; // Copy assignment operator
    Token& operator=(Token&& rhs) noexcept; // Move assignment operator
    virtual ~Token() noexcept; // Destructor (and a virtual one in this example)

    int compare(const Token& aToken) const; // Returns -1, 0, or 1 as “the” this token’s text is less
                                              //than, equal to, or greater than aToken’s text
    const char* getText(); //Returns a constant pointer to this token’s text
    void addLineNumber(int line_num); //Adds line num to the end of this token’s number list
    int size(); //Returns the length of this token’s text
    void print(std::ostream& sout); //Prints this token’s text followed by its number list.
    char getChar(int k) const; //Returns the k’th character (zero-based) of this token’s text.
                               //Returns the null character (\0) if k is out-of-range
    int getLineNumber() const; //Returns this tokens line number, which is stored at position
                               //0 of this token’s list of line numbers
};



#endif // TOKEN_H
