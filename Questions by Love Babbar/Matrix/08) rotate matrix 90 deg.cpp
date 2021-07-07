// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

#include <iostream>
using namespace std;

#define N 4
void ex_elements1(int [][N], int , int );

void ex_elements2(int [][N], int, int );
void back_assign(int [][N], int& , int&);


// rotating group of 4 cells
void rotate90_1(int mat[][N]) {

    for (int i = 0; i < (N + 1)/2; i++)
        for (int j = 0; j < N/2; j++)
            ex_elements2(mat, i, j);
}

//transpose and mirror image
void rotate90_2(int mat[][N]) {

    // Left Diagonal rotation
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);

    // Vertical rotation
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N/2; j++)
            swap(mat[i][j],mat[i][N - 1 - j]);
}


void printMatrix(int arr[N][N]);



// Driver code
int main() {
    int r,c;
    int arr[N][N] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
    printMatrix(arr);
    cout << endl << endl;
    rotate90_2(arr);
    printMatrix(arr);
    return 0;
}





void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}


void ex_elements1(int mat, int i, int j) {
    int temp = mat[i][j];

    mat[i][j] = mat[N - 1 - j][i];
    mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
    mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
    mat[j][N - 1 - i] = temp;
}



void ex_elements2(int mat[][N], int i, int j) {
    int temp = mat[i][j];

    int  k = 3;
    while(k--)
        back_assign(mat, i, j);

    mat[i][j] = temp;
}

void back_assign(int mat[][N], int& i, int& j) {
    mat[i][j] = mat[N - 1 - j][i];

    int t = i;
    i = N - 1 - j;
    j = t;
}
