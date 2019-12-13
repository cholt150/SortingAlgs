#include "Sorting.h"
int main() {
	aType testA[MAX_ARRAY];

	int s = 0; //Variable for swap count
	int c = 0; //variable for comparison count

	fstream fIn;
	string filename;
	cout << "Beginning sorting test for dataset of size " << MAX_ARRAY << endl;
	if (MAX_ARRAY == 100)
		filename = "rand100.txt";
	else if (MAX_ARRAY == 1000)
		filename = "rand1000.txt";
	else if (MAX_ARRAY == 10000)
		filename = "rand10000.txt";
	else {
		cout << "Enter the Dataset filename: " << endl;
		getline(cin, filename);
	}

	cout << "Using file: " << filename << endl;
	fIn.open(filename);
	int i = 0;
	if (!fIn) {
		cout << "Invalid filename" << endl;
		exit(1);
	}
	while (!fIn.eof()) {
		fIn >> testA[i];
		i++;
	}
	fIn.close();
	cout << "=========================================================" << endl << endl;
	//PrintArray(testA, MAX_ARRAY); //For testing
	SelectionSort(testA, MAX_ARRAY, c, s);
	cout << "Selection Sort on random array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	s = c = 0;
	SelectionSort(testA, MAX_ARRAY, c, s);
	cout << "Selection Sort on increasing sorted array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	//Reverse the array for decreasing sorted data
	for (int j = 0; j < MAX_ARRAY / 2; j++) {
		Swap(testA[j], testA[MAX_ARRAY - 1 - j], s);
	}
	//PrintArray(testA, MAX_ARRAY); //For testing
	s = c = 0;
	SelectionSort(testA, MAX_ARRAY, c, s);
	cout << "Selection Sort on decreasing sorted array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	cout << "=========================================================" << endl << endl;
	c = s = 0;
	//Reopen File
	fIn.open(filename);
	i = 0;
	while (!fIn.eof()) {
		fIn >> testA[i];
		i++;
	}
	fIn.close();
	//Begin Quicksort
	Quicksort(testA, 0, MAX_ARRAY - 1, c, s);
	cout << "Quick Sort on random array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	s = c = 0;
	Quicksort(testA, 0, MAX_ARRAY - 1, c, s);
	cout << "Quick Sort on increasing sorted array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	//Reverse the array for decreasing sorted data
	for (int j = 0; j < MAX_ARRAY / 2; j++) {
		Swap(testA[j], testA[MAX_ARRAY - 1 - j], s);
	}
	//PrintArray(testA, MAX_ARRAY); //For testing
	s = c = 0;
	Quicksort(testA, 0, MAX_ARRAY - 1, c, s);
	cout << "Quick Sort on decreasing sorted array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	cout << "=========================================================" << endl << endl;
	s = c = 0;
	//Reopen File
	fIn.open(filename);
	i = 0;
	while (!fIn.eof()) {
		fIn >> testA[i];
		i++;
	}
	fIn.close();
	//Begin mergesort
	Mergesort(testA, 0, MAX_ARRAY - 1, c, s);
	cout << "Merge Sort on random array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	s = c = 0;
	Mergesort(testA, 0, MAX_ARRAY - 1, c, s);
	cout << "Merge Sort on increasing sorted array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;
	//Reverse the array for decreasing sorted data
	for (int j = 0; j < MAX_ARRAY / 2; j++) {
		Swap(testA[j], testA[MAX_ARRAY - 1 - j], s);
	}
	//PrintArray(testA, MAX_ARRAY); //For testing
	s = c = 0;
	Mergesort(testA, 0, MAX_ARRAY - 1, c, s);
	cout << "Merge Sort on decreasing sorted array of size " << MAX_ARRAY << endl;
	cout << "No. of Comparisions: " << c << endl;
	cout << "No. of Swaps: " << s << endl << endl;

}