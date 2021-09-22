#include <iostream>
#include<cassert>
#include "IntList.h"
#include "Token.h"
#include "TokenizerApp.h"


using std::cout;
using std::endl;

int main() {
    
    const char* filename = "input_text_file.txt";
    //// this file is located in the visual studio storing
    //// all the .cpp and .h file for this project.
    //// or
    ////const char* filename = "C:\\COMP5421\\A1\\input_text_file.txt";
    TokenizerApp tokApp(filename);
    tokApp.print(cout);
    cout << endl;
    return 0;

}
