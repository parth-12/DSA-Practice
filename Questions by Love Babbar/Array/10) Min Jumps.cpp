// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element.
// Find the minimum number of jumps to reach the end of the array (starting from the first element).
// If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.



#include <iostream>
using namespace std;

int min_jumps(int [], int);

int main() {
    int n = 11, A[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int m = 3, B[] = {1,2,1};
    cout << min_jumps(B, m) << endl;
    return 0;
}

int min_jumps(int arr[], int n) {
    int access = arr[0];

    int jumps = 1, i = 1, reach = 0;
    while (access < n - 1) {
        jumps++;
        reach = access;

        for (; i <= access; i++)
            reach = max(reach,  i + arr[i]);

        if (reach == access)        // cannot reach the end
            return -1;

        access = reach;
    }
    return jumps;
}
