#include <iostream>
using namespace std;

void reversearray1(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void reversearray2(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end)
        swap(arr[start++], arr[end--]);
}
