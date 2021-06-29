// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:

    // erasing the elements
    int getPairsCount1(int arr[], int n, int k);

    // counting twice (better)
    int getPairsCount2(int arr[], int n, int k);
};

int Solution::getPairsCount1(int arr[], int n, int k) {

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        if (arr[i] < k){
            map[arr[i]]++;
        }
    }
    int ans = 0;
    while (!map.empty()) {
        int n = (map.begin())->first;

        if (n == k - n)
            ans += (map[n] * (map[n] - 1))/2;

        else if (map.count(k - n) == 1) {
            ans += map[n] * map [k - n];
            map.erase(k - n);
        }
        map.erase(n);
    }
    return ans;
}

int Solution::getPairsCount2(int arr[], int n, int k) {

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        if (arr[i] < k)
            map[arr[i]]++;

    int ans = 0;
    for (auto a: map) {
        int n = a.first;
        if (n == k - n)
            ans += map[n] * (map[n] - 1);
        else
            if (map.count(k - n) == 1)
                ans += map[k - n] * map[n];

    }
    return ans/2;
}



// { Driver Code Starts.
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount2(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}  // } Driver Code Ends
