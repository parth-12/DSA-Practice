// Given an array Arr that contains N integers (may be positive, negative or zero).
// Find the product of the maximum product subarray.


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long product = 1, fn_pro, max_pro = LONG_LONG_MIN;

	    int flag = 1;
	    for (int i = 0; i <  n; i++) {
	        if (arr[i] == 0) {
	            flag = 1;
	            if (product < 0)
	                max_pro = max(product / fn_pro, max_pro);
	            product = 1;
	            continue;

	        }
	        product *= arr[i];

	        if (flag == 1 and product < 0) {
	            flag = 0;
	            fn_pro = product;
	        }

	        max_pro = max(max_pro, product);
	    }
	    if (product < 0)
	        max_pro = max(product / fn_pro, max_pro);
	    return max_pro;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
