// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<vector<int>> merge1(vector<vector<int>>&);

//using sorting
vector<vector<int>> sort_merge(vector<vector<int>>&);



// Driver code
int main() {
    vector<vector<int>> v;
    string s;
    cin >> s;

//    int a = 0;
//    bool pre = 0;
//    for (int i = 1; i < s.length() - 1; i++) {
//        char c = s[i];
//        if (c == '[') {
//            vector<int> temp;
//            v.push_back(temp);
//        }
//        else if (c != ']' && c != ',') {
//            a = a*10 + (c - '0');
//            pre = 1;
//        }
//        else if ((c == ']' || c == ',') && pre == 1) {
//            (*(v.end() - 1)).push_back(a);
//            a = 0;
//            pre = 0;
//        }
//    }

    stringstream ss(s);
    char ch;
    int a, b;

    ss >> ch;
    while (ss >> ch)
        if (ch == '[') {
            ss >> a >> ch >> b >> ch;
            v.push_back({a,b});
        }

    vector<vector<int>> merged1 = merge1(v);

    vector<vector<int>> merged2 = sort_merge(v);


    for (auto a: merged1) {
        for (auto b: a)
            cout << b << " ";
        cout << endl;
    }

    for (auto a: merged2) {
        for (auto b: a)
            cout << b << " ";
        cout << endl;
    }
    return 0;
}

vector<vector<int>> merge1(vector<vector<int>>& intervals) {

    vector<vector<int>> finals;
    finals.reserve(intervals.size());

    for (auto& a: intervals) {
        int low = a[0];
        int high = a[1];

        int flag = 1;
        for (auto& b: finals) {
            if (b[0] <= low && low <= b[1]) {
                b[1] = max(b[1], high);
                flag = 0;
                break;
            }
            else if (b[0] <= high && high <= b[1]) {
                b[0] = low;
                flag = 0;
                break;
            }
        }

        if (flag) {
            finals.push_back({low,high});
        }
    }


    for (auto it = finals.end() - 1; it >= finals.begin(); it--) {
        int low = (*it)[0];
        int high = (*it)[1];

        int in_flag = 0;
        for (auto it2 = finals.begin(); it2 != finals.end(); it2++) {
            vector<int>& b = (*it2);
            if (b[0] <= low && low <= b[1] && it2 != it) {
                b[1] = max(b[1], high);
                in_flag = 1;
                break;
            }
            else if (b[0] <= high && high <= b[1]  && it2 != it) {
                b[0] = low;
                in_flag = 1;
                break;
            }
        }
        if (in_flag) {
            finals.erase(it);
        }
    }
    return finals;
}

vector<vector<int>> sort_merge(vector<vector<int>>& intervals) {
    vector<vector<int>>& in = intervals;
    sort(in.begin(), in.end());
    vector<vector<int>> f (in.begin(),in.begin()+ 1);


    for (int i = 1; i < in.size(); i++) {
        if (in[i][0] <= f.back()[1]) {
            f.back() = {f.back()[0], max(f.back()[1], in[i][1])};
        }
        else
            f.push_back(in[i]);
    }

    return f;
}
