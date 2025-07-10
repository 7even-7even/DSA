#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator struct
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Min-heap
    }
};

// DFS to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = code;
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Display tree info
void displayTree(Node* root, unordered_map<char, string>& codes, unordered_map<char, int>& freq) {
    cout << "\nCharacter | Frequency | Code\n";
    cout << "-------------------------------\n";
    for (auto& [ch, code] : codes) {
        cout << "    " << ch << "      |    " << freq[ch] << "      |   " << code << "\n";
    }
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    unordered_map<char, int> freq;
    for (char ch : text)
        if (ch != ' ') freq[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& [ch, f] : freq)
        pq.push(new Node(ch, f));

    while (pq.size() > 1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node *m = new Node('\0', l->freq + r->freq);
        m->left = l;
        m->right = r;
        pq.push(m);
    }

    Node* root = pq.top();

    unordered_map<char, string> codes;
    generateCodes(root, "", codes);
    displayTree(root, codes, freq);

    string encoded;
    for (char ch : text)
        if (ch != ' ') encoded += codes[ch];

    cout << "\nEncoded: " << encoded << "\n";
    return 0;
}
