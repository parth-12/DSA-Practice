// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.


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
