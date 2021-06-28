// An array contains both positive and negative numbers in random order.
// Rearrange the array elements so that all negative numbers appear before all positive numbers.



#include <iostream>
#include <utility>
using namespace std;


// similar to dutch flag algo
void sep1(int [], int);

// less no. of swap here
void sep2(int [], int);

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}



int main() {
    int arr[] = { -2, 2, 1, -7, 5, 4, -5, 0, -15, -19, 24, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sep2(arr, n);

    printarray(arr, n);
    return 0;
}



void sep1(int arr[], int n) {
    int neg = 0;
    int pos = n - 1;

    while (neg <= pos) {
        if ( arr[neg] < 0)
            neg++;
        else
            swap(arr[neg],arr[pos--]);
    }
}

void sep2(int arr[], int n) {
    int l = 0, r = n-1;

    while (l < r) {
        while (arr[l] < 0 && l < r) {
            l++;
        }
        while (arr[r] > 0 && l < r) {
            r--;
        }

        if (l < r) {
            swap(arr[l++],arr[r--]);
        }
    }
}
