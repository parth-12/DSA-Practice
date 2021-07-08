#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution{
public:

    // time complexity O(32 * summation of log(size of each row))
    double median_n_sorted(vector<vector<int>> &matrix){

        int tot = 0;
        for (int i = 0; i < matrix.size(); i++)
            tot += matrix[i].size();


        if (tot & 1) {
            int minn = INT32_MAX;
            int maxx = INT32_MIN;

            for (int i = 0; i < matrix.size(); i++)
                if (matrix[i].size()) {
                    minn = min(minn, matrix[i][0]);
                    maxx = max(maxx, matrix[i].back());
                }


            int start = minn, end = maxx;

            int desired = (tot + 1)/2;

            while (start < end) {
                int mid = floor((start + end) / 2.0);
                int place = 0;

                for (int i = 0; i < matrix.size(); i++)
                    place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

                if (place < desired)
                    start = mid + 1;
                else
                    end = mid;
            }
            return start;
        }

        else {
            int minn = INT32_MAX;
            int maxx = INT32_MIN;

            for (int i = 0; i < matrix.size(); i++)
                if (matrix[i].size()) {
                    minn = min(minn, matrix[i][0]);
                    maxx = max(maxx, matrix[i].back());
                }

            int start = minn, end = maxx;

            int desired = tot / 2;

            while (start < end) {
                int mid = floor((start + end) / 2.0);

                int place = 0;

                for (int i = 0; i < matrix.size(); i++)
                    place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

                if (place < desired)
                    start = mid + 1;
                else
                    end = mid;
            }

            // running once more to find the next element
            int min_of_nexts = INT_MAX, place = 0;

            for (int i = 0; i < matrix.size(); i++) {
                auto it = upper_bound(matrix[i].begin(), matrix[i].end(), start);

                place += it - matrix[i].begin();

                min_of_nexts = min(it != matrix[i].end() ? *it : INT_MAX, min_of_nexts);
            }
            return place == desired ? (start + min_of_nexts)/2.0 : start;
        }
    }
};



// Driver code
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix (n);

        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            matrix[i].assign(c,0);
            for (int j = 0; j < c; j++)
                cin >> matrix[i][j];
        }
        Solution obj;
        cout << obj.median_n_sorted(matrix) << endl;
    }

    return 0;
}
