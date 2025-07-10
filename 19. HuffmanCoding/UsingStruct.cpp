#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iomanip> // For pretty formatting

using namespace std;

// Node for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority_queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Recursive function to print the tree in-order
void displayTree(Node* root, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    displayTree(root->left, huffmanCodes);

    if (!root->left && !root->right) {
        cout << "Character: '" << root->ch << "' | Frequency: " << root->freq 
             << " | Huffman Code: " << huffmanCodes[root->ch] << endl;
    }

    displayTree(root->right, huffmanCodes);
}

int main() {
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    // Step 1: Count frequency of each character
    unordered_map<char, int> frequency;
    for (char ch : text) {
        if (ch != ' ') // Skipping space, you can keep it if needed
            frequency[ch]++;
    }

    cout << "\nFrequencies:\n";
    for (auto pair : frequency) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }

    // Step 2: Build priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 3: Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    // Step 4: Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Step 5: Display the Tree Info
    cout << "\n🎄 Huffman Tree Character Details:\n";
    displayTree(root, huffmanCodes);

    // Step 6: Encode input string
    string encodedStr = "";
    for (char ch : text) {
        if (ch != ' ') 
            encodedStr += huffmanCodes[ch];
    }

    cout << "\n🧠 Encoded Huffman String: " << encodedStr << endl;

    return 0;
}
