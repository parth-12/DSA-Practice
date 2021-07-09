// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m.
// Task is to check whether a2[] is a subset of a1[] or not.
// Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.


// using unordered set and insert (fastest)
string isSubset3(int a1[], int a2[], int n, int m) {
    unordered_set<int> s (a1, a1 + n);
    int k = s.size();

    s.insert(a2, a2 + m);

    if (s.size() == k)
        return "Yes";
    else
        return "No";
}



// using includes
string isSubset1(int a1[], int a2[], int n, int m) {
    set<int> s1 (a1, a1 + n);
    set<int> s2 (a2, a2 + m);

    if (includes(s1.begin(),s1.end(), s2.begin(),s2.end()))
        return "Yes";
    else
        return "No";
}

// using set_difference
string isSubset2(int a1[], int a2[], int n, int m) {
    set<int> s1 (a1, a1 + n);
    set<int> s2 (a2, a2 + m);


    vector<int> v(m);
    auto it = set_difference(s2.begin(),s2.end(), s1.begin(),s1.end(), v.begin());

    if (it - v.begin() == 0)
        return "Yes";
    else
        return "No";
}
