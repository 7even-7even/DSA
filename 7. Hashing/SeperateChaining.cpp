#include <bits/stdc++.h>
using namespace std;

class HashTable {
    int BUCKET;
    list<int>* table;

public:
    HashTable(int size) {
        BUCKET = size;
        table = new list<int>[BUCKET];
    }

    int hashFunction(int key) {
        return key % BUCKET;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void display() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i << " --> ";
            for (int x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    int size, choice, key;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    while (true) {
        cout << "\nMENU:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
            break;
        case 3:
            ht.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
