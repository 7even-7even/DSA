#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestKDistinct(string s, int k) {
    int n = s.length(), maxLen = 0;
    unordered_map<char, int> freq;
    int left = 0;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << "Longest substring with " << k << " distinct characters: " << longestKDistinct(s, k) << endl;
    return 0;
}
