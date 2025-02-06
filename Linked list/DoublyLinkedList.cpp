#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
    ~Node()
    {
        cout << "Node with data " << data << " deleted" << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int i = 1;
    Node *temp = head;
    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (temp->next == NULL)
    {
        insertAtEnd(head, tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterVal(Node *&head, int data, int val)
{
    Node *temp = head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void traverse(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    temp->next = NULL;
    delete temp;
}

void deleteAtEnd(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void deleteAtPos(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    int i = 1;
    Node *temp = head;
    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }
    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    if (deleteNode->next != NULL)
    {
        deleteNode->next->prev = temp;
    }
    else
    {
        tail = temp;
    }
    deleteNode->prev = NULL;
    deleteNode->next = NULL;
    delete deleteNode;
}

void deleteByVal(Node *&head, Node *&tail, int val)
{
    if (head == NULL) 
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *curr = head;
    while (curr != NULL && curr->data != val)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << "Value not found in the list" << endl;
        return;
    }

    if (curr == head)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else if (curr == tail)
    { 
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}
int main()
{
    // Node *node1 = new Node(5);

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtEnd(head, tail, 20);
    traverse(head);

    insertAtPos(head, tail, 11, 2);
    traverse(head);
    insertAfterVal(head, 12, 10);
    traverse(head);

    // deleteAtHead(head);
    // traverse(head);

    // deleteAtEnd(head, tail);
    // traverse(head);

    // deleteAtPos(head, tail, 2);
    // traverse(head);

    deleteByVal(head, tail, 10);
    traverse(head);
    deleteByVal(head, tail, 2);
    traverse(head);

    return 0;
}