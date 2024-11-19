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
	//Prompt the user for the input filename containing the data
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	
	//Open the file and determine the number of integers(size) in the file
	ifstream inFile; //Declare an input file stream
	int size = getFileSize(inFile, filename); //Get the number of elements from the file
	if (size <= 0) return 1; //If the size is 0 or less, exit the program

	//Dynamically allocate an array to store the integers from the file
	int* arr = new int[size];

	//Populate the array with data from the file
	getArray(inFile, filename, arr, size);

	//Display the original array before sorting
	cout << "Original array:" << endl;
	for (int i = 0; i <size; i++) {
		cout << arr[i] << " "; //output each element in the array
	}
	cout << endl;

	//Prompt the user to choose the sorting order
	int order;
	cout << "Ascending (0) or Descending (1): ";
	cin >> order;

	//Sort the array using the selection sort algorithm in the specified order
	sort(order == 1, arr, size, 0);

	//Display the sorted array
	cout << "Sorted array:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " "; //Output each element in the sorted array
	}
	cout << endl;

	//Free the dynamically allocated memory for the array
	delete[] arr;
	//Return 0 to indicate successful program execution
	return 0;
}
