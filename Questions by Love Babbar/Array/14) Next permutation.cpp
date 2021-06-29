//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
//
//The replacement must be in place and use only constant extra memory.



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int i = nums.size() - 1;
        for (; i >= 1; i--) {
            if (nums[i] > nums[i - 1]){
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for (int j = nums.size() - 1; true; j--) {
            if (nums[j] > nums[i - 1]) {
                swap(nums[j], nums[i - 1]);
                break;
            }
        }
        reverse(nums.begin() + i,nums.end());
    }
};
