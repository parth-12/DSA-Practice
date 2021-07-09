// Given an integer N, find its factorial.
// 1 ≤ N ≤ 1000

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void multiply (vector<int>& v, int x) {

        int carry = 0, mult;

        for (int i = 0; i < v.size(); i++) {
            mult = v[i] * x + carry;

            v[i] = mult % 10;
            carry = mult / 10;
        }

        while (carry) {
            v.push_back(carry % 10);
            carry /= 10;
        }
    }

    vector<int> factorial(int N){
        vector<int> v;
        v.reserve(2600);

        v.push_back(1);

        for (int i = 2; i <= N; i++)
            multiply (v, i);

        reverse(v.begin(), v.end());

        return v;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
