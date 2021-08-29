#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:

    // for +ve no.s only
    int sb_positive(int arr[], int n, int x)
    {
        int sum = 0, i = 0, start = 0;
        int ans = n + 1;
        while (i < n) {
            while (sum < x and i < n)
                sum += arr[i++];

            while (sum > x and start < n)
                sum -= arr[start++];

            while (sum == x and start < n){
                ans = min(ans, i - start);
                sum -= arr[start++];
            }
        }
        if (ans == n + 1){
            cout << "no array found" << endl;
            return -1;
        }
        return ans;
    }


    // for both +ve and -ve no.s
    int sb_int(int arr[], int n, int x)
    {

        int k = *min_element(arr, arr + n);

        if (k >= 0)
            return sb_positive(arr, n, x);

        k = abs(k);

        int sum = 0, i = 0, start = 0;
        int ans = n + 1;
        while (i < n) {
            while (sum < x + k * (i - start) and i < n)
                sum += arr[i++] + k;

            while (sum > x + k * (i - start) and start < n)
                sum -= arr[start++] + k;

            while (sum == x + k * (i - start) and start < n){
                ans = min(ans, i - start);
                sum -= arr[start++] + k;
            }
        }
        if (ans == n + 1){
            cout << "no array found" << endl;
            return -1;
        }
        return ans;
    }
};
