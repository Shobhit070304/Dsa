#include <iostream>
#include <stack>

#define SIZE 5

using namespace std;

class Stack
{
    // int *arr;
    // int size;
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        // size = s;
        // arr = new int[s];
        top = -1;
    }

    void push(int x)
    {
        if (SIZE - top > 1)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            return;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            return;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    int stack_size()
    {
        return top + 1;
    }

    bool isFull()
    {
        if (SIZE - top == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // stack<int> st;
    // st.push(5);
    // st.pop();
    // cout << st.top() << endl;
    // cout << st.size() << endl;
    // cout << st.empty() << endl;

    Stack s;

    s.push(7);
    s.push(8);
    s.push(7);
    s.push(8);
    s.push(7);
    s.push(777);
    s.push(888);
    cout << s.stack_size() << endl;
    cout << s.isEmpty() << endl;
    // s.pop();
    cout << s.peek() << endl;
    cout << s.isFull() << endl;

    return 0;
}