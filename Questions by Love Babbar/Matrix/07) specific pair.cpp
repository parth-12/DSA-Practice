// Given an n x n matrix mat[n][n] of integers,
// find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int specific_pair(vector<vector<int>>& Mat) {
    int m = (int) Mat.size();
    int n = (int) Mat[0].size();


    for (int i = 1; i < n; i++)
        Mat[0][i] = min(Mat[0][i - 1], Mat[0][i]);

    for (int i = 1; i < m; i++)
        Mat[i][0] = min(Mat[i - 1][0], Mat[i][0]);

    int ans = INT_MIN;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++) {
            ans = max(ans, Mat[i][j] - Mat[i - 1][j - 1]);

            Mat[i][j] = min({Mat[i][j], Mat[i][j - 1], Mat[i - 1][j]});
        }

    return ans;
}




int main() {
    vector<vector<int>> vec = { { 1, 2, -1, -4, -20 },
                                { -3, -8, 4, 2, 1 },
                                { 3, 8, 6, 1, 3 },
                                { -4, -1, 1, 7, -6 },
                                { 0, -4, 10, -5, 1 }};


    cout << specific_pair(vec) << endl;
    return 0;
}
