#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to populate the array with random numbers
void populateArray(int array[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 451 + 50; // Random number between 50 and 500
    }
}

// Function to display the array
void displayArray(const int array[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to swap two elements in the array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to sort the array using Bubble Sort
void sortArray(int array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Exit if no swaps occurred
    }
}

// Function to measure sort time for arrays of various sizes
void measureSortTime(size_t startSize, size_t endSize, size_t step) {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    cout << fixed << setprecision(3);
    cout << "Array Size\tSort Runtime (ms)" << endl;

    for (size_t size = startSize; size <= endSize; size += step) {
        int *array = new int[size];

        // Populate and display the array before sorting
        populateArray(array, size);
        cout << "Array before sort: ";
        displayArray(array, size);
        cout << endl;

        // Measure sort time
        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        sortArray(array, size);
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

        // Display the sorted array
        cout << "Array after sort: ";
        displayArray(array, size);
        cout << endl;

        // Calculate and display the runtime
        chrono::microseconds sortDuration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Array Size: " << size << "\t\tSort Runtime (ms): " << sortDuration.count() / 1000.0 << " ms" << endl << endl;

        delete[] array; // Free the allocated memory
    }
}

int main() {
    const size_t startSize = 10;   // Starting size of the array
    const size_t endSize = 50;    // Ending size of the array
    const size_t step = 10;       // Step size for increasing array size

    measureSortTime(startSize, endSize, step);

    return 0;
}

