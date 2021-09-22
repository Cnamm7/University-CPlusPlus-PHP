
#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <list>
#include "Token.h"

using std::list;


class Tokenizer
{
private:
    const string theSeparators; // the separator characters in a std::string
    list<Token> theTokenList; // the list of tokens managed by this tokenizer
    vector<string> theLines; // the lines in the input file

    void ProcessTokensInLine(const string& line, size_t linenume);
    vector<string> splitLineIntoTokens(const string& line) const;
    void insert(string text, size_t linenum);
    vector<size_t> search(const string& str) const;
    void printSomeInputLines(const vector<size_t>& vec) const;

public:

    Tokenizer() = delete;   //disable default constructor
    Tokenizer(const string& filename, const string& separators);

    ~Tokenizer() = default; //dtor
    Tokenizer(const Tokenizer&) = default; //copy ctor
    Tokenizer(Tokenizer&&) = default; // move ctor
    Tokenizer& operator=(const Tokenizer&) = default; // copy op=
    Tokenizer& operator=(Tokenizer&&) = default; // move op+

    void searchAndPrint(string& str) const;
    void printAllInputLines() const;
    void print(ostream& sout) const;
    void sortOnFrequency() const;
    void sortOnTokenLenght() const;

protected:


};

ostream& operator<<(ostream&, const Tokenizer&);
bool compareLength(const Token& t1, const Token& t2);
bool compareFrequency(const Token& t1, const Token& t2);

#endif // TOKENIZER_H
