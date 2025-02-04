// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

//this soln only works if the empty subarrys are admitted !!
class Solution{
    public:
    int maxSubarraySum(int arr[], int n){

        int sum = 0, ans = 0;
        for (int i = 0; i < n ; i++) {
            sum += arr[i];
            ans = max(ans, sum);

            if (sum < 0) sum = 0;
        }
        return ans;
    }
};

// The Real Kadane's algo where empty subarrys are not admitted 
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int res = INT_MIN, sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum = max(sum + arr[i], arr[i]);
            res = max(res, sum);
        }
        return res;
    }
};
