// Given an array of positive integers. We need to make the given array a ‘Palindrome’.
// The only allowed operation is”merging” (of two adjacent elements).
// Merging two adjacent elements means replacing them with their sum.
// The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.


#include <iostream>
using namespace std;

// recursive code
int findMinOps(int arr[], int n) {
    if (n == 0 or n == 1)
        return 0;

    if (arr[0] == arr[n - 1])
        return findMinOps(arr + 1, n - 2);

    else if (arr[0] > arr[n - 1]) {
        arr[n - 2] += arr[n - 1];
        return 1 + findMinOps(arr, n - 1);
    }
    else {
        arr[1] += arr[0];
        return 1 + findMinOps(arr + 1, n - 2);
    }
}


// using while loop
int findMinOps2(int arr[], int n) {
    int ans = 0;

    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] == arr[j]) {
            i++; j--;
        }
        else if (arr[i] > arr[j]) {
            arr[j - 1] += arr[j];
            j--; ans++;
        }
        else {
            arr[i + 1] += arr[i];
            i++; ans++;
        }
    }
    return ans;
}
