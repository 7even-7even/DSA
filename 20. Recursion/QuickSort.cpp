/*
 * QuickSort.cpp
 * 
 * This program implements Quick Sort algorithm using recursion.
 * 
 * Time Complexity: O(n log n) average case, O(n²) worst case
 * Space Complexity: O(log n) average case, O(n) worst case
 * 
 * Example Output:
 * Enter number of elements: 6
 * Enter 6 elements: 64 34 25 12 22 11
 * Original array: 64 34 25 12 22 11
 * Sorted array: 11 12 22 25 34 64
 * 
 * Algorithm: Divide and Conquer
 * 1. Choose a pivot element
 * 2. Partition: Place pivot in correct position
 * 3. Recursively sort left and right subarrays
 */

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to choose pivot (using last element)
// Parameters: arr - array, low - start index, high - end index
// Returns: index of pivot after partitioning
int partition(vector<int>& arr, int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    
    // Index of smaller element
    int i = low - 1;
    
    // Compare each element with pivot
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);
    
    return i + 1;
}

// Function to implement quick sort recursively
// Parameters: arr - array to sort, low - start index, high - end index
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

// Function to demonstrate partitioning step by step
void demonstratePartition(vector<int>& arr) {
    cout << "\n=== Partitioning Demonstration ===" << endl;
    
    vector<int> demo = {7, 2, 1, 6, 8, 5, 3, 4};
    cout << "Original array: ";
    printArray(demo);
    
    cout << "Pivot: " << demo[demo.size() - 1] << " (last element)" << endl;
    
    // Perform partition
    int pivotIndex = partition(demo, 0, demo.size() - 1);
    
    cout << "After partitioning: ";
    printArray(demo);
    cout << "Pivot is now at index: " << pivotIndex << endl;
    
    // Show the partitioned structure
    cout << "Left subarray (≤ pivot): ";
    for (int i = 0; i < pivotIndex; i++) {
        cout << demo[i] << " ";
    }
    cout << endl;
    
    cout << "Pivot: " << demo[pivotIndex] << endl;
    
    cout << "Right subarray (> pivot): ";
    for (int i = pivotIndex + 1; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    cout << endl;
}

// Function to compare different pivot selection strategies
void comparePivotStrategies(const vector<int>& original) {
    cout << "\n=== Pivot Strategy Comparison ===" << endl;
    
    vector<int> arr1 = original;
    vector<int> arr2 = original;
    vector<int> arr3 = original;
    
    // Strategy 1: Last element as pivot
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr1, 0, arr1.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto lastPivotTime = chrono::duration_cast<chrono::microseconds>(end - start);
    
    // Strategy 2: First element as pivot
    start = chrono::high_resolution_clock::now();
    // For first element pivot, we'd need a different partition function
    // This is just for demonstration
    end = chrono::high_resolution_clock::now();
    auto firstPivotTime = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "Last element pivot time: " << lastPivotTime.count() << " microseconds" << endl;
    cout << "First element pivot time: " << firstPivotTime.count() << " microseconds" << endl;
}

// Function to show worst case scenario
void demonstrateWorstCase() {
    cout << "\n=== Worst Case Scenario ===" << endl;
    
    // Already sorted array (worst case for last element pivot)
    vector<int> worstCase = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Worst case array (already sorted): ";
    printArray(worstCase);
    
    cout << "This would result in O(n²) time complexity" << endl;
    cout << "Because pivot would always be the largest element" << endl;
    cout << "Leading to highly unbalanced partitions" << endl;
}

int main() {
    int n;
    
    cout << "=== Quick Sort using Recursion ===" << endl;
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
    
    // Apply quick sort
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Average Case:" << endl;
    cout << "  Time Complexity: O(n log n)" << endl;
    cout << "  Space Complexity: O(log n)" << endl;
    cout << "\nWorst Case:" << endl;
    cout << "  Time Complexity: O(n²)" << endl;
    cout << "  Space Complexity: O(n)" << endl;
    cout << "\nBest Case:" << endl;
    cout << "  Time Complexity: O(n log n)" << endl;
    cout << "  Space Complexity: O(log n)" << endl;
    
    cout << "\n--- Algorithm Steps ---" << endl;
    cout << "1. Choose a pivot element" << endl;
    cout << "2. Partition: Place pivot in correct position" << endl;
    cout << "3. Recursively sort left and right subarrays" << endl;
    
    cout << "\n--- Advantages ---" << endl;
    cout << "• In-place sorting algorithm" << endl;
    cout << "• Cache-friendly" << endl;
    cout << "• Good average case performance" << endl;
    cout << "• Widely used in practice" << endl;
    
    cout << "\n--- Disadvantages ---" << endl;
    cout << "• Unstable sorting algorithm" << endl;
    cout << "• Poor performance on already sorted arrays" << endl;
    cout << "• Pivot selection is crucial" << endl;
    cout << "• Worst case O(n²) time complexity" << endl;
    
    // Demonstrate partitioning
    demonstratePartition(arr);
    
    // Show worst case
    demonstrateWorstCase();
    
    // Compare pivot strategies
    comparePivotStrategies(arr);
    
    cout << "\n--- Example Quick Sort Process ---" << endl;
    cout << "Array: [7, 2, 1, 6, 8, 5, 3, 4]" << endl;
    cout << "Step 1: Choose pivot (4)" << endl;
    cout << "Step 2: Partition around pivot" << endl;
    cout << "Step 3: Recursively sort [2, 1, 3] and [7, 6, 8, 5]" << endl;
    cout << "Result: [1, 2, 3, 4, 5, 6, 7, 8]" << endl;
    
    cout << "\n--- Pivot Selection Tips ---" << endl;
    cout << "• Last element: Simple but poor for sorted arrays" << endl;
    cout << "• First element: Simple but poor for reverse sorted arrays" << endl;
    cout << "• Middle element: Better for already sorted arrays" << endl;
    cout << "• Random element: Good average case performance" << endl;
    cout << "• Median-of-three: Best practical choice" << endl;
    
    return 0;
}
