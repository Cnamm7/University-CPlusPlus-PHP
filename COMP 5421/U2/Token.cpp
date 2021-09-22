#include "Token.h"

/**
* Constructor of the Token
* @param: string, size_t
*/
Token::Token(string text, size_t lineNum)
{
    this->theText = text; // assigning the text argument to theText
    this->theLineNumbers.push_back(lineNum); // pushing the line number into the number list
    this->theFrequency = 1; // setting the frequency to 1
}
/**
* comparing the tokens base their ascii value
* @param: const Token&
* return: int
*/
int Token::compareIgnoreCase(const Token& t) const
{
    size_t i = 0;
    while ((i < this->theText.length()) && (i < t.theText.length())) // checking the lenght of the text with i to traverse through both textes
    {
        if (tolower(this->theText[i]) < tolower(t.theText[i])) return -1; // in case that the invoking object's text character is less than the argument text
        else if (tolower(this->theText[i]) == tolower(t.theText[i]) && this->theText.length() == t.theText.length()) return 0; // in case that the invoking object's text character is equal to the argument text
        else return 1; // in case that the invoking object's text character is greater than the argument text
        ++i;
    }
    throw std::invalid_argument("the value to compare is out of bound"); // throw an exeption in case of returing all control panths and the case that the return is out of bound
}
/**
* a function to return the text
* @return: string
*/
string Token::getTheText() const
{
    return this->theText;
}
/**
* a function to get the line number
* @return: vector<size_t>
*/
vector<size_t> Token::getTheLineNumberList() const
{
    return this->theLineNumbers;
}
/**
* a function to get the frequency of invoking object
* @return: size_t
*/
size_t Token::getFrequency() const
{
    return this->theFrequency;
}
/**
* a function to get the first line number of the invoking object
* @return: size_t
*/
size_t Token::getLineNumber(size_t) const
{
    return theLineNumbers[0]; // returning the first line number of the object in the list
}
/**
* a function to get push line number into the number lists
* @param: size_t
* @return: void
*/
void Token::pushBackLineNumber(size_t lineNum)
{
    this->theLineNumbers.push_back(lineNum); // pushing into the line number list the lineNum parameter
    this->theFrequency++; // increasing frequency
}
/**
* print tokens base on their line numbers and frequencies
* @param: ostream&
* @return: void
*/
void Token::print(ostream& sout) const
{
    sout << theText << " " << "(" << theFrequency << ")"; // printing the text and frequency in one line
    for (unsigned i = 0; i < theLineNumbers.size(); ++i) // for loop for traversing in the list of numbers
        sout << theLineNumbers[i] << ", "; // printing the line numbers to ostream object
    
    sout << endl;
}
/**
* extraction overload function
* @param: ostream&, const Token&
* @return: ostream&
*/
ostream& operator<<(ostream& sout, const Token& arr)
{
    arr.print(sout); // print using the Token object print function
    return sout;
}
