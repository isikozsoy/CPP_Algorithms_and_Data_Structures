/*
* Title: Algorithm Efficiency and Sorting
* Author: Isik Ozsoy
* ID: 21703160
* Section: 1
* Assignment: 1
* Description: description of your code
*/

#ifndef sorting_h
#define sorting_h

    void insertionSort(int *arr, int size, int &compCount, int &moveCount);

    void quickSort(int *arr, int size, int &compCount, int &moveCount);
    void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void partition(int arr[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
    void swap(int &x, int &y, int &compCount, int &moveCount);

    void mergeSort(int *arr, int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount);

#endif
