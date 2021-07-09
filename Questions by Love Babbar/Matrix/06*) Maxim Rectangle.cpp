// Given a rows x cols binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.


#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// Time complexity O(r*c)    space : O(c)
class Solution {
public:
    int maximalRectangle(vector<vector<int>>& matrix) {
        if (!matrix.size()) return 0;

        int m = (int) matrix.size();
        int n = (int) matrix[0].size();       // this line gives error if m = 0 so above if condtn is required

        int maxArea = 0;

        vector<int> row(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    row[j]++;
                else
                    row[j] = 0;
            }
            maxArea = max(maxArea, maxAreaInHisto(row));
        }

        return maxArea;
    }

    // max area of rectangle in a histogram

    // can be made also done in storing heights in stack
    // see E1) largest rectangle area in histogram
    int maxAreaInHisto(vector<int>& h) {
        int maxArea = 0;

        h.push_back(0);
        stack<int> s;

        int n = (int) h.size();

        int i = 0;
        while (i < n) {
            if (s.empty() or h[i] > h[s.top()])
                s.push(i++);
            else if (h[i] == h[s.top()])
                s.pop();
            else {
                int top = s.top();
                s.pop();
                maxArea = max(maxArea, h[top] * (s.empty() ? i : i - (s.top() + 1)) );
            }
        }

        h.pop_back();

        return maxArea;
    }
};

int main() {
    vector<vector<int>> bi_mat = {
                                    { 0, 1, 1, 0 },
                                    { 1, 1, 1, 1 },
                                    { 1, 1, 1, 1 },
                                    { 1, 1, 0, 0 },
                                };
    Solution ob;

    cout << "Maximum area is: " << ob.maximalRectangle(bi_mat) << endl;
    return 0;
}
