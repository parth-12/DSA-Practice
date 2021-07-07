// Given a boolean 2D array of n x m dimensions where each row is sorted.
// Find the 0-based index of the first row that has the maximum number of 1's.

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    // Time compl : O(m + n)
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int ans = -1;
        int one_ind = m - 1;
        for (int i = 0; i < n; i++) {
            if (arr[i][one_ind] == 1) {
                while (one_ind >= 0 and arr[i][one_ind--]);

                if (one_ind == -1 and arr[i][0])
                    return i;
                one_ind++;
                ans = i;
            }
        }
        return ans;
    }

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
