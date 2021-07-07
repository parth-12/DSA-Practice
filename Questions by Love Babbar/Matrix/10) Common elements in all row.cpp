// A Program to prints common element in all
// rows of matrix


#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// prints common element in all rows of matrix
// using map
void printCommonElements1(int mat[M][N]) {

    unordered_map<int, int> mp;

    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;

    for (int i = 1; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mp.find(mat[i][j]) != mp.end() and mp[mat[i][j]] == i) {

                mp[mat[i][j]] = i + 1;
                if (i == M-1)
                    cout << mat[i][j] << " ";
            }
}

// using set
void printCommonElements2(int mat[M][N]) {
    unordered_set<int> st (mat[0], mat[0] + N);

    for (int i = 1; i < M; i++) {
        unordered_set<int> temp;

        for (int j = 0; j < N; j++)
            if (st.find(mat[i][j]) != st.end())
                temp.insert(mat[i][j]);

        st = temp;
    }
    for (auto a: st)
        cout << a << " ";

}


// driver code
int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    // printCommonElements1(mat);
    printCommonElements2(mat);

    return 0;
}
