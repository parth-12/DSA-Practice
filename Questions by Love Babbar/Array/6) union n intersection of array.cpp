#include <iostream>
#include <set>
#include <unordered_set>
#include<algorithm>
#include<vector>
using namespace std;




// UNION
//https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// unordered_set                FAST
unsigned long union_sol1 (int [], int, int [], int);
// set, set_union               SLOW
long union_sol2 (int [], int, int [], int);


//INTERSECTION
//https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#
// unordered_set                FAST
int inter_sol1 (int [], int, int [], int);
//set, set_intersection         SLOW
long inter_sol2 (int [], int, int [], int);


int main() {
    int arr1[] = {1, 2, 3, 7, 1, 1, 6, 6};
    int n1 = sizeof(arr1)/sizeof(int);

    int arr2[] = {4, 5, 7, 6, 8, 8};
    int n2 = sizeof(arr2)/sizeof(int);


    // UNION
    cout << union_sol1 (arr1, n1, arr2, n2) << endl;
    cout << union_sol2 (arr1, n1, arr2, n2) << endl;

    //INTERSECTION
    cout << inter_sol1 (arr1, n1, arr2, n2) << endl;
    cout << inter_sol2 (arr1, n1, arr2, n2) << endl;

    return 0;
}




unsigned long union_sol1 (int a[], int n, int b[], int m) {
    unordered_set<int> myset (a, a + n);
    myset.insert(b, b + m);

    return myset.size();
}
long union_sol2 (int a[], int n, int b[], int m) {
    set<int> myset1 (a, a + n);
    set<int> myset2 (b, b + m);

    vector<int> v(n + m);
    vector<int>::iterator it;

    it = set_union (myset1.begin(), myset1.end(), myset2.begin(), myset2.end(),v.begin());

    return (it - v.begin());
}



int inter_sol1 (int a[], int n, int b[], int m) {
    unordered_set<int> myset (a, a+n);

    unordered_set<int> ans;
    for (int i = 0; i < m; i++) {
        if (myset.find(b[i]) != myset.end())
            ans.insert(b[i]);
    }
    return (int)ans.size();
}
long inter_sol2 (int a[], int n, int b[], int m) {
    set<int> myset1 (a, a + n);
    set<int> myset2 (b, b + m);

    vector<int> v(n + m);
    vector<int>::iterator it;

    it = set_intersection(myset1.begin(), myset1.end(), myset2.begin(), myset2.end(),v.begin());

    return (it - v.begin());
}
