/*
 * 0/1 Knapsack Problem using Dynamic Programming
 * 
 * Problem: Given a set of items with weights and values, and a knapsack with capacity W,
 * find the maximum value that can be obtained by selecting items such that
 * the total weight doesn't exceed the capacity.
 * 
 * Dynamic Programming Approach: Bottom-up
 * Time Complexity: O(n * W) where n = number of items, W = capacity
 * Space Complexity: O(n * W)
 * 
 * Expected Output Example:
 * Enter the number of items: 4
 * Enter the capacity of knapsack: 7
 * 
 * Enter weight and value for each item:
 * Item 1 - Weight: 1 Value: 1
 * Item 2 - Weight: 3 Value: 4
 * Item 3 - Weight: 4 Value: 5
 * Item 4 - Weight: 5 Value: 7
 * 
 * Maximum value: 9
 * Selected items: Item 2 (weight: 3, value: 4) + Item 4 (weight: 4, value: 5)
 * Total weight used: 7
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    int id;
    
    Item(int w, int v, int i) : weight(w), value(v), id(i) {}
};

class KnapsackDP {
private:
    vector<Item> items;
    int capacity;
    int n;
    
public:
    KnapsackDP(vector<Item>& itemList, int cap) {
        items = itemList;
        capacity = cap;
        n = items.size();
    }
    
    // Solve 0/1 Knapsack using dynamic programming
    pair<int, vector<int>> solve() {
        // Create 2D DP table
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                // Don't include current item
                dp[i][w] = dp[i - 1][w];
                
                // Include current item if possible
                if (items[i - 1].weight <= w) {
                    dp[i][w] = max(dp[i][w], 
                                  dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
                }
            }
        }
        
        // Reconstruct the solution
        vector<int> selectedItems;
        int w = capacity;
        
        for (int i = n; i > 0 && w > 0; i--) {
            if (dp[i][w] != dp[i - 1][w]) {
                selectedItems.push_back(i - 1);  // Item index
                w -= items[i - 1].weight;
            }
        }
        
        reverse(selectedItems.begin(), selectedItems.end());
        
        return {dp[n][capacity], selectedItems};
    }
    
    // Print the DP table (for debugging/understanding)
    void printDPTable() {
        cout << "\n--- DP Table (showing first 10 rows/columns for clarity) ---" << endl;
        
        int maxRows = min(n + 1, 11);
        int maxCols = min(capacity + 1, 11);
        
        // Print header
        cout << "     ";
        for (int w = 0; w < maxCols; w++) {
            printf("%3d ", w);
        }
        cout << endl;
        
        // Print table
        for (int i = 0; i < maxRows; i++) {
            if (i == 0) {
                printf("%3d: ", i);
            } else {
                printf("%3d: ", i);
            }
            
            for (int w = 0; w < maxCols; w++) {
                if (i == 0) {
                    printf("%3d ", 0);
                } else {
                    printf("%3d ", (w < items[i - 1].weight) ? 
                           dp[i - 1][w] : 
                           max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value));
                }
            }
            cout << endl;
        }
        
        if (n > 10 || capacity > 10) {
            cout << "... (showing only first 10 rows/columns)" << endl;
        }
    }
    
    // Print selected items
    void printSelectedItems(const vector<int>& selectedItems) {
        if (selectedItems.empty()) {
            cout << "No items selected!" << endl;
            return;
        }
        
        cout << "Selected items:" << endl;
        int totalWeight = 0;
        int totalValue = 0;
        
        for (int idx : selectedItems) {
            cout << "  Item " << items[idx].id 
                 << " (weight: " << items[idx].weight 
                 << ", value: " << items[idx].value << ")" << endl;
            totalWeight += items[idx].weight;
            totalValue += items[idx].value;
        }
        
        cout << "\nSummary:" << endl;
        cout << "  Total weight used: " << totalWeight << "/" << capacity << endl;
        cout << "  Total value: " << totalValue << endl;
        cout << "  Efficiency: " << (double)totalValue / totalWeight << " value per weight unit" << endl;
    }
    
    // Print all items for reference
    void printAllItems() {
        cout << "\nAll available items:" << endl;
        for (const Item& item : items) {
            cout << "  Item " << item.id 
                 << " (weight: " << item.weight 
                 << ", value: " << item.value 
                 << ", ratio: " << (double)item.value / item.weight << ")" << endl;
        }
    }
};

int main() {
    cout << "=== 0/1 Knapsack Problem using Dynamic Programming ===" << endl;
    
    // Get number of items
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: Number of items must be positive!" << endl;
        return 1;
    }
    
    // Get knapsack capacity
    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    
    if (capacity <= 0) {
        cout << "Error: Capacity must be positive!" << endl;
        return 1;
    }
    
    // Get items
    vector<Item> items;
    cout << "\nEnter weight and value for each item:" << endl;
    
    for (int i = 0; i < n; i++) {
        int weight, value;
        cout << "Item " << (i + 1) << " - Weight: ";
        cin >> weight;
        cout << "Item " << (i + 1) << " - Value: ";
        cin >> value;
        
        if (weight <= 0 || value < 0) {
            cout << "Error: Weight must be positive and value must be non-negative!" << endl;
            return 1;
        }
        
        items.push_back(Item(weight, value, i + 1));
    }
    
    // Create KnapsackDP object
    KnapsackDP kpDP(items, capacity);
    
    // Print all items
    kpDP.printAllItems();
    
    // Solve the problem
    auto result = kpDP.solve();
    int maxValue = result.first;
    vector<int> selectedItems = result.second;
    
    // Display results
    cout << "\n--- Results ---" << endl;
    cout << "Maximum value: " << maxValue << endl;
    
    // Print selected items
    kpDP.printSelectedItems(selectedItems);
    
    // Print DP table for understanding
    kpDP.printDPTable();
    
    // Additional information
    cout << "\n--- Additional Information ---" << endl;
    cout << "Time Complexity: O(n * W) where n = " << n << ", W = " << capacity << endl;
    cout << "Space Complexity: O(n * W)" << endl;
    cout << "Method: Bottom-up Dynamic Programming" << endl;
    cout << "Problem Type: 0/1 Knapsack (each item can be used at most once)" << endl;
    
    return 0;
}
