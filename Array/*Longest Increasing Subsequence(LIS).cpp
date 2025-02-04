// O(nlogn) crazy soln
class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n =arr.size();
        vector<int> seq({arr[0]});
        for(int i=0; i<n; i++) {
            if(arr[i] > seq.back()) seq.push_back(arr[i]);
            else {
                int idx = lower_bound(seq.begin(), seq.end(), arr[i])-seq.begin();
                seq[idx] = arr[i];
            }
        }
        return seq.size();
    }
};

// O(n^2) soln and O(n) space complexity
class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n =arr.size();
        vector<int> lis(n, 1);
        int ans = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(arr[j] < arr[i] and lis[j] + 1 > lis[i])
                    lis[i] = lis[j] + 1;
            }
            ans = max(lis[i], ans);
        }
        return ans;
    }
};
// each dp[i] represents the lis till that index;



// to PRINT the lis we maintain a prev array, which element in the array points to
// corresponding previous smaller element in the array.

// O(n^2) soln and O(n) space complexity
// we can get here the lexiographically smallest or largest lis, but not in log(n) soln
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> lis(n, 1);
        vector<int> prev(n, -1);
        for(int i=0; i<n; i++)  for(int j=0; j<i; j++) {
            if(arr[j] < arr[i] and lis[j]+1 > lis[i]) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }

        int lis_size = 0, idx = -1;
        for(int i=0; i<n; i++) {
            if(lis_size < lis[i]) {
                lis_size = lis[i];
                idx = i;
            }
        }

        vector<int> res;
        while(idx != -1) {
            res.push_back(arr[idx]);
            idx = prev[idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//O(logn) print LIS soln, we just maintain a seq of indices of elements rather the element themselves.
// just cooperate maintaining prev array here : for ref =
// https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n =arr.size();

        vector<int> seq({0});

        for(int i=1; i<n; i++) {
            if(arr[i] > arr[seq.back()]) seq.push_back(i);
            else {
                int idx = lower_bound(seq.begin(), seq.end(), arr[i], [&arr](int j, int val){
                    return arr[j] < val;
                    })-seq.begin();
                seq[idx] = i;
            }
        }
        return seq.size();
    }
};
