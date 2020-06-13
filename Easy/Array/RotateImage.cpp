// ROTATE IMAGE

/*  PROBLEM:
    You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
*/

/*  EXAMPLE:

    Input: 
    [
    [1,2,3],
    [4,5,6],
    [7,8,9]
    ],
    Output:
    [
    [7,4,1],
    [8,5,2],
    [9,6,3]
    ]

    Input:
    [
    [ 5, 1, 9,11],
    [ 2, 4, 8,10],
    [13, 3, 6, 7],
    [15,14,12,16]
    ], 
    Output:
    [
    [15,13, 2, 5],
    [14, 3, 4, 1],
    [12, 6, 8, 9],
    [16, 7,10,11]
    ]
*/

/*  APPROACH: 
    1. Find the transpose of the matrix. (Rows -> Columns)
    2. Reverse every row.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // Find the transpose of every matrix
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row of the matrix
        for(int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};