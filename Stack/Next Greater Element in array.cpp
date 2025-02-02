// time complexity - O(n).... space complexity - O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, k = -1;
        for (int i=0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                k = i;
            }
        }

        k++;    // making highest elemt last element, so that the cyclic problem is solved
        stack<int> st;
        vector<int> ans (n, -1);
        for (int i = n-1 + k; i>=k; i--) {
            int num = nums[i%n];
            while(!st.empty() and st.top() <= num)
                st.pop();

            if (st.empty()) ans[i%n] = -1;
            else ans[i%n] = st.top();
            st.push(num);
        }
        return ans;
    }
};


// sexy advanced level question - https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/
// to get the leftmost greater element than 'h' after index i
