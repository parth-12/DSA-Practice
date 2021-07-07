// Given a matrix of size r*c. Traverse the matrix in spiral form.


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    // wall logic
    vector<int> spirallyTraverse1(vector <vector<int>>& matrix, int r, int c) {
        int sr = -1 , er = r;
        int i = 0;

        int sc = -1 , ec = c;
        int j = 0;

        vector<int> v;
        v.reserve(r*c);

        while (true) {
            //top
            while (j < ec)
                v.push_back(matrix[i][j++]);

            sr++; i++; j--;
            if (er - sr == 1) break;


            //right
            while (i < er)
                v.push_back(matrix[i++][j]);

            ec--; i--; j--;
            if (ec - sc == 1) break;


            //bottom
            while ( j > sc)
                v.push_back(matrix[i][j--]);

            er--; i--; j++;
            if (er - sr == 1) break;

            //left
            while (i > sr)
                v.push_back(matrix[i--][j]);

            sc++; i++; j++;
            if (ec - sc == 1) break;
        }

        return v;
    }

    //recursive code
    vector<int> spirallyTraverse2(vector <vector<int>>& matrix, int r, int c) {

        vector<int> v;
        v.reserve(r*c);

        // Not possible with vectors if recursion by address and not index
        // as elements of 2 rows are not stored in continuous memory locations
        // vector<int> v = {1,2}

        // &v  and &v[0] are different
        // but &v[0] and &v[1] are continous
        int arr[r][c];

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                arr[i][j] = matrix[i][j];

        spt(arr[0], r, c, c, v);

        return v;
    }
    void spt(int *arr, int r, int c, int C, vector<int>& v) {

        if (r == 0 or c == 0)
            return;

        if (r == 1){
            v.insert(v.end(), arr, arr + c);
            return;
        }
        if (c == 1) {
            for (int i = 0; i < r; i++)
                v.push_back(*(arr + i * C));
            return;
        }


        //top row
        v.insert(v.end(), arr, arr + c);

        //right
        for (int i = 1; i < r - 1; i++)
            v.push_back(*(arr + i * C + c - 1));

        //bottom
        reverse_copy(arr + (r - 1) * C, arr + (r - 1) * C + c, back_inserter(v));

        //left
        for (int i = r - 2; i > 0; i--)
            v.push_back(*(arr + i * C));

        spt(arr + C + 1, r - 2, c - 2, C, v);

    }


    // O(r*c) extra space to checked visited elements but used vector bool
    vector<int> spirallyTraverse3(vector <vector<int>>& matrix, int r, int c) {

        vector<int> v;

        vector<vector<bool>> seen(r, vector<bool>(c,false));
        int dr[][2] = {0,1 , 1,0 , 0,-1 , -1,0};

        int i = 0, j = 0, direction = 0;

        int n = r*c;

        while (n--) {
            v.push_back(matrix[i][j]);

            seen[i][j] = true;

            int cr = i + dr[direction][0];
            int cc = j + dr[direction][1];

            if (cr < 0 or cr >= r or cc < 0 or cc >= c or seen[cr][cc]) {
                //turn clockwise
                direction = (direction + 1) % 4;

                i += dr[direction][0];
                j += dr[direction][1];
            }
            else {
                i = cr;
                j = cc;
            }
        }
        return v;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> matrix (r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c,0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector <int> result = ob.spirallyTraverse2(matrix, r, c);

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << ' ';
        cout << endl;
        return 0;
    }
}
