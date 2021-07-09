// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
//
// Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    int sb(int arr[], int n, int x)
    {
        int sum = 0, i = 0, start = 0;
        int ans = n + 1;
        while (i < n) {
            while (sum <= x and i < n)
                sum += arr[i++];

            while (sum > x and start < n) {
                ans = min(ans, i - start);
                sum -= arr[start++];
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution obj;
        cout<<obj.sb(a,n,x)<<endl;
    }
    return 0;
}
