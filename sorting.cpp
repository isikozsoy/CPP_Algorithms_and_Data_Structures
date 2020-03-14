/*
* Title: Algorithm Efficiency and Sorting
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 1
* Description: description of your code
*/

#include <iostream>
#include "sorting.h"
using namespace std;

void insertionSort(int *arr, int size, int &compCount, int &moveCount) {
  compCount = 0;
  moveCount = 0;
  for (int unsorted = 1; unsorted < size; ++unsorted) {
    moveCount++;
    int nextItem = arr[unsorted];
    int loc = unsorted;

    for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
       compCount++;
       moveCount++;
       arr[loc] = arr[loc-1];
    }
    arr[loc] = nextItem;
    compCount++;
    moveCount++;
  }
}





void mergeSort(int *arr, int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergeSort(arr, first, mid, compCount, moveCount);

      mergeSort(arr, mid+1, last, compCount, moveCount);

      // merge the two halves
      merge(arr, first, mid, last, compCount, moveCount);
   }
}  // end mergesort

void merge( int arr[], int first, int mid, int last, int &compCount, int &moveCount) {

   int tempArray[last+1]; 	// temporary array

   int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      if (arr[first1] < arr[first2]) {
         tempArray[index] = arr[first1];
         ++first1;
      }
      else {
          tempArray[index] = arr[first2];
          ++first2;
      }
      moveCount++;
      compCount++;
   }
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index) {
      tempArray[index] = arr[first1];
      moveCount++;
   }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index) {
      tempArray[index] = arr[first2];
      moveCount++;
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index) {
      arr[index] = tempArray[index];
      moveCount++;
   }

}  // end merge

void quickSort(int *arr, int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

void quickSort(int *arr, int first, int last, int &compCount, int &moveCount) {
// Precondition: arr[first..last] is an array.
// Postcondition: arr[first..last] is sorted.

	int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(arr, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quickSort(arr, first, pivotIndex-1, compCount, moveCount);
      quickSort(arr, pivotIndex+1, last, compCount, moveCount);
   }
}

void partition(int arr[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
   // Precondition: arr[first..last] is an array; first <= last.
   // Postcondition: Partitions arr[first..last] such that:
   //   S1 = arr[first..pivotIndex-1] < pivot
   //   arr[pivotIndex] == pivot
   //   S2 = arr[pivotIndex+1..last] >= pivot

   int pivot = arr[first]; // copy pivot
   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: arr[first+1..lastS1] < pivot
      //            arr[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (arr[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(arr[firstUnknown], arr[lastS1], compCount, moveCount);
      }	// else belongs to S2
      compCount++;
   }
   // place pivot in proper position and mark its location
   swap(arr[first], arr[lastS1], compCount, moveCount);
   pivotIndex = lastS1;
}

void swap(int &x, int &y, int &compCount, int &moveCount) {
   int temp = x;
   x = y;
   y = temp;
   moveCount+=3;
}
