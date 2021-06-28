// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array.
// It is given that all array elements are distinct.


#include<iostream>
#include <utility>
using namespace std;

// Using min-heap
class Minheap {
    int* harr;
    int heap_size;
public:
    Minheap (int [], int);
    void Minheapify (int);

    int parent(int i)   { return i - 1 / 2; }
    int left(int i)     { return 2 * i + 1; }
    int right(int i)     { return 2 * i + 2; }

    int extractMin();
    int getMin()    { return harr[0];}
};

int main() {
    int arr[] = {12, 4, 13, 6, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]), k = 4;

    cout << kthSmallest(arr, n, k) << endl;
    return 0;
}


// can be also implemented using max-heap
// https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/


// using quicksort
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/


Minheap::Minheap(int a[], int size) {
    heap_size = size;
    harr = a;
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        Minheapify(i);
    }
}

void Minheap::Minheapify(int i) {
    int l = left(i);
    int r = right(i);

    int smallest;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    else smallest = i;

    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        Minheapify(smallest);
    }
}

int Minheap::extractMin() {
    if (heap_size < 1) {
        cout << "heap underflow";
        return -101;
    }

    int min = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size -= 1;
    Minheapify(0);

    return min;
}


int kthSmallest(int arr[], int n, int k) {

    Minheap name(arr, n);

    for (int i = 0; i < k - 1; i++) {
        name.extractMin();
    }
    return name.extractMin();

}
