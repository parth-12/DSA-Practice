// Given an array arr of size n and an integer X.
// Find if there's a triplet in the array which sums up to the given integer X.

#include <bits/stdc++.h>
using namespace std;


// main logic is iterate over array and find (X - A[i]) as the sum of 2 elements in remaining array
class Solution{
public:
    // using unordered_set (works only if elements are distinct) and O(n^2) time
    bool find3Numbers1(int A[], int n, int X)
    {
        unordered_set<int> s;

        for (int i = 0; i < n; i++)
            if (A[i] < X)
                s.insert(A[i]);


        for (auto it1 = s.begin(); it1 != s.end(); it1++)
            for (it2 = next(it1); it2 != s.end(); it2++) {
                int k = X - *it1 - *it2;
                if (s.find(k) != s.end() and k != *it1 and k != *it2)
                    return 1;
            }

        return 0;
    }


    // using sorting and O(1) space and O(n^2) time
    bool find3Numbers2(int A[], int n, int X)
    {
        sort(A, A + n);
        int flag = 0;
        for (int i = 0; i < n - 2 and A[i] < X - 1; i++) {
            int sum = X - A[i];

            int l = i +1, r = n - 1;

            while (l < r)
                if (A[l] + A[r] == sum)
                    return 1;
                else if (A[r] > X - 2 or A[l] + A[r] > sum)
                    r--;
                else
                    l++;

        }
        return 0;
    }
};
