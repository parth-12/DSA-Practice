// Given two sorted arrays, a[] and b[],
// the task is to find the median of these sorted arrays, in O(log n + log m) time complexity,
// when n is the number of elements in the first array, and m is the number of elements in the second array.


#include <iostream>
using namespace std;

// non-recursive code
double findmedian(int B[], int m, int A[], int n) {
    if (m > n)
        return findmedian(A, n, B, m);

    int p_size = (n + m + 1) / 2;

    int start = 0;
    int end = m;

    while (start <= end) {
        int p_x = (start + end)/2;
        int p_y = p_size - p_x;

        int tl = p_x == 0 ? INT32_MIN : B[p_x - 1];
        int tr = p_x == m ? INT32_MAX : B[p_x];

        int bl = p_y == 0 ? INT32_MIN : A[p_y - 1];
        int br = p_y == n ? INT32_MAX : A[p_y];

        if (tl <= br and bl <= tr) {
            if ((n + m) & 1)
                return max(tl, bl);
            else
                return (max(tl, bl) + min(tr, br)) / 2.0;
        }
        else if (tl > br)
            end = p_x - 1;
        else
            start = p_x + 1;
    }
    return -1;
}

//using recursion
double findmedian_rec(int B[], int m, int A[], int n) {
    if (m > n)
        return findmedian_rec(A, n, B, m);

    if (m == 0) {
        if (n == 0)
            return -1;

        if (n & 1)
            return A[n/2];
        else
            return (A[n/2 - 1] + A[n/2]) / 2.0;
    }

    else if (m == 1) {

    }

    else if (m == 2) {

    }

    int ind_s = (m - 1)/2;
    int ind_b = (n - 1)/2;

    if (B[ind_s] == A[ind_b]) {
        if (m & 1 and n & 1)
            return (B[m/2] + A[n/2]) / 2.0;

        else if (m & 1 or n & 1)
            return m & 1 ? B[m/2] : A[m/2];

        else
            return ( B[m/2] + min(B[m/2 + 1], A[n/2] + 1) ) / 2.0;
    }

    else if (B[ind_s] < A[ind_b])
        return findmedian_rec(A + ind_s, n/2 + 1, B, n - ind_s);

    return findmedian_rec(A, n/2 + 1, B + ind_s, n - ind_s );
}

int main()
{
    int A[] = {900};
    int B[] = {5, 8, 10, 20};

    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    cout << findmedian( A, N, B, M ) << endl;

    return 0;
}
