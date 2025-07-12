/*
 * Longest Common Subsequence (LCS) using Dynamic Programming
 * 
 * Problem: Given two sequences, find the length of the longest subsequence
 * that appears in both sequences in the same order, but not necessarily consecutively.
 * 
 * Dynamic Programming Approach: Bottom-up
 * Time Complexity: O(m * n) where m, n are lengths of sequences
 * Space Complexity: O(m * n)
 * 
 * Expected Output Example:
 * Enter the first sequence: ABCDEF
 * Enter the second sequence: BDF
 * 
 * Length of LCS: 3
 * LCS: BDF
 * 
 * Another example:
 * Sequence 1: AGTAB
 * Sequence 2: GXTXAYB
 * LCS: GTAB (length: 4)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class LCSDP {
private:
    string seq1, seq2;
    int m, n;
    
public:
    LCSDP(string& sequence1, string& sequence2) {
        seq1 = sequence1;
        seq2 = sequence2;
        m = seq1.length();
        n = seq2.length();
    }
    
    // Find LCS length and reconstruct the sequence
    pair<int, string> findLCS() {
        // Create 2D DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Reconstruct the LCS
        string lcs = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                lcs = seq1[i - 1] + lcs;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        
        return {dp[m][n], lcs};
    }
    
    // Print the DP table for understanding
    void printDPTable() {
        cout << "\n--- DP Table ---" << endl;
        
        // Print header
        cout << "    ";
        for (int j = 0; j <= n; j++) {
            if (j == 0) cout << "  ";
            else cout << " " << seq2[j - 1] << " ";
        }
        cout << endl;
        
        // Print table
        for (int i = 0; i <= m; i++) {
            if (i == 0) cout << "  ";
            else cout << " " << seq1[i - 1] << " ";
            
            for (int j = 0; j <= n; j++) {
                printf("%2d ", (i == 0 || j == 0) ? 0 : 
                       (seq1[i - 1] == seq2[j - 1] ? 
                        dp[i - 1][j - 1] + 1 : 
                        max(dp[i - 1][j], dp[i][j - 1])));
            }
            cout << endl;
        }
    }
    
    // Find all possible LCS (if multiple exist)
    vector<string> findAllLCS() {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        vector<string> allLCS;
        findAllLCSUtil(dp, m, n, "", allLCS);
        
        // Remove duplicates and sort
        sort(allLCS.begin(), allLCS.end());
        allLCS.erase(unique(allLCS.begin(), allLCS.end()), allLCS.end());
        
        return allLCS;
    }
    
private:
    void findAllLCSUtil(const vector<vector<int>>& dp, int i, int j, string current, vector<string>& result) {
        if (i == 0 || j == 0) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        
        if (seq1[i - 1] == seq2[j - 1]) {
            findAllLCSUtil(dp, i - 1, j - 1, seq1[i - 1] + current, result);
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            findAllLCSUtil(dp, i - 1, j, current, result);
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            findAllLCSUtil(dp, i, j - 1, current, result);
        } else {
            // Both directions are equal, explore both
            findAllLCSUtil(dp, i - 1, j, current, result);
            findAllLCSUtil(dp, i, j - 1, current, result);
        }
    }
    
public:
    // Print detailed analysis
    void printAnalysis() {
        cout << "\n--- Detailed Analysis ---" << endl;
        cout << "Sequence 1: \"" << seq1 << "\" (length: " << m << ")" << endl;
        cout << "Sequence 2: \"" << seq2 << "\" (length: " << n << ")" << endl;
        
        // Find all LCS
        vector<string> allLCS = findAllLCS();
        
        if (allLCS.size() == 1) {
            cout << "Unique LCS found!" << endl;
        } else {
            cout << "Multiple LCS found (" << allLCS.size() << "):" << endl;
            for (const string& lcs : allLCS) {
                cout << "  \"" << lcs << "\"" << endl;
            }
        }
        
        // Show subsequence positions
        auto result = findLCS();
        string lcs = result.second;
        
        if (!lcs.empty()) {
            cout << "\nSubsequence positions:" << endl;
            cout << "In sequence 1: ";
            int pos1 = 0;
            for (char c : lcs) {
                while (pos1 < m && seq1[pos1] != c) pos1++;
                cout << pos1 + 1;
                if (c != lcs.back()) cout << ", ";
                pos1++;
            }
            cout << endl;
            
            cout << "In sequence 2: ";
            int pos2 = 0;
            for (char c : lcs) {
                while (pos2 < n && seq2[pos2] != c) pos2++;
                cout << pos2 + 1;
                if (c != lcs.back()) cout << ", ";
                pos2++;
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Longest Common Subsequence using Dynamic Programming ===" << endl;
    
    // Get first sequence
    string seq1;
    cout << "Enter the first sequence: ";
    cin >> seq1;
    
    if (seq1.empty()) {
        cout << "Error: First sequence cannot be empty!" << endl;
        return 1;
    }
    
    // Get second sequence
    string seq2;
    cout << "Enter the second sequence: ";
    cin >> seq2;
    
    if (seq2.empty()) {
        cout << "Error: Second sequence cannot be empty!" << endl;
        return 1;
    }
    
    // Create LCSDP object
    LCSDP lcsDP(seq1, seq2);
    
    // Find LCS
    auto result = lcsDP.findLCS();
    int lcsLength = result.first;
    string lcs = result.second;
    
    // Display results
    cout << "\n--- Results ---" << endl;
    cout << "Length of LCS: " << lcsLength << endl;
    
    if (lcsLength > 0) {
        cout << "LCS: \"" << lcs << "\"" << endl;
    } else {
        cout << "No common subsequence found!" << endl;
    }
    
    // Print DP table for understanding
    lcsDP.printDPTable();
    
    // Print detailed analysis
    lcsDP.printAnalysis();
    
    // Additional information
    cout << "\n--- Additional Information ---" << endl;
    cout << "Time Complexity: O(m * n) where m = " << seq1.length() 
         << ", n = " << seq2.length() << endl;
    cout << "Space Complexity: O(m * n)" << endl;
    cout << "Method: Bottom-up Dynamic Programming" << endl;
    cout << "Problem Type: Longest Common Subsequence" << endl;
    
    return 0;
}
