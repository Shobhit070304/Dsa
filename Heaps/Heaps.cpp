#include <iostream>
#include<queue>

using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insertIntoHeap(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = arr[index / 2];

            if (val <= parent)
            {
                return;
            }
            else
            {
                swap(arr[index], arr[index / 2]);
                index = index / 2;
            }
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty. Cannot delete." << endl;
            return;
        }

        arr[1] = arr[size];
        arr[size] = -1;
        size--;
        int i = 1;

        while (i <= size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int largest = i;

            if (leftChild <= size && arr[leftChild] > arr[i])
            {
                largest = leftChild;
            }

            if (rightChild <= size && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }

            if (largest == i)
            {
                break;
            }
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    while (i <= n)
    {
        if (left <= n && arr[left] > arr[i])
        {
            largest = left;
        }
        if (right <= n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (i != largest)
        {
            swap(arr[i], arr[largest]);
            i = largest;
            heapify(arr, n, i);
        }
        else{
            break;
        }
    }
}

void printHeap(int arr[])
{
    for (int i = 1; i <= 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    // priority_queue<int> q;
    // q.push(7);
    // q.push(3);
    // q.pop();
    // cout<<q.top()<<endl;
    // cout<<q.size()<<endl;
    // cout<<q.empty()<<endl;

    // priority_queue<int, vector<int>, greater<int>> q;
    // q.push(7);
    // q.push(3);
    // q.pop();
    // cout<<q.top()<<endl;
    // cout<<q.size()<<endl;
    // cout<<q.empty()<<endl;
    

    // Heap h;
    // h.insertIntoHeap(60);
    // h.insertIntoHeap(30);
    // h.insertIntoHeap(40);
    // h.insertIntoHeap(50);
    // h.insertIntoHeap(20);

    // cout << "Heap: ";
    // printHeap(h.arr);

    // h.insertIntoHeap(70);
    // cout << "\nHeap after adding 70: ";
    // printHeap(h.arr);

    // h.deleteFromHeap();
    // cout << "\nHeap after deleting the largest element: ";
    // printHeap(h.arr);

    // h.deleteFromHeap();
    // cout << "\nHeap after deleting the largest element: ";
    // printHeap(h.arr);

    // heapify(h.arr, 10, 1);
    // cout << "\nHeap after heapify: ";
    // printHeap(h.arr);

    return 0;
}