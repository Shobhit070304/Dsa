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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
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
    temp->next = newNode;
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
    temp->next = newNode;
}

void traverse(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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
    temp->next = NULL;
    delete temp;
}

void deleteAtEnd(Node *&head)
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
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *next = temp->next;
    temp->next = NULL;
    delete next;
}

void deleteAtPos(Node *&head, int pos)
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
    if (temp == NULL){
        cout << "Invalid position" << endl;
        return;
    }  
    Node *next = temp->next;
    temp->next = temp->next->next;
    delete next;
}

void deleteByVal(Node *&head, int val)
{
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node*prev = NULL;
    Node *curr = head;
    while (curr != NULL && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Value not found in the list" << endl;
        return;
    }
    prev -> next = curr -> next;
    delete curr;
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
    Node *node1 = new Node(5);

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, tail, 77);
    insertAtEnd(head, tail, 103);
    insertAtPos(head, tail, 117, 4);
    insertAfterVal(head, 129, 103);
    traverse(head);

    // deleteAtHead(head);
    // cout<<endl;
    // traverse(head);

    // deleteAtEnd(head);
    // cout << endl;
    // traverse(head);

    // deleteAtPos(head, 7);
    // cout << endl;
    // traverse(head);

    // deleteByVal(head, 11);
    // cout << endl;
    // traverse(head);

    // if (isCircular(head))
    // {
    //     cout << "Circular Linked List" << endl;
    // }
    // else
    // {
    //     cout << "Non-Circular Linked List" << endl;
    // }

    return 0;
}