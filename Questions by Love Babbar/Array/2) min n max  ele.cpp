#include <iostream>
using namespace std;

int* makearray(int);

// Tournament method
// Divide and Conquer... algo paradigm
struct Pair get_minmax(int [], int, int);

struct Pair {
    int min, max;
};

int main() {
    int n;
    cin >> n;
    int* arr = makearray(n);

    struct Pair m = get_minmax(arr, 0, n - 1);

    cout << "min: " << m.min << endl;
    cout << "max: " << m.max << endl;

    return 0;
}

struct Pair get_minmax(int arr[], int l, int h){
    struct Pair p;

    if (l == h) {
        p.min = arr[l];
        p.max = arr[l];
        return p;
    }

    if (l + 1 == h) {
        if (arr[l] < arr[h]) {
            p.min = arr[l];
            p.max = arr[h];
        }
        else {
            p.min = arr[h];
            p.max = arr[l];
        }
        return p;
    }

    struct Pair left, right;
    int m = (l + h)/2;

    left = get_minmax(arr, l, m);
    right = get_minmax(arr, m + 1, h);

    if (left.min < right.min) {
        p.min = left.min;
    }
    else p.min = right.min;

    if (left.max > right.max) {
        p.max = left.max;
    }
    else p.max = right.max;

    return p;

}

int* makearray(int n) {
    int* arr = new int [n];
    for (int  i= 0; i<n; i++)
        cin >> arr[i];

    return arr;
}
