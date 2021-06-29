// Given two sorted arrays arr1[] of size N and arr2[] of size M.
// Each array is sorted in non-decreasing order.
// Merge the two arrays into one sorted array in non-decreasing order without using any extra space.



#include <iostream>
using namespace std;

// O(nlog(n) + mlog(m))
void merge(int [], int [], int, int);
// O(n + m)
void encode_merge(int [], int [], int, int);

void printarray(int [], int );
int main() {
    int n = 4, a[] = {1, 3, 5, 7};
    int m = 5, b[] = {4, 4,  6, 8, 9};

    // merge(a, b, n, m);
    encode_merge(a, b, n, m);

    cout << "a: ";
    printarray(a, n);

    cout << "b: ";
    printarray(b, m);

    return 0;
}

void merge(int arr1[], int arr2[], int n, int m) {

    int pt1 = n - 1, pt2 = 0;
    while (pt2 < m && pt1 >= 0)
        if (arr1[pt1] > arr2[pt2])
            swap(arr1[pt1--],arr2[pt2++]);
        else {
            cout << "hi" << endl;
            break;
        }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);


}

void encode_merge(int arr1[], int arr2[], int n, int m) {

    int mx = max(arr1[n - 1], arr2[m - 1]);

    mx++;

    int i = 0, j = 0, k = 0;

    int num;
    while (i < n and j < m) {
        if (arr1[i] % mx < arr2[j] % mx)
            num = arr1[i++] % mx;
        else
            num = arr2[j++] % mx;

        k < n ? arr1[k++] += num * mx : arr2[(k++) - n] += num * mx;
    }

    while (i < n) {
        num = arr1[i++] % mx;
        k < n ? arr1[k++] += num * mx : arr2[(k++) - n] += num * mx;
    }
    while (j < m) {
        num = arr2[j++] % mx;
        k < n ? arr1[k++] += num * mx : arr2[(k++) - n] += num * mx;
    }


    for (int i = 0; i < n; i++)
        arr1[i] /= mx;
    for (int i = 0; i < m; i++)
        arr2[i] /= mx;


}

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
