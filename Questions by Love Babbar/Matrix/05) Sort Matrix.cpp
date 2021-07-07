#include <iostream>
#include <vector>
#include <utility>
using namespace std;


// Implemented using heap sort
class Maxheap_2d {
    vector<vector<int>>& hvec;
    int r;
    int c;
public:
    int heap_size;

    Maxheap_2d (vector<vector<int>>&);
    void Maxheapify_2d(int);

    int Left(int i)     {return 2*i + 1;}
    int Right(int i)    {return 2*i + 2;}

    int& Val(int i) {return hvec[i / r][i % c];}
};

Maxheap_2d::Maxheap_2d(vector<vector<int>>& A) : hvec(A)
{
    r = (int) hvec.size();
    c = (int) hvec[0].size();

    heap_size = r * c;

    for (int i = heap_size/2 - 1; i >= 0; i--)
        Maxheapify_2d(i);
}
void Maxheap_2d::Maxheapify_2d(int i) {
    int l = Left(i);
    int r = Right(i);

    int largest = i;
    if (l < heap_size and Val(l) > Val(i))
        largest = l;

    if (r < heap_size and Val(r) > Val(largest))
        largest = r;

    if (largest != i) {
        swap(Val(i), Val(largest));
        Maxheapify_2d(largest);
    }
}

// Heap sort
void Heapsort_2d (vector<vector<int>>& v) {
    Maxheap_2d hh(v);

    for (int i = hh.heap_size - 1; i >= 1; i--) {
        swap(hh.Val(i), hh.Val(0));
        hh.heap_size--;
        hh.Maxheapify_2d(0);
    }
}





// Implemented using merge sort
class Merge_2d {
    vector<vector<int>>& mvec;
    int roww;
    int col;
public:
    Merge_2d(vector<vector<int>>& A) : mvec(A)
    {
        roww = (int) mvec.size();
        col = (int) mvec[0].size();
    }

    void mergesort_2d(int l, int r);
    void merge_2d(int p, int q, int r);

    int& Val(int i) {return mvec[i / roww][i % col];}

};

// Merge Sort
void Merge_2d::mergesort_2d(int l, int r) {
    if (l < r) {
        int m = (l + r)/ 2;
        mergesort_2d(l, m);
        mergesort_2d(m + 1, r);
        merge_2d(l, m, r);
    }
}

void Merge_2d::merge_2d(int p, int q, int r) {
    int n = q - p + 1;
    int m = r - q;


    int* L = new int [n];
    int* R = new int [m];

    for (int i = 0; i < n; i++)
        L[i] = Val(p + i);

    for (int i = 0; i < m; i++)
        R[i] = Val(q + 1 + i);

    int i = 0, j = 0, k = p;

    while (i < n and j < m) {
        if (L[i] < R[j])
            Val(k++) = L[i++];
        else
            Val(k++) = R[j++];
    }

    while (i < n)
        Val(k++) = L[i++];
    while (j < m)
        Val(k++) = R[j++];
}





class Solution {
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // Heapsort_2d(Mat);

        Merge_2d name(Mat);
        name.mergesort_2d(0, N*N - 1);


        return Mat;
    }
};


// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
//Driver code Ends
