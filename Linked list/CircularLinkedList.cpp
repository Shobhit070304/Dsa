#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    ~Node()
    {
        cout << "Node with data " << data << " deleted" << endl;
    }
};

void insertNode(Node *&tail, int data, int element)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        Node *temp = tail;
        bool found = false;
        do
        {
            if (temp->data == element)
            {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != tail);
        if (found == true)
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Element not found in the list" << endl;
            return;
        }
    }
}

void traverse(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != tail);
    cout << endl;
}

void deleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = tail->next;

        bool found = false;

        do
        {
            if (curr->data == val)
            {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        if (found == false)
        {
            cout << "Element not found in the list" << endl;
            return;
        }

        // 1 Node list
        if (prev == curr)
        {
            tail = NULL;
            delete curr;
            return;
        }
        //>=2 Node list
        if (curr == tail)
        {
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
}

bool isCircular(Node *&tail)
{
    if (tail == NULL)
    {
        return false;
    }

    Node *curr = tail->next;

    while (curr != NULL && curr != tail)
    {
        curr = curr->next;
    }

    return (curr == tail);
}

int main()
{
    // Node *node1 = new Node(5);
    Node *tail = NULL;
    insertNode(tail, 5, 10);
    traverse(tail);
    insertNode(tail, 10, 5);
    traverse(tail);
    insertNode(tail, 12, 10);
    traverse(tail);
    insertNode(tail, 15, 10);
    traverse(tail);

    deleteNode(tail, 10);
    traverse(tail);
    deleteNode(tail, 13);
    traverse(tail);

    if (isCircular(tail))
    {
        cout << "Circular Linked List" << endl;
    }
    else
    {
        cout << "Non-Circular Linked List" << endl;
    }

    return 0;
}