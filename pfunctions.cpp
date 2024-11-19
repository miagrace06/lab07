// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"



//Function recursively checks if a given string is a palindrome
//Precondition: The input string 's' must not be empty        
                //The string may contain uppercase or lowercase letters
//Post condition: Returns true if the string is a palindrome(the same forwards and backwards)
                 //Returns false if the string is not a palindrome 
bool isPalindrome(string s) {
        //Base case: a string with 0 or 1 character is a palindrome
        if (s.length() <= 1){
                return true;
        }
        //Check if the first and last chracters are the same
        if (s[0] == s[s.length() - 1]) {
                //Recusrive case: check the substring with the first and last characters removed
                return isPalindrome(s.substr(1, s.length() - 2));
        } else {
                //if the characters do not match, it is not a palindrome
                return false;
        }
}
//Function to clean up the input string by removing any non-alphabetical characters and converting all letters to lowercase. The cleaned string is returned in place
//Precondition: the input string 's' can contain letters and other characters like space or digits.
//Postcondition: modifies the string 's' to only contain lowercase alphabetical characters
void cleanUp(string &s) {
        //Temporary string to hold the cleaned version
        string cleaned = "";
        
        //Iterate over each character in the string
        for (char c : s) {
                //only include letters(A-Z, a-z) in the cleaned string
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z')) {
                        //Convert uppercase characters to lowercase
                        if (c >= 'A' && c<= 'Z') {
                                c = c + ('a' - 'A');
                        }
                        //add the character to the cleaned string
                        cleaned += c;
                }
        }
        //replace the originial string with the cleaned version
        s = cleaned;
}
