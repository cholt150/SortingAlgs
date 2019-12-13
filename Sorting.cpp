#include "Sorting.h"
//BEGIN FUNCTION DEFS
//SELECTION SORT
void  SelectionSort(aType A[], int nElements, int& c, int& s)
{
	int iSmallest;
	aType  tmp;

	for (int i = 0; i < nElements; i++)
	{
		iSmallest = IndexOfSmallest(A, i, nElements - 1, c);
		//  swap
		if (iSmallest > i)
		{
			tmp = A[i];
			A[i] = A[iSmallest];
			A[iSmallest] = tmp;
			s++;
		}
	}

}

int IndexOfSmallest(aType A[], int iStart, int iEnd, int& c)
{
	int    index = -1;
	aType  aMin = A[iStart];

	for (int i = iStart; i <= iEnd; i++)
	{
		c++;
		if (A[i] < aMin)
		{
			aMin = A[i];
			index = i;
		}
	}

	return index;
}
//QUICK SORT
void Quicksort(aType a[], int first, int last, int& c, int& s)
{
	int pivot;

	if (first < last) {
		pivot = Pivot(a, first, last, c, s);
		Quicksort(a, first, pivot - 1, c, s);
		Quicksort(a, pivot + 1, last, c, s);
	}
}

int Pivot(aType a[], int first, int last, int& c, int& s)
{
	int  p = first;
	aType pivot = a[first];

	for (int i = first + 1; i <= last; i++) {
		c++;
		if (a[i] <= pivot) {
			p++;
			Swap(a[i], a[p], s);
		}
	}

	Swap(a[p], a[first], s);

	return p;
}
//MERGE SORT
void Mergesort(aType a[], int first, int last, int& c, int& s)
{
	int  middle;

	c++;
	if (first < last) {
		middle = (first + last) / 2;
		Mergesort(a, first, middle, c, s);
		Mergesort(a, middle + 1, last, c, s);
		Merge(a, first, middle, middle + 1, last, c, s);
	}
}

/*  Merge:  Merge two segments of an array together.
 */

void Merge(aType a[],
	int firstLeft, int lastLeft,
	int firstRight, int lastRight, int& c, int& s)
{
	aType tempArray[MAX_ARRAY];
	int  index = firstLeft;
	int  firstSave = firstLeft;

	//  Merge segments (array subsets)
	
	while ((firstLeft <= lastLeft) && (firstRight <= lastRight))
	{
		c++;
		c++;//two comparisons from loop
		c++;//one comparison from if
		if (a[firstLeft] < a[firstRight])
		{
			tempArray[index] = a[firstLeft];
			firstLeft++;
			s++;
		}
		else
		{
			tempArray[index] = a[firstRight];
			firstRight++;
			s++;
		}
		index++;
	}
	//  Copy remainder of left array into tempArray
	while (firstLeft <= lastLeft)
	{
		c++;
		tempArray[index] = a[firstLeft];
		firstLeft++;
		index++;
	}

	//  Copy remainder of right array into tempArray
	while (firstRight <= lastRight)
	{
		c++;
		tempArray[index] = a[firstRight];
		firstRight++;
		index++;
	}

	//  Copy back into original array
	for (index = firstSave; index <= lastRight; index++)
		a[index] = tempArray[index];
}


/*  Swap:  Swap two items (by reference).
 */
void  Swap(aType& v1, aType& v2, int& s)
{
	aType  tmpVal;

	tmpVal = v1;
	v1 = v2;
	v2 = tmpVal;
	s++;
}

void  PrintArray(aType A[], int nElements)
{
	cout << "[ ";

	for (int i = 0; i < nElements; i++)
	{
		cout << A[i];
		if (i < nElements - 1)
			cout << ", ";
	}

	cout << " ] " << endl;
}

