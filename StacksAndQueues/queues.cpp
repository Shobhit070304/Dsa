#include <iostream>
#include <queue>

#define size 5

using namespace std;

// class Queue
// {

//     // int *arr;
//     // int size;
//     int arr[size];
//     int front;
//     int rear;

// public:
//     Queue()
//     {
//         // size = d;
//         // arr = new int[size];
//         front = -1;
//         rear = -1;
//     }

//     void enqueue(int d)
//     {
//         if (rear == size - 1)
//         {
//             cout << "Queue is full" << endl;
//             return;
//         }
//         if (front == -1)
//             front = 0;
//         rear++;
//         arr[rear] = d;
//     }

//     void dequeue()
//     {
//         if (front == -1 || front > rear)
//         {
//             cout << "Queue is empty" << endl;
//             return;
//         }
//         front++;
//         if (front > rear)
//         {
//             front = -1;
//             rear = -1;
//         }
//     }

//     int get_front()
//     {
//         if (front == -1 || front == size)
//         {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         return arr[front];
//     }

//     bool isEmpty()
//     {
//         if (front == -1 || front > rear)
//         {
//             return true;
//         }
//         return false;
//     }

//     int get_size()
//     {
//         if (front == -1)
//             return 0;
//         return rear - front + 1;
//     }
//     ~Queue()
//     {
//         delete[] arr;
//     }
// };

class Deque
{
    // int *arr;
    // int size;
    int arr[size];
    int front;
    int rear;

public:
    Deque()
    {
        // size = d;
        // arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_front(int d)
    {
        if (front == 0)
        {
            cout << "Deque is full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front--;
        }
        arr[front] = d;
    }
    void push_back(int d)
    {
        if (isFull())
        {
            cout << "Deque is full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = d;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {

            front++;
        }
    }
    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear--;
        }
    }

    int get_front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    int get_rear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    int getSize()
    {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }

    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return rear == size - 1;
    }

    // ~Deque(){
    //     delete[] arr;
    // }
};
int main()
{
    // queue<int> q;
    // q.push(55);
    // q.pop();
    // cout << q.size() << endl;
    // cout << q.front() << endl;
    // cout << q.empty() << endl;

    // Queue q;
    // q.enqueue(55);
    // q.enqueue(66);

    // cout << q.get_size() << endl;
    // cout << q.get_front() << endl;
    // cout << q.isEmpty() << endl;

    // q.dequeue();
    // cout << q.get_size() << endl;
    // cout << q.get_front() << endl;
    // cout << q.isEmpty() << endl;

    // deque<int> q;

    // q.push_front(1);
    // q.pop_front();
    // q.push_back(3);
    // q.pop_back();
    // cout << q.front() << endl;
    // cout << q.back() << endl;
    // cout << q.size() << endl;
    // cout << q.empty() << endl;

    Deque d;

    d.push_back(1);
    d.push_back(2);
    cout << d.get_front() << endl;
    cout << d.get_rear() << endl;
    cout << d.getSize() << endl;
    cout << d.isEmpty() << endl;
    d.pop_front();
    d.push_front(11);
    d.push_back(13);
    cout << d.get_front() << endl;
    cout << d.get_rear() << endl;
    cout << d.getSize() << endl;
    cout << d.isEmpty() << endl;

    d.push_back(16);
    d.push_back(17);
    cout << d.getSize() << endl;
    d.push_back(22);
    cout << d.getSize() << endl;

    return 0;
}