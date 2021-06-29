// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with k sum.


#include <iostream>
#include <unordered_set>
using namespace std;

class Solution{
public:
    // Subarry with sum k exists or not
    bool subArrayExists(int arr[], int n, int k)
    {
        int val = 0;
        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            val += arr[i];
            if (s.find(val - k) == s.end() and val != k)
                s.insert(val);
            else return 1;
        }
        return 0;
    }
};

// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n, k))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}  // } Driver Code Ends
