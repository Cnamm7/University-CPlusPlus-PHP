#include <iostream>
#include <fstream>
#include "Token.h"
#include "Tokenizer.h"
#include <string>
#include <vector>
#include <list>
#include <forward_list>

using std::cout;
using std::ifstream;
using std::cin;

int main()
{
 
    string filename;
    cout << "Enter the name of an input file of text: ";

    filename = "input_text_file.txt"; // to speed up testing, MUST remove when done
    //cin >> filename;

    string separators;
    cout << "Enter the separator characters: ";

    separators = ";. ,?!\" = ':"; // to speed up testing, MUST remove when done
    //cin >> separators;

    char answer{};

    string line;
    ifstream myFile;
    myFile.open(filename);

    if (!myFile)
    {
        cout << "Could not open input file:  " << filename << "\n";
        exit(1);
    }

    // create a list of tokens
    Tokenizer t1(filename, separators);

    while (answer != 'X')
    {
        cout << " Menu " << "\n"
            " ====== " << "\n"
            " A - Print all input lines " << "\n"
            " P - Print indexed tokens " << "\n"
            " F - Print tokens sorted on frequency " << "\n"
            " L - Print tokens sorted on length " << "\n"
            " S - Search " << "\n"
            " X - Exit " << "\n"
            " Enter your choice: ";
        cin >> answer;
        // convert answer to uppercase
        answer = std::toupper(answer);

        switch (answer)
        {
        case 'A':
            cout << "Case A selected" << "\n";
            t1.printAllInputLines();
            break;

        case 'P':
            cout << "Case P selected" << "\n";
            t1.print(cout);
            break;

        case 'F':
            cout << "Case F selected" << "\n";
            t1.sortOnFrequency();
            break;

        case 'L':
            cout << "Case L selected" << "\n";
            t1.sortOnTokenLenght();
            break;

        case 'S':
            cout << "Case S selected" << "\n";
            cout << "Please enter the text to search for: ";
            if (myFile.is_open())
            {
                string s;
                cin >> s;
                t1.searchAndPrint(s);
            }

            break;

        case 'X':
            cout << "Case X selected" << "\n";
            myFile.close();
            cout << "Thank you for trying my program." << endl;;
            cout << "Goodbye" << endl;
            exit(0);
            break;
        }
    }
    



}
