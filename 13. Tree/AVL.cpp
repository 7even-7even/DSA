#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

int height(Node *node) {
    return node ? node->height : 0;
}

int getBalance(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *leftRotate(Node *y) {
    Node *x = y->right;
    Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *insert(Node *root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && val < root->left->data)
        return rightRotate(root);

    if (balance < -1 && val > root->right->data)
        return leftRotate(root);

    if (balance > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *minValueNode(Node *node) {
    Node *curr = node;
    while (curr->left)
        curr = curr->left;
    return curr;
}

Node *deleteNode(Node *root, int val) {
    if (!root)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void levelOrder(Node *root) {
    if (!root) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node *temp = q.front(); q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

bool search(Node *root, int val) {
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return search(root->left, val);
    return search(root->right, val);
}

void printGraphical(Node *root, int space = 0, int gap = 10) {
    if (!root)
        return;
    space += gap;
    printGraphical(root->right, space);
    cout << endl;
    for (int i = gap; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    printGraphical(root->left, space);
}

int getTreeHeight(Node *root) {
    return height(root);
}

int main() {
    int ch = -1, val;
    Node *root = nullptr;

    while (ch != 8) {
        cout << "\n1. Insert\n2. Delete\n3. Inorder\n4. Level Order\n5. Search\n6. Height\n7. Graphical Print\n8. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Level Order Traversal:\n";
                levelOrder(root);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (search(root, val) ? "Found\n" : "Not Found\n");
                break;
            case 6:
                cout << "Tree Height: " << getTreeHeight(root) << endl;
                break;
            case 7:
                cout << "Tree Structure:\n";
                printGraphical(root);
                break;
            case 8:
                cout << "Exit...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    }

    return 0;
}
