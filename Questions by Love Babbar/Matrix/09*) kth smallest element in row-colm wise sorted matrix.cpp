// Given an n x n matrix, where every row and column is sorted in non-decreasing order.
// Find the kth smallest element in the given 2D array.



// Below Solution 1 also works for finding the kth smallest element in n sorrted arrays


#include <iostream>
#include <vector>
#include <utility>
using namespace std;



struct MinheapNode {
    int element;
    int i;
    int j;
};

// Minheap to merge k sorted arrays or
// find kth smallest element in row and wise sorted matrix
class Minheap {
    vector<vector<int>>& vec;
    MinheapNode* harr;
    int heap_size;


    int Left(int i)     { return 2*i + 1;}
    int Right(int i)    { return 2*i + 2;}

    // Used in insert key
    int Parent(int i)   { return i - 1/2;}

    int Val(int i) { return harr[i].element;}

    void MinHeapify (int i) {
        int l = Left(i);
        int r = Right(i);

        int smallest = i;
        if (l < heap_size and Val(l) < Val(i))
            smallest = l;
        if (r < heap_size and Val(r) < Val(smallest))
            smallest = r;

        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    MinheapNode Extract_Min() {

        MinheapNode min = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return min;
    }

    void Insert_Key(MinheapNode n) {
        heap_size++;
        int i = heap_size - 1;
        harr[i] = n;

        while (i > 0 and Val(i) < Val(Parent(i))) {
            swap(harr[i], harr[Parent(i)]);
            i = Parent(i);
        }
    }
public:
    Minheap(vector<vector<int>>& a) : vec(a)
    {
        heap_size = (int) vec.size();
        harr = new MinheapNode [heap_size];

        int ind = 0;
        for (int i = 0; i < heap_size; i++) {
            if (!vec[i].empty()) {
                MinheapNode a;
                a.element = vec[i][0];
                a.i = i;
                a.j = 0;

                harr[ind++] = a;
            }
            else
                heap_size--;
        }

        for (int i = heap_size / 2 - 1; i >= 0; i--)
            MinHeapify(i);

    }

    // kth smallest element
    int kth_smallest (int k) {

        for (int i = 0; i < k - 1; i++) {
            MinheapNode s = Extract_Min();

            if (s.j + 1 < vec[s.i].size()) {
                s.element = vec[s.i][s.j + 1];
                s.j++;

                Insert_Key(s);
            }
        }

        return Extract_Min().element;
    }
};





// Using Minheap
// Time complexity O(k * log(r))
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        Minheap cc(matrix);

        return cc.kth_smallest(k);
    }
};


// Binary Search in number line
// Time complexity O(32 * r * log(c))
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];


        while (lo < hi) {
            int mid = (lo + hi)/2;
            int place = 0;

            for (int i = 0; i < n; i++)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (place < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
