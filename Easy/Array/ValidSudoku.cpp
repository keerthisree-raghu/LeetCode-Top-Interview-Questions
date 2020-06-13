// VALID SUDOKU

/*  PROBLEM:
    Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

/*  EXAMPLE:

    Input:
    [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
    ]
    Output: true

    Input:
    [
    ["8","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
    ]
    Output: false
    Explanation: 
    Same as Example 1, except with the 5 in the top left corner being modified to 8. 
    Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

/*  APPROACH: 
    1. Initialize two-dimensional arrays to check if the value in one cell repeats in a row, column, or 3x3 sub-matrix.
    2. Iterate through every row and column.
    3. If the cell is filled with a value
        a. Store the value in a variable.
        b. Map the position from the 9x9 matrix to a 3x3 matrix using the formula:
           k = (i / 3) * 3 + (j / 3)
    4. If the element exists in the row or column or 3x3 matrix, return false.
    5. If it does not exist, set the cell value to 1.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Initialize two-dimensional arrays to track the row values, column values, and 3x3 sub-box values
        int row[9][9] = {0}, col[9][9] = {0}, subBox[9][9] = {0};
        // Iterate through every row and column of the sudoku board
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j <board[i].size(); j++) {
                // Check the cells which are filled with a number
                if(board[i][j] != '.') {
                    // Store the value in each cell 
                    // Subtracting '0' converts the character into an integer
                    int val = board[i][j] - '0' - 1;
                    // Formula to map 9x9 matrix into a 3x3 matrix
                    int k = (i / 3) * 3 + (j / 3);
                    // If the element exists in the row or column or sub-box, the sudoku solution won't be valid
                    if(row[i][val] || col[j][val] || subBox[k][val]) {
                        return false;
                    }
                    // If the element does not exists, set its value as 1
                    row[i][val] = col[j][val] = subBox[k][val] = 1;
                }
            }
        }
        return true;
    }
};