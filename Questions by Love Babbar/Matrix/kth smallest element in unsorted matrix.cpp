#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Minheap_2d {
    vector<vector<int>>& hvec;
    int r;
    int c;
public:
    int heap_size;

    Minheap_2d (vector<vector<int>>&);
    void Minheapify_2d(int);

    int Left(int i)     {return 2*i + 1;}
    int Right(int i)    {return 2*i + 2;}

    int Parent(int i)   { return i - 1 / 2; }

    int& Val(int i) {return hvec[i / r][i % c];}

    int extractMin_2d();
};

Minheap_2d::Minheap_2d(vector<vector<int>>& A) : hvec(A)
{
    r = (int) hvec.size();
    c = (int) hvec[0].size();

    heap_size = r * c;

    for (int i = heap_size/2 - 1; i >= 0; i--)
        Minheapify_2d(i);
}
void Minheap_2d::Minheapify_2d(int i) {
    int l = Left(i);
    int r = Right(i);

    int smallest = i;
    if (l < heap_size and Val(l) < Val(i))
        smallest = l;

    if (r < heap_size and Val(r) < Val(smallest))
        smallest = r;

    if (smallest != i) {
        swap(Val(i), Val(smallest));
        Minheapify_2d(smallest);
    }
}
int Minheap_2d::extractMin_2d() {
    int min = Val(0);

    Val(0) = Val(heap_size - 1);
    heap_size--;
    Minheapify_2d(0);

    return min;
}



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        Minheap_2d hh(matrix);

        for (int i = 0; i < k - 1; i++)
            hh.extractMin_2d();

        return hh.extractMin_2d();
    }
};
