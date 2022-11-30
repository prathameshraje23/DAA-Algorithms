//strassens matrix naive method




// C++ program to multiply
// two square matrices.
#include <iostream>

using namespace std;

#define N 4

// This function multiplies
// mat1[][] and mat2[][], and
// stores the result in res[][]
void multiply(int mat1[][N],
            int mat2[][N],
            int res[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

// Driver Code
int main()
{
    int i, j;
    int res[N][N]; // To store result
    int mat1[N][N] = { { 1, 1, 1, 1 },
                    { 2, 2, 2, 2 },
                    { 3, 3, 3, 3 },
                    { 4, 4, 4, 4 } };

    int mat2[N][N] = { { 1, 1, 1, 1 },
                    { 2, 2, 2, 2 },
                    { 3, 3, 3, 3 },
                    { 4, 4, 4, 4 } };

    multiply(mat1, mat2, res);

    cout << "Result matrix is \n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
}




//Algorithm:
//square_matrix_multiply(a, b)
//n = a.rows
//let c be a new n x n matrix
//for i = 1 to n
//for j = 1 to n
//cij = 0
//for k=1 to n
//cij = cij + (aik * bkj)
//return c
//For accessing all the elements of any matrix we need two for loops. But for finding
//the product, it requires one additional for loop. That’s how it is taking 3 for loops.

//Time Complexity: O(n^3)
