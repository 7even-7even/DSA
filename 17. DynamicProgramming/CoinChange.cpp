/*
 * Coin Change Problem using Dynamic Programming
 * 
 * Problem: Given a set of coin denominations and a target amount,
 * find the minimum number of coins needed to make the target amount.
 * Also find the total number of ways to make the target amount.
 * 
 * Dynamic Programming Approach: Bottom-up
 * Time Complexity: O(amount * number of coins)
 * Space Complexity: O(amount)
 * 
 * Expected Output Example:
 * Enter the number of coin denominations: 3
 * Enter coin denominations: 1 2 5
 * Enter the target amount: 11
 * 
 * Minimum coins needed: 3 (5 + 5 + 1)
 * Total ways to make change: 12
 * 
 * Ways breakdown:
 * 1: 1 way
 * 2: 2 ways (1+1, 2)
 * 3: 2 ways (1+1+1, 1+2)
 * 4: 3 ways (1+1+1+1, 1+1+2, 2+2)
 * 5: 4 ways (1+1+1+1+1, 1+1+1+2, 1+2+2, 5)
 * ...
 * 11: 12 ways
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class CoinChangeDP {
private:
    vector<int> coins;
    int amount;
    
public:
    CoinChangeDP(vector<int>& coinDenominations, int targetAmount) {
        coins = coinDenominations;
        amount = targetAmount;
    }
    
    // Find minimum number of coins needed
    int findMinCoins() {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        // Fill dp array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    
    // Find total number of ways to make change
    int findTotalWays() {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  // One way to make amount 0 (no coins)
        
        // Fill dp array
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
    
    // Print all ways to make change (for smaller amounts)
    void printWaysBreakdown() {
        cout << "\nWays breakdown for amounts 1 to " << min(amount, 10) << ":" << endl;
        
        for (int target = 1; target <= min(amount, 10); target++) {
            vector<int> dp(target + 1, 0);
            dp[0] = 1;
            
            for (int coin : coins) {
                for (int i = coin; i <= target; i++) {
                    dp[i] += dp[i - coin];
                }
            }
            
            cout << target << ": " << dp[target] << " ways" << endl;
        }
        
        if (amount > 10) {
            cout << "... (showing only first 10 for brevity)" << endl;
        }
    }
    
    // Print the coins used for minimum solution
    void printMinCoinsSolution() {
        vector<int> dp(amount + 1, INT_MAX);
        vector<int> prev(amount + 1, -1);
        dp[0] = 0;
        
        // Fill dp array and track previous coin
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    if (dp[i - coin] + 1 < dp[i]) {
                        dp[i] = dp[i - coin] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        
        if (dp[amount] == INT_MAX) {
            cout << "No solution exists!" << endl;
            return;
        }
        
        // Reconstruct the solution
        cout << "Minimum coins solution: ";
        int current = amount;
        vector<int> usedCoins;
        
        while (current > 0) {
            usedCoins.push_back(coins[prev[current]]);
            current -= coins[prev[current]];
        }
        
        // Sort and print
        sort(usedCoins.begin(), usedCoins.end(), greater<int>());
        for (int i = 0; i < usedCoins.size(); i++) {
            cout << usedCoins[i];
            if (i < usedCoins.size() - 1) cout << " + ";
        }
        cout << " = " << amount << endl;
    }
};

int main() {
    cout << "=== Coin Change Problem using Dynamic Programming ===" << endl;
    
    // Get number of coin denominations
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: Number of denominations must be positive!" << endl;
        return 1;
    }
    
    // Get coin denominations
    vector<int> coins(n);
    cout << "Enter coin denominations (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        if (coins[i] <= 0) {
            cout << "Error: Coin denominations must be positive!" << endl;
            return 1;
        }
    }
    
    // Get target amount
    int amount;
    cout << "Enter the target amount: ";
    cin >> amount;
    
    if (amount < 0) {
        cout << "Error: Target amount must be non-negative!" << endl;
        return 1;
    }
    
    // Create CoinChangeDP object
    CoinChangeDP ccDP(coins, amount);
    
    // Find minimum coins
    int minCoins = ccDP.findMinCoins();
    cout << "\n--- Results ---" << endl;
    
    if (minCoins == -1) {
        cout << "It's not possible to make the target amount with given coins!" << endl;
    } else {
        cout << "Minimum coins needed: " << minCoins << endl;
        ccDP.printMinCoinsSolution();
    }
    
    // Find total ways
    int totalWays = ccDP.findTotalWays();
    cout << "Total ways to make change: " << totalWays << endl;
    
    // Print breakdown for smaller amounts
    ccDP.printWaysBreakdown();
    
    // Additional information
    cout << "\n--- Additional Information ---" << endl;
    cout << "Time Complexity: O(amount * number of coins)" << endl;
    cout << "Space Complexity: O(amount)" << endl;
    cout << "Method: Bottom-up Dynamic Programming" << endl;
    
    return 0;
}
