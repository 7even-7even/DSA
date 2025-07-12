/*
 * MergeSort.cpp
 * 
 * This program implements Merge Sort algorithm using recursion.
 * 
 * Time Complexity: O(n log n) - where n is the number of elements
 * Space Complexity: O(n) - additional space for temporary arrays
 * 
 * Example Output:
 * Enter number of elements: 6
 * Enter 6 elements: 64 34 25 12 22 11
 * Original array: 64 34 25 12 22 11
 * Sorted array: 11 12 22 25 34 64
 * 
 * Algorithm: Divide and Conquer
 * 1. Divide: Split array into two halves
 * 2. Conquer: Recursively sort the two halves
 * 3. Merge: Merge the sorted halves
 */

#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays
// Parameters: arr - original array, left - left index, mid - middle index, right - right index
void merge(vector<int>& arr, int left, int mid, int right) {
    // Calculate sizes of two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort recursively
// Parameters: arr - array to sort, left - left index, right - right index
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << endl;
}

// Function to demonstrate the merge process step by step
void demonstrateMerge(vector<int>& arr) {
    cout << "\n=== Merge Process Demonstration ===" << endl;
    
    // Create a small example
    vector<int> demo = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array: ";
    printArray(demo);
    
    // Sort the demo array
    mergeSort(demo, 0, demo.size() - 1);
    
    cout << "Sorted array: ";
    printArray(demo);
}

// Function to compare with other sorting algorithms
void compareSortingAlgorithms(const vector<int>& original) {
    cout << "\n=== Algorithm Comparison ===" << endl;
    
    vector<int> arr1 = original;
    vector<int> arr2 = original;
    
    // Merge Sort
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr1, 0, arr1.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto mergeTime = chrono::duration_cast<chrono::microseconds>(end - start);
    
    // Bubble Sort (for comparison)
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < arr2.size() - 1; i++) {
        for (int j = 0; j < arr2.size() - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                swap(arr2[j], arr2[j + 1]);
            }
        }
    }
    end = chrono::high_resolution_clock::now();
    auto bubbleTime = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "Merge Sort time: " << mergeTime.count() << " microseconds" << endl;
    cout << "Bubble Sort time: " << bubbleTime.count() << " microseconds" << endl;
}

int main() {
    int n;
    
    cout << "=== Merge Sort using Recursion ===" << endl;
    cout << "Enter number of elements: ";
    cin >> n;
    
    // Input validation
    if (n <= 0) {
        cout << "Error: Please enter a positive number!" << endl;
        return 1;
    }
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\nOriginal array: ";
    printArray(arr);
    
    // Apply merge sort
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Time Complexity: O(n log n)" << endl;
    cout << "Space Complexity: O(n)" << endl;
    cout << "Stable: Yes" << endl;
    cout << "In-place: No (requires extra space)" << endl;
    
    cout << "\n--- Algorithm Steps ---" << endl;
    cout << "1. Divide: Split array into two halves" << endl;
    cout << "2. Conquer: Recursively sort the two halves" << endl;
    cout << "3. Merge: Merge the sorted halves" << endl;
    
    cout << "\n--- Advantages ---" << endl;
    cout << "• Guaranteed O(n log n) time complexity" << endl;
    cout << "• Stable sorting algorithm" << endl;
    cout << "• Good for large datasets" << endl;
    cout << "• Predictable performance" << endl;
    
    cout << "\n--- Disadvantages ---" << endl;
    cout << "• Requires extra space O(n)" << endl;
    cout << "• Not in-place sorting" << endl;
    cout << "• Overkill for small arrays" << endl;
    
    // Demonstrate merge process
    demonstrateMerge(arr);
    
    // Compare with other algorithms
    compareSortingAlgorithms(arr);
    
    cout << "\n--- Example Merge Process ---" << endl;
    cout << "Array: [38, 27, 43, 3, 9, 82, 10]" << endl;
    cout << "Step 1: Divide into [38, 27, 43, 3] and [9, 82, 10]" << endl;
    cout << "Step 2: Recursively sort each half" << endl;
    cout << "Step 3: Merge sorted halves: [3, 27, 38, 43] + [9, 10, 82]" << endl;
    cout << "Result: [3, 9, 10, 27, 38, 43, 82]" << endl;
    
    return 0;
}
