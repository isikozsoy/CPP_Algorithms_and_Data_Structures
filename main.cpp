/*
* Title: Algorithm Efficiency and Sorting
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 1
* Description: description of your code
*/

#include <ctime>
#include <iostream>
#include "sorting.h"
#include "auxArrayFunctions.h"
#include "partc.h"

using namespace std;

main() {
    performanceAnalysis();
    int compCount = 0;
    int moveCount = 0;
    int arrayTestInsertion[16] =  {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    displayArray(arrayTestInsertion, 16);
    insertionSort(arrayTestInsertion, 16, compCount, moveCount);
    displayArray(arrayTestInsertion, 16);
    cout << "insertion sort: num of key comp: " << compCount << "   num of movement: " << moveCount << endl;

    int arrayTestMerge[16] =  {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    displayArray(arrayTestMerge, 16);
    mergeSort(arrayTestMerge, 16, compCount, moveCount);
    displayArray(arrayTestMerge, 16);
    cout << "merge sort: num of key comp: " << compCount << "   num of movement: " << moveCount << endl;

    int arrayTestQuick[16] =  {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    displayArray(arrayTestQuick, 16);
    quickSort(arrayTestQuick, 16, compCount, moveCount);
    displayArray(arrayTestQuick, 16);
    cout << "quick sort: num of key comp: " << compCount << "   num of movement: " << moveCount << endl;
    return 0;
}
