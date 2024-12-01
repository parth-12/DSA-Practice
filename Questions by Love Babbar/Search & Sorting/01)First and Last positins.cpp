//Given a sorted array arr with possibly some duplicates, the task is to find the first and last occurrences of an element x in the given array.


//my first soln
class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        vector<int> ans = {-1, -1};
        int s = 0, e = arr.size()- 1, m = -1;
        // bs for finding first value
        while(s != e) {
            m = (s+e)/2;
            if (arr[m] < x) s = m + 1;
            else            e = m;
        }
        if (arr[s] == x) ans[0] = s;
        s = 0, e = arr.size()-1;
        // bs for finding last value
        while(s != e) {
            m = (s+e+1)/2;
            if (arr[m] <= x) s = m;
            else            e = m-1;
        }
        if (arr[s] == x) ans[1] = s;
        return ans;
    }
};

// easier to understand, less to think code, by gfg

class Solution {
  public:
    // Function to find the first and last occurrence of x in the array
    vector<int> find(vector<int>& arr, int x) {

        int n = arr.size();
        vector<int> ans(2, -1);

        // Find the first occurrence of x
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                ans[0] = mid;
                right = mid - 1;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Find the last occurrence of x
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                ans[1] = mid;
                left = mid + 1;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
