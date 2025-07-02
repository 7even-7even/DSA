#include <bits/stdc++.h>
using namespace std;

class HashTable {
    int* table;
    int size;

public:
    HashTable(int cap) {
        size = cap;
        table = new int[size];
        fill(table, table + size, -1);
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < size) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == -1) {
                table[newIndex] = key;
                return;
            }
            i++;
        }

        cout << "Hash Table Full!\n";
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << (table[i] == -1 ? "EMPTY" : to_string(table[i])) << endl;
        }
    }
};

int main() {
    int size, choice, key;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    while (true) {
        cout << "\nMENU:\n1. Insert\n2. Display\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            ht.display();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
