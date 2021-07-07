//Write an efficient algorithm that searches for a value in an m x n matrix.
//This matrix has the following properties:
//
//  Integers in each row are sorted from left to right.
//  The first integer of each row is greater than the last integer of the previous row.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size(), c = matrix[0].size();

        int start = 0, end = r * c - 1;

        // binary search
        while (start <= end) {
            int val = (start + end)/2;

            int i = val / c;
            int j = val % c;

            if (matrix[i][j] == target)
                return 1;

            else if(matrix[i][j] > target)
                end = val - 1;

            else
                start = val + 1;
        }
        return 0;
    }
};
