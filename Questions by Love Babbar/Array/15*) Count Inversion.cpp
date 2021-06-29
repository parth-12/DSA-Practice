// Given an array of integers. Find the Inversion Count in the array.
//
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
// If array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.




#include <iostream>
using namespace std;

int inv_merge_sort(int [], int, int);
int inv_merge(int [], int, int, int);

//Driver code
int main() {
    int n = 4, arr[] = {8, 4, 2, 1};

    cout << inv_merge_sort(arr, 0, n - 1) << endl;
    return 0;
}
// Driver code Ends



int inv_merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        int inv = 0;
        inv += inv_merge_sort(A, p, q);
        inv += inv_merge_sort(A, q + 1, r);

        inv += inv_merge(A, p, q, r);
        return inv;
    }
    return 0;
}

int inv_merge(int A[], int p, int q, int r) {
    int n = q - p + 1;
    int m = r - q;

    int* L = new int [n];
    int* R = new int [m];

    for (int i = 0; i < n; i++)
        L[i] = A[p + i];
    for (int i = 0; i < m; i++)
        R[i] = A[q + 1 + i];

    int i = 0, j = 0, k = p;
    int inv = 0;

    while (i < n and j < m) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else {
            A[k++] = R[j++];
            inv += n - i;
        }
    }

    while (i < n)
        A[k++] = L[i++];

    while (j < m)
        A[k++] = R[j++];

    return inv;
}
