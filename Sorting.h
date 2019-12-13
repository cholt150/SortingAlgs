#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_ARRAY 10000
#define aType int

//SELECTION PROTOTYPES
void SelectionSort(aType A[], int nElements, int& c, int& s);
int IndexOfSmallest(aType A[], int iStart, int iEnd, int& c);
//QUICK PROTOTYPES
void Quicksort(aType a[], int first, int last, int& c, int& s);
int Pivot(aType a[], int first, int last, int& c, int& s);
void Swap(aType& v1, aType& v2, int& s);
//MERGE PROTOTYPES
void  Mergesort(aType a[], int first, int last, int& c, int& s);
void  Merge(aType a[],
	int firstLeft, int lastLeft,
	int firstRight, int lastRight, int& c, int& s);
void  PrintArray(aType A[], int nElements);
//END PROTOTYPES