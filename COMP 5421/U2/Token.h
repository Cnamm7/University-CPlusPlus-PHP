#ifndef TOKEN_H
#define TOKEN_H
#include <vector>
#include <string>
#include <iostream>

using std::ostream;
using std::string;
using std::vector;
using std::endl;


class Token
{
private:
    string theText{}; // the text of this token
    vector<size_t> theLineNumbers{}; // this token’s list of (non-negative) line numbers, the size of line number should be at least 1
    size_t theFrequency{ 1 }; // the frequency of this token in the input file
public:
    
    Token() = delete; // disable default construction
    Token(string text, size_t linenum); // a normal constructor
    Token& operator=(const Token& rhs) = default; // copy op=
    Token& operator=(Token&& rhs) = default; // move op=
    Token(const Token& source) = default; // copy ctor
    Token(Token&& source) = default; // move ctor
    ~Token() = default; // dtor

    int compareIgnoreCase(const Token& t) const;

    string getTheText() const;
    vector<size_t> getTheLineNumberList() const;
    size_t getFrequency() const;
    size_t getLineNumber(size_t = 1) const; // line number is 1-based to provide user friendly interface

    void pushBackLineNumber(size_t lineNum); // append the suppled line number
    void print(ostream& sout) const;


protected:


};

#endif // TOKEN_H
ostream& operator<<(ostream& sout, const Token& arr);
