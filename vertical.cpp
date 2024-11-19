/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
// Do not add any other #include statement!
#include <iostream>
using namespace std;
void printV(long int n);

int main() {
    long int n;
    cout << "Enter integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Input must be a positive integer." << endl;
    } else {
	printV(n);
	}

    return 0;
}

void printV(long int n){
    if (n <= 0) {
    	return;
	}
    printV( n / 10);
    cout << n % 10 << endl;    
    }
