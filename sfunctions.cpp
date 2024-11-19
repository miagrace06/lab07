// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

/*
* Function find the index of the element in the array that should be swapped 
* with the element at the given 'start_index' based on the sorting order.
* Precondition: - 'desc': a boolean flag where true means descending order and false means ascending order
	* - 'a': The array to be sorted
	* - 'start_index': the index from where the search for the smallest or largest element should begin
	* - 'number_used': The total number of elements in the array
* Postcondition: returns the index of the element to be swapped with the element at 'start_index'

*/
int find_index_of_swap(bool desc, int a[], int start_index, int number_used){
	int target_index = start_index; //start with the first index as the target for swapping

	//loop through the array starting from start_index + 1
	for (int i = start_index + 1; i < number_used; i++){
		//If sorting in descending order, look for the largest element
		if (desc) {
			if (a[i] > a[target_index]) {
				target_index = i; //update target index if a larger element is found
			}
		} else {
			//If sorting in ascending order, look for the smallest element
			if (a[i] < a[target_index]) {
				target_index = i; //update target index if a smaller element is found
			}
		}
	}
	return target_index; //Return the index of the element ot be swapped
}
/*
* Function swaps the values of two integers
*Precondition: v1 and v2 are valid integer references
*Postcondition: the values of v1 and v2 have been swapped
*/
void swap_values(int& v1, int& v2) {
	int temp = v1;  //Store the value of v1 temporarily
	v1 = v2; //Assign the value of v2 to v1
	v2 = temp; //Assign the temporary value (original v1) to v2
}

/*
* Function sorts the array using the selection sort algorithm either in ascending or descending order, 
* depending on the desc flag.
*Precondition: - desc; a boolean flag where true means descending order and false means ascending order
* 	       - a: the array of integers to be sorted
* 	       - number_used: the total number of elements in the array
*	       - index: the starting index for the current pass of selection sort
*Postcondition: - the array a is sorted in the specified order
* 	        - the sorting is performed using recursion
*/
void sort(bool desc, int a[], int number_used, int index) {
	//Base case: if the index is the last element, the array is already sorted
	if (index >= number_used - 1) {
		return;
	}
	//Find the index of the element to swap with the element at 'index'
	int swap_index = find_index_of_swap(desc, a, index, number_used);
	//If the element at index is not the correct one, swap it with the element at swap_index
	if (swap_index != index) {
		swap_values(a[index], a[swap_index]);
	}
	//Recursively sort the rest of the array, starting from the next index
	sort(desc, a, number_used, index + 1);
}

/*
*Function reads a file and returns the number of integers in the file
* Precondition: - inf: a reference to an input file stream
*		- fname: the name of the file to be read
*Postcondition: returns the total number of integers in the file if the file opens successfully
*/
int getFileSize(ifstream& inf, string fname) {
	int count = 0;  //Counter for the number of integers in the file
	int temp;       //Temporary variable to hold each number read from the file

	inf.open(fname);  //Open the file
	if(!inf.is_open()) {
		cout << "Error opening file."<< endl;
		return -1;
	}
	//Read the integers from the file and count them
	while (inf >> temp) {
		count++;
	}
	inf.close();  //close the file after reading
	return count;  //Return the total number of integers 
}
/*
*Function reads the integers from a file and stores them in the provided array
*Precondition: - in: a reference to an input file stream
	      * - fname: the name fo the file containing the integers 
               * - arr: an array where the integers from the file will be stored
	       * - size: the number of integers to be read from the file 
*Postcondition: - the array arr is filled with the integers from the file
* 		- if the file cannot be opened, an error message is printed
*/
void getArray(ifstream& in, string fname, int arr[], int size) {
	in.open(fname); //Open the file for reading
	if(!in.is_open()) {
		cout << "Error opening file." << endl; 
		return;
	}
	//Read the integers from the file and store them in the array
	for (int i = 0; i < size; i++) {
		in >> arr[i];
	}
	in.close();  //Close the file after reading
}
