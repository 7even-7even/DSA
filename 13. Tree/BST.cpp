#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
    Node *root;

private:
    Node *insert(Node *node, int val)
    {
        if (!node)
        {
            return new Node(val);
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        else
        {
            cout << "\nDuplicates Detected!";
        }

        return node;
    }

    bool search(Node *node, int val)
    {
        if (!node)
        {
            return false;
        }

        if (node->data == val)
        {
            return true;
        }

        if (val < node->data)
        {
            return search(node->left, val);
        }
        else
        {
            return search(node->right, val);
        }
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    Node *remove(Node *node, int val)
    {
        if (!node)
            return nullptr;

        if (val < node->data)
        {
            node->left = remove(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = remove(node->right, val);
        }
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = remove(node->right, minRight->data);
        }
        return node;
    }

    void freeMemory(Node *node)
    {
        if (!node)
        {
            return;
        }
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }

    void inorder(Node *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void levelOrder(Node *node)
    {
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        freeMemory(root);
    }
    void insertNode(int val)
    {
        root = insert(root, val);
        cout << "Success!";
    }

    void deleteNode(int val)
    {
        if (!search(root, val))
        {
            cout << "\nNode Not Found!";
            return;
        }
        root = remove(root, val);
        cout << "\nSuccess!";
    }

    void findNode(int val)
    {
        if (search(root, val))
        {
            cout << "\nNode Found!";
        }
        else
        {
            cout << "\nNode Not Found!";
        }
    }

    void inorderDisplay()
    {
        if (!root)
        {
            cout << "\nTree is Empty!";
            return;
        }
        cout << "\nInorder Traversal: " << endl;
        inorder(root);
    }

    void levelOrderDisplay()
    {
        if (!root)
        {
            cout << "\nTree is Empty!";
            return;
        }
        cout << "\nLevel Order Display: ";
        levelOrder(root);
    }
};

int main()
{
    BST tree;
    int ch;

    do
    {
        cout << "\n\n===== Binary Search Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Search Node";
        cout << "\n4. Display Inorder";
        cout << "\n5. Display Level Order";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "Enter Value to Insert: ";
            cin >> val;
            tree.insertNode(val);
            break;
        }
        case 2:
        {
            int val;
            cout << "Enter Value to Delete: ";
            cin >> val;
            tree.deleteNode(val);
            break;
        }
        case 3:
        {
            int val;
            cout << "Enter Value to Search: ";
            cin >> val;
            tree.findNode(val);
            break;
        }
        case 4:
            tree.inorderDisplay();
            break;
        case 5:
            tree.levelOrderDisplay();
            break;
        case 6:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid Choice!";
        }
    } while (ch != 6);

    return 0;
}
