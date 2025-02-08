#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
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

Node *buildTree(Node *&root)
{
    int d;
    cout << "Enter the value of node : ";
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    root = new Node(d);

    // Create further tree
    cout << "Enter the value of left node of " << d << " :" << endl;
    root->left = buildTree(root->left);
    cout << "Enter the value of right node of " << d << " :" << endl;
    root->right = buildTree(root->right);

    return root;
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

void preOrder(Node *root)
{
    // base condition
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    // base condition
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

vector<int> inorderTraversal(Node *root)
{
    vector<int> inOrder;
    stack<Node *> st;

    if (!root)
        return inOrder;

    while (true)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            Node *temp = st.top();
            st.pop();
            inOrder.push_back(temp->data);
            if (temp->right)
            {
                root = temp->right;
            }
        }
    }
    return inOrder;
}

vector<int> preorderTraversal(Node *root)
{

    vector<int> preOrder;
    stack<Node *> st;

    if (!root)
        return preOrder;

    while (true)
    {
        if (root != NULL)
        {
            preOrder.push_back(root->data);
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            Node *temp = st.top();
            st.pop();
            if (temp->right)
            {
                root = temp->right;
            }
        }
    }

    return preOrder;
}

vector<int> postorderTraversal(Node *root)
{
    if (!root)
        return {};

    stack<Node *> st;
    vector<int> postOrder;

    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        postOrder.push_back(temp->data);

        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }

    reverse(postOrder.begin(), postOrder.end());
    return postOrder;
}

void buildFromlevelOrderTraversal(Node *&root)
{

    int d;
    cout << "Enter the value for root node : ";
    cin >> d;

    root = new Node(d);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter value for left node of " << temp->data << " :";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter value for right node of " << temp->data << " :";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    // root = buildTree(root);

    buildFromlevelOrderTraversal(root);

    cout << "Level order traversal of binary tree is: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    // cout << "Inorder traversal of binary tree is: " << endl;
    // inOrder(root);
    // cout << endl;

    // cout << "Preorder traversal of binary tree is: " << endl;
    // preOrder(root);
    // cout << endl;

    // cout << "Postorder traversal of binary tree is: " << endl;
    // postOrder(root);

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1