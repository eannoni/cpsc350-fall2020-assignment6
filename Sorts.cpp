#include "Sorts.h"

bool Sorts::quickSort(double* arr, int size) {
    quickSort(arr, 0, size - 1);
    return true;
}

bool Sorts::mergeSort(double* arr, int size) {
    mergeSort(arr, 0, size - 1);
    return true;
}

bool Sorts::selectionSort(double* arr, int size) {
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    double temp = 0;

    for(i = 0; i < size - 1; ++i) {
        indexSmallest = i;
        for(j = i + 1; j < size; ++j) {
            if(arr[j] < arr[indexSmallest]) {
                indexSmallest = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexSmallest];
        arr[indexSmallest] = temp;
    }
    return true;
}

bool Sorts::insertionSort(double* arr, int size) {
    int i = 0;
    int j = 0;
    double temp = 0;

    for(i = 1; i < size; ++i) {
        j = i;
        while(j > 0 && arr[j] < arr[j - 1]) {
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    return true;
}

bool Sorts::bubbleSort(double* arr, int size) {
    int i = 0;
    int j = 0;
    double temp = 0;

    for(i = 0; i < size; ++i) {
        for(j = 0; j < size - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return true;
}



/* Private Methods */

void Sorts::quickSort(double* arr, int lowIndex, int highIndex) {
    if(lowIndex >= highIndex) {
        return;
    }

    int lowEndIndex = quickSortPartition(arr, lowIndex, highIndex);
    quickSort(arr, lowIndex, lowEndIndex);
    quickSort(arr, lowEndIndex + 1, highIndex);
}

int Sorts::quickSortPartition(double* arr, int lowIndex, int highIndex) {
   // Pick middle element as pivot
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   double pivot = arr[midpoint];

   bool done = false;
   while (!done) {
      // Increment lowIndex while arr[lowIndex] < pivot
      while (arr[lowIndex] < pivot) {
         lowIndex += 1;
      }

      // Decrement highIndex while pivot < arr[highIndex]
      while (pivot < arr[highIndex]) {
         highIndex -= 1;
      }

      // If zero or one elements remain, then all arr are
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true;
     } else {
         // Swap arr[lowIndex] and arr[highIndex]
         double temp = arr[lowIndex];
         arr[lowIndex] = arr[highIndex];
         arr[highIndex] = temp;

         // Update lowIndex and highIndex
         lowIndex += 1;
         highIndex -= 1;
      }
   }
   return highIndex;
}

void Sorts::mergeSort(double* arr, int i, int k) {
    int j = 0;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        mergeSort(arr, i, j);
        mergeSort(arr, j + 1, k);

        // Merge left and right partition in sorted order
        merge(arr, i, j, k);
    }
}

void Sorts::merge(double* arr, int i, int j, int k) {
   int mergedSize = k - i + 1;
   int mergePos = 0;
   int leftPos = 0;
   int rightPos = 0;
   double* mergedArr = new double[mergedSize];

   leftPos = i;
   rightPos = j + 1;

   // Add smallest element from left or right partition to merged arr
   while (leftPos <= j && rightPos <= k) {
      if (arr[leftPos] <= arr[rightPos]) {
         mergedArr[mergePos] = arr[leftPos];
         ++leftPos;
      }
      else {
         mergedArr[mergePos] = arr[rightPos];
         ++rightPos;

      }
      ++mergePos;
   }

   // If left partition is not empty, add remaining elements to merged arr
   while (leftPos <= j) {
      mergedArr[mergePos] = arr[leftPos];
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged arr
   while (rightPos <= k) {
      mergedArr[mergePos] = arr[rightPos];
      ++rightPos;
      ++mergePos;
   }

   // Copy merge number back to arr
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      arr[i + mergePos] = mergedArr[mergePos];
   }
}
