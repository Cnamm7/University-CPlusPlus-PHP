#include "Token.h"
#include <cstring>
#include "IntList.h"

using std::endl;
using std::cout;

/**
* explicit normal constructor, creates a new token
* using the supplied C-string and line number
* declared as noexcept because the implementation should be reliable
* @param: const char*, int
*/
Token::Token(const char* cstr, int line_num) 
{
    int len = strlen(cstr); // to get the lenght of passing c string
    this->text = new char[len + 1]; // for creating a new array of char with lenght plus to one because of a null pointer at the end of the c string and assigning it to text
    strcpy(text, cstr); // copying the c string to text
    number_list.pushBack(line_num); // inserting the line number into the number list
}
/**
* Default Constructor, creates an empty C-string
* declared as noexcept because the implementation should be reliable
*/
Token::Token() noexcept

{
    this->text = new char[1];
    strcpy(text, "");
    //this->number_list;
}
/**
* Copy constructor
* declared as noexcept because the implementation should be reliable
* @param: const Token&
*/
Token::Token(const Token& token) noexcept 
{
    int len = strlen(token.text); // to get the lenght of passing c string
    this->text = new char[len + 1]; // for creating a new array of char with lenght plus to one because of a null pointer at the end of the c string and assigning it to text
    strcpy(this->text, token.text); // copying the c string to text
    this->number_list = token.number_list; // assigning the rhs list of numbers to lhs list of numbers
}
/**
* Move constructor
* declared as noexcept because the implementation should be reliable
* @param: Token&&
*/
Token::Token(Token&& token) noexcept 
{
    this->text = token.text; // assigning the rhs text to lhs text
    this->number_list = token.number_list; // assigning the rhs list of numbers to lhs list of numbers
    token.text = nullptr; // assigning the text pointer to null, here we steal the data from rhs and assigned it to lhs, then we removed rhs
}
/**
* Copy assignment operator
* declared as noexcept because the implementation should be reliable
* @param: const Token&
*/
Token& Token::operator=(const Token& rhs) noexcept 
{
    if (this != &rhs)// handle self-assignment
    {
        delete[] this->text; // delete the text
        int len = strlen(rhs.text); // to get the lenght of passing c string
        this->text = new char[len + 1]; // for creating a new array of char with lenght plus to one because of a null pointer at the end of the c string and assigning it to text
        strcpy(this->text, rhs.text); // copying the c string to text
    }
    return *this; // *this is the invoking obj.
}
/**
* Move assignment operator
* declared as noexcept because the implementation should be reliable
* @param: const Token&&
*/
Token& Token::operator=(Token&& rhs) noexcept 
{
    if (this != &rhs)// handle self-assignment
    {
        this->text = rhs.text; // assigning the rhs text to lhs text
        this->number_list = rhs.number_list; // assigning the rhs list of numbers to lhs list of numbers
        rhs.text = nullptr; // assigning the text pointer to null, here we steal the data from rhs and assigned it to lhs, then we removed rhs
    }
    return *this; // *this is the invoking obj.
}
/**
* Destructor (and a virtual one in this example)
* declared as noexcept because the implementation should be reliable
*/
Token::~Token() noexcept
{
    delete[] text;
}
/**
* Returns -1, 0, or 1 as “the” this token’s text is less
* than, equal to, or greater than aToken’s text
* @param: const Token&
* @return: int
*/
int Token::compare(const Token& aToken) const
{
    int str = strcmp(this->text, aToken.text); // using strcmp function checks whether the to c stirng are equal or not and returning accordingly
    return str;
}
/**
* Returns a constant pointer to this token’s text
* @return: const char*
*/
const char* Token::getText()
{
    return this->text;
}
/**
* Adds line num to the end of this token’s number list
* @return: void
*/
void Token::addLineNumber(int line_num)
{
    this->number_list.pushBack(line_num);
}
/**
* Returns the length of this token’s text
* @return: int
*/
int Token::size()
{
    int lenText = strlen(text);
    return lenText;
}
/**
* Prints this token’s text followed by its number list.
* @param: ostream&
* @return: void
*/
void Token::print(std::ostream& sout)
{
    sout << this->text << " "; // print the text of Token
    this->number_list.print(cout); // using IntList print function, print the list of numbers
}
/**
* Returns the k’th character (zero-based) of this token’s text.
* Returns the null character (\0) if k is out-of-range
* @param: int
* @return: char
*/
char Token::getChar(int k) const
{
    if (unsigned(k) > strlen(this->text) || k < 0) { return NULL; }
    else
    {
        return this->text[k];
    }
}
/**
* Returns this tokens line number, which is stored at position
* 0 of this token’s list of line numbers
* @param: int
* @return: char
*/
int Token::getLineNumber() const
{
    return this->number_list.getDynarray(0);
}









