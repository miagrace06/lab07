/* Main function for palindrome.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
#include "pheaders.h"

int main() {
    // 1. declare a string variable to hold the user input
    string s;
    // 2. Prompt the user to enter a sentence
    cout << "Enter sentence:";

    //3. Read the entire line of input from the user, including spaces
    getline(cin, s);
    // print a newline for formatting purposes
    cout << endl;

    //4. Clean up the string by removing any unwanted characters
    cleanUp(s);

    //5. check if the cleaned-up string is a palindrome
    if (isPalindrome(s)) {
	    // 6. If it is a palindrome, print this message. 
	    cout << "It is a palindrome." << endl;
    }else {
	    //7. If it is not a palindrome, print this message.
	    cout << "It is not a palindrome." << endl;
    }
    //8. return 0 to indicate sufessful execution of the program
    return 0;
}

