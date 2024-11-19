// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// DEFINE THE 2 FUNCTIONS PER THE pheaders.h FILE HERE
// Add Pre- and Post-Condition comments

bool isPalindrome(string s) {
        if (s.length() <= 1){
                return true;
        }

        if (s[0] == s[s.length() - 1]) {
                return isPalindrome(s.substr(1, s.length() - 2));
        } else {
                return false;
        }
}
void cleanUp(string &s) {
        string cleaned = "";

        for (char c : s) {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z')) {
                        if (c >= 'A' && c<= 'Z') {
                                c = c + ('a' - 'A');
                        }
                        cleaned += c;
                }
        }
        s = cleaned;
}
