#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *createBST(Node *root, int d)
{
    if (root == NULL)
    {
        Node *root = new Node(d);
        return root;
    }
    else
    {
        if (root->data < d)
        {
            root->right = createBST(root->right, d);
        }
        else
        {
            root->left = createBST(root->left, d);
        }
    }
}

void takeInput(Node *&root)
{
    int d;
    cout << "Enter data to create BST : ";
    cin >> d;

    while (d != -1)
    {
        root = createBST(root, d);
        cin >> d;
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inOrder(Node *root)
{
    // base condition
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int getMini(Node *root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL)
        return root->data;
    return getMini(root->left);
}

int getMaxi(Node *root)
{
    if (root == NULL)
        return -1;
    if (root->right == NULL)
        return root->data;
    return getMaxi(root->right);
}

Node *deleteInBST(Node *&root, int d)
{
    if (root == NULL)
        return NULL;

    if (root->data == d)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = getMini(root->right);
            root->data = mini;
            root->right = deleteInBST(root->right, mini);
            return root;
        }
    }

    if (root->data < d)
    {
        root->right = deleteInBST(root->right, d);
        return root;
    }
    else
    {
        root->left = deleteInBST(root->left, d);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    takeInput(root);

    cout << endl;
    cout << "Level order traversal of binary tree is: " << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << "Inorder traversal of binary tree is: " << endl;
    inOrder(root);

    cout << endl;
    cout << "Minimum value in the binary tree is: " << getMini(root) << endl;
    cout << "Maximum value in the binary tree is: " << getMaxi(root) << endl;

    cout << "Deletion" << endl;

    int d;
    cout << "Enter the value to delete in BST : ";
    cin >> d;
    root = deleteInBST(root, d);

    cout << "Level order traversal of binary tree after deletion is: " << endl;
    levelOrderTraversal(root);
    cout << "Inorder traversal of binary tree after deletion is: " << endl;
    inOrder(root);

    cout << endl;
    cout << "Minimum value in the binary tree is: " << getMini(root) << endl;
    cout << "Maximum value in the binary tree is: " << getMaxi(root) << endl;

    return 0;
}

// 50 20 10 30 70 90 110 -1