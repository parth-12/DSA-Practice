// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once.
// After modifying, height should be a non-negative integer.
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.



#include <iostream>
using namespace std;

int min_height_diff(int [], int, int);

int main() {
    int n = 7, A[] = {16, 12, 13, 14, 11, 15, 20};
    cout << min_height_diff(A, n, 5) << endl;
    return 0;
}

int min_height_diff(int arr[], int n, int k) {
    sort(arr, arr + n);

    int min_ele, max_ele;
    int ans = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] >= k) {                              // heights cannot be -ve
            min_ele = min(arr[i] - k, arr[0] + k);
            max_ele = max(arr[i - 1] + k, arr[n - 1] - k);

            ans = min(ans, max_ele - min_ele);
        }

    return ans;
}
