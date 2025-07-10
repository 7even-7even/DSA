#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }

    void insert(TrieNode *root, string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isLeaf = true;
        cout << "\nSuccess!";
    }

    bool search(TrieNode *root, string word)
    {
        if (isEmpty(root))
        {
            cout << "\nTrie Empty!";
            return false;
        }
        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
            {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isLeaf;
    }

    bool isPrefix(TrieNode *root, string word)
    {
        if (isEmpty(root))
        {
            cout << "\nTrie Empty!";
            return false;
        }
        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
            {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }

    void helper(TrieNode *curr, string &word)
    {
        if (curr->isLeaf)
        {
            cout << word << "\n";
        }

        for (int i = 0; i < 26; i++)
        {
            if (curr->children[i] != nullptr)
            {
                word.push_back('a' + i);
                helper(curr->children[i], word);
                word.pop_back();
            }
        }
    }

    bool isEmpty(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                return false;
            }
        }
        return true;
    }

    void display(TrieNode *root)
    {
        if (isEmpty(root))
        {
            cout << "\nTrie Empty!";
            return;
        }
        cout << "\nThe Trie Data is as Follows:\n";
        string word = "";
        helper(root, word);
    }

    TrieNode *deleteWord(TrieNode *root, string word, int depth = 0)
    {
        if (isEmpty(root))
        {
            return nullptr;
        }

        if (depth == word.length())
        {
            if (root->isLeaf)
                root->isLeaf = false;

            if (isEmpty(root))
            {
                delete root;
                return nullptr;
            }

            return root;
        }

        int idx = word[depth] - 'a';
        if (root->children[idx] != nullptr)
        {
            root->children[idx] = deleteWord(root->children[idx], word, depth + 1);
        }

        if (!root->isLeaf && isEmpty(root))
        {
            delete root;
            return nullptr;
        }

        return root;
    }

    void freeMemory(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                freeMemory(root->children[i]);
            }
        }
        delete root;
    }
};

int main()
{
    TrieNode trie;
    TrieNode *root = new TrieNode();
    int ch = -1;
    string word;

    while (ch != 6)
    {
        cout << "\n\n1. Insert Word\n2. Search Word\n3. Check Prefix\n4. Display All Words\n5. Delete Word\n6. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
            cout << "\nEnter the Word to be Inserted: ";
            getline(cin, word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word.empty())
            {
                cout << "\nEmpty Input Not Allowed!";
                break;
            }

            trie.insert(root, word);
            break;

        case 2:
            cout << "\nEnter the Word to be Searched: ";
            getline(cin, word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word.empty())
            {
                cout << "\nEmpty Input Not Allowed!";
                break;
            }

            if (trie.search(root, word))
                cout << "\nFound";
            else
                cout << "\nWord Does Not Exist!";
            break;

        case 3:
            cout << "\nEnter the Prefix to be Checked: ";
            getline(cin, word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word.empty())
            {
                cout << "\nEmpty Input Not Allowed!";
                break;
            }

            if (trie.isPrefix(root, word))
                cout << "\nFound";
            else
                cout << "\nNot Found!";
            break;

        case 4:
            trie.display(root);
            break;

        case 5:
            cout << "\nEnter the Word to be Deleted: ";
            getline(cin, word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word.empty())
            {
                cout << "\nEmpty Input Not Allowed!";
                break;
            }

            if (trie.search(root, word))
            {
                root = trie.deleteWord(root, word);
                cout << "\nDelete Success!";
            }
            else
            {
                cout << "\nWord Does Not Exist!";
            }
            break;

        case 6:
            trie.freeMemory(root);
            cout << "\nExited Successfully!";
            break;

        default:
            cout << "\nInvalid Option!";
            break;
        }
    }

    return 0;
}
