#include <iostream>

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
};

int main()
{

    Heap h;
    h.insertIntoHeap(60);
    h.insertIntoHeap(30);
    h.insertIntoHeap(40);
    h.insertIntoHeap(50);
    h.insertIntoHeap(20);

    cout << "Heap: ";
    for (int i = 1; i <= 5; i++)
    {
        cout << h.arr[i] << " ";
    }

    h.insertIntoHeap(70);
    cout << "\nHeap after adding 70: ";
    for (int i = 1; i <= 6; i++)
    {
        cout << h.arr[i] << " ";
    }

    return 0;
}