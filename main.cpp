#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */
#include "Sorts.h"

using namespace std;

void printArray(double* arr, int arrSize) {
    cout << "[ ";
    for(int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void randomizeArray(double* arr, int arrSize) {
    srand (time(NULL));
    for(int i = 0; i < arrSize; ++i) {
        double temp = arr[i];
        int randIndex = rand() % (arrSize - i) + i;
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
}

int main(int argc, char** argv) {

    string fileName = "";
    ifstream file;
    bool running = true;
    double* arrSelectionSort;
    double* arrInsertionSort;
    double* arrBubbleSort;
    double* arrQuickSort;
    double* arrMergeSort;
    int arrSize;
    time_t startTime;
    time_t endTime;
    time_t elapsedTime;

    // get command line input
    if(argc != 2) {
        cout << "Invalid command line parameters, please enter a file name." << endl;
        return -1;
    } else {
        fileName = argv[1];
    }

    // open file
    file.open(fileName);
    while(!file.is_open()) {
        cout << "Unable to locate file \'" << fileName << "\'. Please input name of a file: ";
        cin >> fileName;
        file.open(fileName);
    }

    // initialize arrays
    cout << "Loading file..." << endl;
    string currLine;
    getline(file, currLine);
    arrSize = stoi(currLine);
    arrSelectionSort = new double[arrSize];
    arrInsertionSort = new double[arrSize];
    arrBubbleSort = new double[arrSize];
    arrQuickSort = new double[arrSize];
    arrMergeSort = new double[arrSize];

    // save doubles into arrays
    for(int i = 0; i < arrSize; ++i) {
        getline(file, currLine);
        arrSelectionSort[i] = stod(currLine);
        arrInsertionSort[i] = stod(currLine);
        arrBubbleSort[i] = stod(currLine);
        arrQuickSort[i] = stod(currLine);
        arrMergeSort[i] = stod(currLine);
    }
    file.close();

    cout << "finished." << endl;

    cout << "\nStarting sorts..." << endl;

    cout << "\n-------- Selection Sort --------" << endl;
    cout << "sorting..." << endl;
    startTime = time(0);
    Sorts::selectionSort(arrSelectionSort, arrSize);
    endTime = time(0);
    elapsedTime = endTime - startTime;
    cout << "finished." << endl;
    cout << "Start time: " << startTime << endl;
    cout << "End time: " << endTime << endl;
    cout << "Elapsed time: " << elapsedTime << endl;

    cout << "\n-------- Insertion Sort --------" << endl;
    cout << "sorting..." << endl;
    startTime = time(0);
    Sorts::insertionSort(arrInsertionSort, arrSize);
    endTime = time(0);
    elapsedTime = endTime - startTime;
    cout << "finished." << endl;
    cout << "Start time: " << startTime << endl;
    cout << "End time: " << endTime << endl;
    cout << "Elapsed time: " << elapsedTime << endl;

    cout << "\n-------- Bubble Sort --------" << endl;
    cout << "sorting..." << endl;
    startTime = time(0);
    Sorts::bubbleSort(arrBubbleSort, arrSize);
    endTime = time(0);
    elapsedTime = endTime - startTime;
    cout << "finished." << endl;
    cout << "Start time: " << startTime << endl;
    cout << "End time: " << endTime << endl;
    cout << "Elapsed time: " << elapsedTime << endl;

    cout << "\n-------- Quick Sort --------" << endl;
    cout << "sorting..." << endl;
    startTime = time(0);
    Sorts::quickSort(arrQuickSort, arrSize);
    endTime = time(0);
    elapsedTime = endTime - startTime;
    cout << "finished." << endl;
    cout << "Start time: " << startTime << endl;
    cout << "End time: " << endTime << endl;
    cout << "Elapsed time: " << elapsedTime << endl;

    cout << "\n-------- Merge Sort --------" << endl;
    cout << "sorting..." << endl;
    startTime = time(0);
    Sorts::mergeSort(arrMergeSort, arrSize);
    endTime = time(0);
    elapsedTime = endTime - startTime;
    cout << "finished." << endl;
    cout << "Start time: " << startTime << endl;
    cout << "End time: " << endTime << endl;
    cout << "Elapsed time: " << elapsedTime << endl;

    delete[] arrSelectionSort;
    delete[] arrInsertionSort;
    delete[] arrBubbleSort;
    delete[] arrQuickSort;
    delete[] arrMergeSort;

    return 0;
}
