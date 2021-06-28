// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
//
// There is only one repeated number in nums, return this repeated number.
//
// You must solve the problem without modifying the array nums and uses only constant extra space.



#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// bool array
int findDuplicate1(vector<int>&);

//unordered_set
int findDuplicate2(vector<int>&);

//floyd-cycle-finding algo     O(1) space
int findDuplicate3(vector<int>&);

int main() {
    int n = 6, A[] = {1, 3, 5, 2, 2, 2};
    vector<int> v(A, A+n);
    cout << findDuplicate1(v) << endl;

    cout << findDuplicate2(v) << endl;

    cout << findDuplicate3(v) << endl;

    return 0;
}

int findDuplicate1(vector<int>& nums) {
    long long n = nums.size();
    bool* hash = new bool [n];
    fill(hash, hash + n, false);

    for (auto a: nums) {
        if (hash[a] == false)
            hash[a] = true;
        else
            return a;
    }
    return -1;
}

int findDuplicate2(vector<int>& nums) {
    unordered_set<int> myset;

    myset.reserve(nums.size());

    for (auto& a: nums) {
        if (myset.find(a) == myset.end())
            myset.insert(a);
        else
            return a;
    }
    return -1;
}

int findDuplicate3(vector<int>& nums) {

    int s = nums[0];
    int tor = nums[s], hare = nums[nums[s]];

    while (tor != hare) {
        tor = nums[tor];
        hare = nums[nums[hare]];
    }

    hare = s;
    while (tor != hare) {
        tor = nums[tor];
        hare = nums[hare];
    }
    return hare;
}
