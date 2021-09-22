#include "Tokenizer.h"
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <istream>
#include <forward_list>

using std::cout;
using std::forward_list;
/**
* proccess tokens and use insert function
* @param: const string&, size_t
* return: void
*/
void Tokenizer::ProcessTokensInLine(const string& line, size_t lineNum)
{
    vector<string> vec; // creatung a temporary vetor of strings
    vec = splitLineIntoTokens(line); // using the splitLineIntoTokens to put each string in a vector Token
    for (unsigned i = 0; i < vec.size(); ++i) // for traversing through vector

    {
        insert(vec[i], lineNum); // inserting the text and line number using the insert function
    }
}
/**
* function to split each line into different tokens of text
* @param: const string&
* return: vector<string>
*/
vector<string> Tokenizer::splitLineIntoTokens(const string& line)const
{
    vector<string> vec; // creating a temporary vector of string
    size_t len = line.length(); // assigning the lenght of the line string to the len
    size_t start = line.find_first_not_of(theSeparators, 0); // searching for the first separator in the string starting from character 0
    while ((start >= 0) && (start < len)) // using while loop to travers through the line string
    {
        int stop = line.find_first_of(theSeparators, start); // finding separator starting from start(start is where the first separator found)
        if ((stop < 0) || (unsigned(stop) > len)) unsigned(stop) = len;
        string word = line.substr(start, stop - start); // in this line we find words between two separators
        vec.push_back(word); // pushing words into vector
        start = line.find_first_not_of(theSeparators, stop + 1); // starting from where the last separator found + 1 so we can travers through the end of line
    }
    return vec;
}
/**
* funtion to insert tokens into the token list
* @param: string, size_t
* @return: void
*/
void Tokenizer::insert(string text, size_t lineNum) 
{
    Token t(text, lineNum); // creating an object of Token with the passed arguments
    int result{ 1 };
    auto it = theTokenList.begin();
    for (; it != theTokenList.end(); ++it) // travers through token list in order to see if there is any token with the same case
    {
        result = (*it).compareIgnoreCase(t);
        if(result == 0)
        {
            break;
        }
    }
    if (result > 0 || result < 0) // in case that no token found with the same text
    {
        theTokenList.insert(it, t);
    }
    for (auto it = theTokenList.begin(); it != theTokenList.end(); ++it) // traversing through token list in order to push back line number of existing tokens
    {
        result = t.compareIgnoreCase(*it);
        if (result == 0 && (*it).getLineNumber() != t.getLineNumber()) // check whether the line number of that token iserted or not
        {
            (*it).pushBackLineNumber(lineNum);   
        }
    }   
}
/**
* a function to search the token for the passed string
* @param: const string&
* @return: vector<size_t>
*/
vector<size_t> Tokenizer::search(const string& str) const
{

    for (auto v : theTokenList) // for checking and comparing passed string with every elements in the TokenList
    {

        if (str.compare(v.getTheText()) == 0)
        {

            return v.getTheLineNumberList(); // returning the found line number list
        }

    }
    throw std::invalid_argument("no text matches the result");
}
/**
* a function to print some input lines based on the passing vector
* @param: const vector<size_t>&
* return: void
*/
void Tokenizer::printSomeInputLines(const vector<size_t>& vec) const
{

    for (auto v : vec) // for every elements of vector, prints the corresponding line, here v minuses 1 because the index start from 0
        cout << theLines[v-1] << endl;  
}
/**
* a constructor of tokenizer
* @param: const string&
*/
Tokenizer::Tokenizer(const string& filename, const string& separators)
    : theSeparators(separators)
{
    string line;
    std::ifstream myFile; // creating a myFile ifstream


    myFile.open(filename);
    if (myFile.is_open())
    {
        int i = 1;
        while (getline(myFile, line))
        {

            theLines.push_back(line); // add to line list
            
            ProcessTokensInLine(line, i); // processing the tokens in line
            i++;

        }

    }
    else
    {
        cout << "Could not open input file:  " << filename << "\n";
        exit(1);
    }
}
/**
* a function to search and print the line which contains the passed string
* @param: string&
* @return: void
*/
void Tokenizer::searchAndPrint(string& str) const
{
    printSomeInputLines(search(str)); // using the search function first we find the vector of the string which we were looking, then passing that line number list to printSomeInputLines
}
/**
* a function to print all lines
* @return: void
*/
void Tokenizer::printAllInputLines() const
{
    for (unsigned i = 0; i < theLines.size(); ++i)
        cout << i + 1 << ": " << theLines[i] << endl;
}
/**
* a function to print the Tokenizer object
* printing each Token with its line number list line by line
*/
void Tokenizer::print(ostream& sout) const
{
    for (auto it = theTokenList.begin(); it != theTokenList.end(); ++it)
        sout << *it << endl;
}
/**
* a function to sort Tokens based on ther frequencies
* @return: void
*/
void Tokenizer::sortOnFrequency() const
{
    // we need to use sort of forward_list and copy token list in it
    forward_list<Token> F;

    for (auto v : theTokenList)
        F.emplace_front(v);

    F.sort(compareFrequency); // we pass the compareFrequency function as sorting parameter
    for (auto v : F) // a for loop to print the result
        cout << v << endl;
}
/**
* a function to sort Tokens based on ther Token text lenght
* @return: void
*/
void Tokenizer::sortOnTokenLenght() const
{
    // we need to use sort of forward_list and copy token list in it
    forward_list<Token> F;

    for (auto v : theTokenList)
        F.push_front(v);

    F.sort(compareLength); // we pass the compareLength function as sorting parameter
    for (auto v : F) // a for loop to print the result
        cout << v << endl;
}
/**
* overloading the extraction operator for Tokenizer class
* @param: ostream&, const Tokenizer&
*/
ostream& operator<<(ostream& sout, const Tokenizer& T)
{
    T.print(sout);
    return sout;
}
/**
* a function to compare two Tokens based on their length
* @param: const Token&, const Token&
* return: bool
*/
bool compareLength(const Token& t1, const Token& t2)
{
    if (((t1.getTheText()).length()) < ((t2.getTheText()).length()))return true;
    else if ((t1.getTheText()).length() == t2.getTheText().length())
    {
        if (t1.getTheText().compare(t2.getTheText()) == -1) { return true; }
    }
    return false;
}
/**
* a function to compare two Tokens based on their frequencies
* @param: const Token&, const Token&
* return: bool
*/
bool compareFrequency(const Token& t1, const Token& t2)
{

    if (t1.getFrequency() < t2.getFrequency()) { return true; }
    return false;
}
