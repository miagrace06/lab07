// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"
int find_index_of_swap(bool desc, int a[], int start_index, int number_used){
	int target_index = start_index;

	for (int i = start_index + 1; i < number_used; i++){
		if (desc) {
			if (a[i] > a[target_index]) {
				target_index = i;
			}
		} else {
			if (a[i] < a[target_index]) {
				target_index = i;
			}
		}
	}
	return target_index;
}

void swap_values(int& v1, int& v2) {
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

void sort(bool desc, int a[], int number_used, int index) {
	if (index >= number_used - 1) {
		return;
	}
	int swap_index = find_index_of_swap(desc, a, index, number_used);

	if (swap_index != index) {
		swap_values(a[index], a[swap_index]);
	}
	sort(desc, a, number_used, index + 1);
}

int getFileSize(ifstream& inf, string fname) {
	int count = 0;
	int temp;

	inf.open(fname);
	if(!inf.is_open()) {
		cout << "Error opening file."<< endl;
		return -1;
	}
	while (inf >> temp) {
		count++;
	}
	inf.close();
	return count;
}
void getArray(ifstream& in, string fname, int arr[], int size) {
	in.open(fname);
	if(!in.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		in >> arr[i];
	}
	in.close();
}
// DEFINE ALL 5 FUNCTIONS PER THE sheaders.h FILE HERE
// Add Pre- and Post-Condition comments
