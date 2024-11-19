/* Main function for selectionSort.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"

int main() {
	string filename;
	cout << "Enter filename: ";
	cin >> filename;

	ifstream inFile;
	int size = getFileSize(inFile, filename);
	if (size <= 0) return 1;

	int* arr = new int[size];
	getArray(inFile, filename, arr, size);

	cout << "Original array:" << endl;
	for (int i = 0; i <size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int order;
	cout << "Ascending (0) or Descending (1): ";
	cin >> order;

	sort(order == 1, arr, size, 0);

	cout << "Sorted array:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;
	return 0;
}
