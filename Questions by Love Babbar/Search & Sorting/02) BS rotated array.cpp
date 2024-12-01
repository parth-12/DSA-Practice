//There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.


// my soln.... finding the index f first element and then nrmal binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0, e = n-1, m, k = 0;
        // finding first element index if rotated
        if (nums[0] > nums[n-1]) {
            while(e-s != 1) {
                m = (s+e)/2;
                if (nums[e] > nums[m]) e = m;
                else s = m;
            }
            k = e;
        }

        // normal binary search
        s = k, e = n-1 + k;
        while(s <= e){
            m = (s+e)/2;
            if (nums[m%n] == target) return m%n;
            else if (nums[m%n] < target) s = m+1;
            else e = m-1;
        }
        return -1;
    }
};


// crazy soln
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
