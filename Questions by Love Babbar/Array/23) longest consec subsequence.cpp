// Given an array of positive integers.
// Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
// the consecutive numbers can be in any order.



#include <bits/stdc++.h>
using namespace std;


// Functions to return length of longest subsequence of consecutive integers.
class Solution{
public:
    int findLongestConseqSubseq1(int arr[], int N) {
        int* st = new int [100001];

        for (int i = 0; i < 100001; i++)
            st[i] = 0;

        for (int i = 0; i < N; i++)
            st[arr[i]] = 1;

        int cnt = 0, ans = 0;
        for (int i = 0; i < 100001; i++)
            if (st[i] == 1)
                cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        return max(ans, cnt);
    }

    int findLongestConseqSubseq2(int arr[], int N) {
        unordered_set<int> s;
        for (int i = 0; i < N; i++)
            s.insert(arr[i]);

        int c = 0, ans = 0;
        for (int i = 0; i < N; i++)
            if (s.find(arr[i] - 1) == s.end()) {

                while (s.find(arr[i] + c) != s.end())    c++;

                ans = max(c, ans);
                c = 0;
            }

        return ans;
    }
};


// Driver program
int main()
{
    int  t,n,i,a[100001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        Solution obj;
        cout<<obj.findLongestConseqSubseq1(a, n)<<endl;
    }

    return 0;
}
