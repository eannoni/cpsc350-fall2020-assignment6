#ifndef SORTS
#define SORTS

#include <iostream>

using namespace std;

class Sorts {
    public:
        static bool quickSort(double* arr, int size);
        static bool mergeSort(double* arr, int size);
        static bool selectionSort(double* arr, int size);
        static bool insertionSort(double* arr, int size);
        static bool bubbleSort(double* arr, int size);

    private:
        static void quickSort(double* arr, int lowIndex, int highIndex);
        static int quickSortPartition(double* arr, int lowIndex, int highIndex);
        static void mergeSort(double* arr, int i, int k);
        static void merge(double* arr, int i, int j, int k);
};

#endif
