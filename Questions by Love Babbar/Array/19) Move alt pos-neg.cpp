// Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance.
//
// Number of positive and negative numbers need not be equal.
// If there are more positive numbers they appear at the end of the array.
// If there are more negative numbers, they too appear in the end of the array.


#include <iostream>
using namespace std;

void move_alt(int [], int);

void printarray(int [], int );

int main() {
    int n = 8, arr[] = {1, -1, 3, 2, -7, -5, 11, 6};

    move_alt(arr, n);
    printarray(arr, n);

    return 0;
}

void move_alt(int A[], int n) {
    int neg = 0, pos = n - 1;

    while (neg <= pos)
        if (A[neg] < 0)
            neg++;
        else
            swap(A[neg], A[pos--]);


    pos++;
    int i = 1;
    while (pos < n and i < pos) {
        swap(A[i++], A[pos++]);
        i++;
    }
}

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
