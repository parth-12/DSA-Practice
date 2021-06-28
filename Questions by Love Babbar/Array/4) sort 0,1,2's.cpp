// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


// Dutch ANational Flag Algo (3 - way partioning)
void sort012(int arr[], int n) {

    int low = 0, mid = 0;
    int high = n - 1;

    while ( mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid++],arr[low++]);
        }
        else if (arr[mid] == 1) mid++;
        else {
            swap(arr[mid], arr[high--]);
        }
    }
}
