#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};

class Tree
{
    Node *root;

private:
    Node *finder(Node *node, int val)
    {
        if (!node)
        {
            return nullptr;
        }

        if (node->data == val)
        {
            return node;
        }

        for (Node *child : node->children)
        {
            Node *found = finder(child, val);
            if (found)
            {
                return found;
            }
        }
        return nullptr;
    }

    void deleteSubTree(Node *node)
    {
        for (Node *child : node->children)
        {
            deleteSubTree(child);
        }
        delete node;
    }

    bool deleter(Node *parent, int val)
    {
        for (int i = 0; i < parent->children.size(); i++)
        {
            if (parent->children[i]->data == val)
            {
                deleteSubTree(parent->children[i]);
                parent->children.erase(parent->children.begin() + i);
                return true;
            }
            if (deleter(parent->children[i], val))
            {
                return true;
            }
        }
        return false;
    }

public:
    Tree()
    {
        root = nullptr;
    }

    void insertNode(int val)
    {
        if (!root)
        {
            root = new Node(val);
            cout << "\nInserted at Root!";
            return;
        }

        int parentVal;
        cout << "\nEnter the Parent Node Value Under which you want to insert : ";
        cin >> parentVal;

        Node *parent = finder(root, parentVal);

        if (parent)
        {
            Node *newNode = new Node(val);
            parent->children.push_back(newNode);
            cout << "\nSucces!";
        }
        else
        {
            cout << "\nParent Does Not Exit";
            return;
        }
    }

    void deleteNode(int val)
    {
        if (!root)
        {
            cout << "\nTree Empty!";
            return;
        }

        if (root->data == val)
        {
            delete root;
            root = nullptr;
            cout << "\nThe Value Was Root!";
            cout << "\nDelete Succes!";
            return;
        }

        if (deleter(root, val))
        {
            cout << "\nSuccess!";
            return;
        }
        else
        {
            cout << "\nNode Does Not Exist!";
            return;
        }
    }

    void findNode(int key)
    {
        Node *res = finder(root, key);
        if (res)
            cout << "Node " << key << " found." << endl;
        else
            cout << "Node " << key << " not found." << endl;
    }

    void displayTree()
    {
        if (!root)
        {
            cout << "Tree is empty!" << endl;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " -> ";
            for (Node *child : curr->children)
            {
                cout << child->data << " ";
                q.push(child);
            }
            cout << endl;
        }
    }
};

int main()
{
    int ch;
    Tree t;

    while (ch != 5)
    {
        cout << "\nEnter Your Choice: ";
        cout << "\n1.Insert  2.Delete  3.Search  4.Display  5.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "\nEnter the value to be inserted : ";
            cin >> val;
            t.insertNode(val);
            break;
        }

        case 2:
        {
            int val;
            cout << "\nEnter the value to be deleted : ";
            cin >> val;
            t.deleteNode(val);
            break;
        }

        case 3:
        {
            int key;
            cout << "\nEnter the value to be found : ";
            cin >> key;
            t.findNode(key);
            break;
        }

        case 4:
            t.displayTree();
            break;

        case 5:
            cout << "\nExited!";
            break;

        default:
            cout << "\nInvalid Input!";
            break;
        }
    }
    return 0;
}