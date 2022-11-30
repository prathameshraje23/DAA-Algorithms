//Q2) Implement algorithm for Tiling problem: Given an n by n board
//where n is of form 2k where k >= 1 (Basically n is a power of 2 with
//minimum value as 2). The board has one missing cell (of size 1 x 1). Fill
//the board using L shaped tiles. An L shaped tile is a 2 x 2 square with
//one cell of size 1×1 missing





#include <bits/stdc++.h>
using namespace std;
 
int size_of_grid, b, a, cnt = 0;
int arr[128][128];
 
// Placing tile at the given coordinates
void place(int x1, int y1, int x2,
           int y2, int x3, int y3)
{
    cnt++;
    arr[x1][y1] = cnt;
    arr[x2][y2] = cnt;
    arr[x3][y3] = cnt;
}
// Quadrant names
// 1   2
// 3   4
 
// Function based on divide and conquer
int tile(int n, int x, int y)
{
    int r, c;
    if (n == 2) {
        cnt++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[x + i][y + j] == 0) {
                    arr[x + i][y + j] = cnt;
                }
            }
        }
        return 0;
    }
    // finding hole location
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[i][j] != 0)
                r = i, c = j;
        }
    }
 
    // If missing tile is 1st quadrant
    if (r < x + n / 2 && c < y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2,
              y + n / 2, x + n / 2 - 1, y + n / 2);
 
    // If missing Tile is in 3rd quadrant
    else if (r >= x + n / 2 && c < y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
              y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
 
    // If missing Tile is in 2nd quadrant
    else if (r < x + n / 2 && c >= y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2,
              y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
 
    // If missing Tile is in 4th quadrant
    else if (r >= x + n / 2 && c >= y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
              y + (n / 2) - 1, x + (n / 2) - 1,
              y + (n / 2) - 1);
 
    // dividing it again in 4 quadrants
    tile(n / 2, x, y + n / 2);
    tile(n / 2, x, y);
    tile(n / 2, x + n / 2, y);
    tile(n / 2, x + n / 2, y + n / 2);
 
    return 0;
}
// Driver program to test above function
int main()
{
    // size of box
    size_of_grid = 8;
    memset(arr, 0, sizeof(arr));
    // Coordinates which will be marked
    a = 0, b = 0;
    // Here tile can not be placed
    arr[a][b] = -1;
    tile(size_of_grid, 0, 0);
    // The grid is
    for (int i = 0; i < size_of_grid; i++) {
        for (int j = 0; j < size_of_grid; j++)
            cout << arr[i][j] << " \t";
        cout << "\n";
    }
}







//Algorithm:
//1) Start.
//2) Base case: n = 2, A 2 x 2 square with one cell missing is nothing but a tile and
//can be filled with a single tile.
//3) Place a L shaped tile at the center such that it does not cover the n/2 * n/2
//subsquare that has a missing square. Now all four subsquares of size n/2 x n/2 have
//a missing cell (a cell that doesn't need to be filled).
//4) Solve the problem recursively for following four. Let p1, p2, p3 and p4 be
//positions of the 4 missing cells in 4 squares.
//a. a) Tile(n/2, p1)
//b. b) Tile(n/2, p2)
//c. c) Tile(n/2, p3)
//d. d) Tile(n/2, p3)
//5) Go to Step 3.
//6) End.


//Time Complexity: O(n*n)