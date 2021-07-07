// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.


#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    // also given r and c are always odd
    int median(vector<vector<int>> &matrix, int r, int c){

        int minn = INT32_MAX;
        int maxx = INT32_MIN;

        for (int i = 0; i < r; i++) {
            minn = min(minn, matrix[i][0]);
            maxx = max(maxx, matrix[i][c - 1]);
        }

        int start = minn, end = maxx;

        int desired = (r * c + 1)/2;

        // checking on whole no. line b/w minn and maxx irrespective of whether it is in matrix or not

        // finding a number n which has ( place >= desired) where n - 1 has (place < desired)
        // So n is the median !!

        while (start < end) {
            int mid = (start + end)/2;
            int place = 0;

            for (int i = 0; i < r; i++)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (place < desired)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};


int main() {
    int t;
    cin >> t;
    while(t--) {
        int r,c;
        cin >> r >> c;
        vector<vector<int>> matrix (r, vector<int> (c));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> matrix[i][j];

        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }

    return 0;
}
