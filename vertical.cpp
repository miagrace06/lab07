/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
// Do not add any other #include statement!
#include <iostream>
using namespace std;

//Function for printing digits vertically
void printV(long int n);

int main() {
    long int n;
    //prompt user to enter an integer
    cout << "Enter integer: ";
    cin >> n;

    //Check if input is negative
    if (n < 0) {
        cout << "Input must be a positive integer." << endl;
    } else {
	//Call recusrive function to print digits
	printV(n);
	}

    return 0;
}

//Recusrive function to print digits vertically
void printV(long int n){
    //Base case: stop when number becomes less than 0
    if (n < 0) {
    	return;
	}
    //Recusrively process the number by dividing by 10
    //This moves to the next digit from left to right
    printV( n / 10);

    //Print the rightmost digit after recursion
    //Ensures digits are printed vertically from left to right
    cout << n % 10 << endl;    
    }
