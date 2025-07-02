#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree
{
    Node *root;

private:
    Node *finder(Node *node, int val)
    {
        if(!node){
            return nullptr;
        }

        if(node->data == val){
            return node;
        }

        Node * leftRes = finder(node->left, val);
        if(leftRes)
            return leftRes;
        
        return finder(node->right, val);
    }

    void deleteSubTree(Node* node){
        if(!node)
            return;
        
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }

    bool deleter(Node * parent, int val){
        if(!parent){
            return false;
        }

        if(parent->left && parent->left->data ==  val){
            deleteSubTree(parent->left);
            parent->left = nullptr;
            return true;
        }

        if(parent->right && parent->right->data ==  val){
            deleteSubTree(parent->right);
            parent->right = nullptr;
            return true;
        }

        return deleter(parent->left, val) || deleter(parent->right, val);
    }

public:
    BinaryTree()
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
        cout << "\nEnter the Parent Node Value: ";
        cin >> parentVal;

        Node *parent = finder(root, parentVal);
        if (!parent)
        {
            cout << "\nParent Does not Exist!";
            return;
        }

        char dir;
        cout << "\nInsert at Left or Right of: " << parentVal << "(L/R)? :";
        cin >> dir;
        if (dir == 'L' || dir == 'l')
        {
            if (!parent->left)
            {
                parent->left = new Node(val);
                cout << "\nSuccess!";
            }
            else
            {
                cout << "\nLeft Child Already Exist!";
                return;
            }
        }
        else if (dir == 'r' || dir == 'R')
        {
            if (!parent->right)
            {
                parent->right = new Node(val);
                cout << "\nSuccess!";
            }
            else
            {
                cout << "\nRight Child Already Exist!";
                return;
            }
        }
        else
        {
            cout << "\nInvalid Input!";
            return;
        }
        return;
    }

    void deleteNode(int val)
    {
        if (!root)
        {
            cout << "\nEmpty Tree!";
            return;
        }

        if(root->data ==  val){
            deleteSubTree(root);
            root = nullptr;
            cout << "\nValue Found At Root!";
            cout << "\nRoot Deleted";
            return;
        }

        if(deleter(root , val)){
            cout << "\nSuccess!";
        }
        else{
            cout << "\nNode Not Found";
        }
    }

    void findNode(int val)
    {
        Node *res = finder(root, val);
        if (res)
            cout << "Node " << val << " found." << endl;
        else
            cout << "Node " << val << " not found." << endl;
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

            if (curr->left)
            {
                cout << "L:" << curr->left->data << " ";
                q.push(curr->left);
            }

            if (curr->right)
            {
                cout << "R:" << curr->right->data << " ";
                q.push(curr->right);
            }

            cout << endl;
        }
    }
};

int main()
{
    int ch;
    BinaryTree bt;

    do
    {
        cout << "\n\nEnter Your Choice:\n";
        cout << "1.Insert  2.Delete  3.Search  4.Display  5.Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "\nEnter Value to Insert: ";
            cin >> val;
            bt.insertNode(val);
            break;
        }

        case 2:
        {
            int val;
            cout << "\nEnter Value to Delete: ";
            cin >> val;
            bt.deleteNode(val);
            break;
        }

        case 3:
        {
            int key;
            cout << "\nEnter Value to Search: ";
            cin >> key;
            bt.findNode(key);
            break;
        }

        case 4:
            bt.displayTree();
            break;

        case 5:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid Input!";
        }

    } while (ch != 5);

    return 0;
}