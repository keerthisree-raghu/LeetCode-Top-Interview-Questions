// PASCAL'S TRIANGLE

/*  PROBLEM:
    Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

    Note: In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/

/*  EXAMPLE:

    Input: 5
    Output:
    [   [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1] ]
*/

/*  APPROACH: Iterative - O(n^2)
    1. Allocate space in each row and initialize the values as 1.
    2. Fill the elements of each row by calculating the sum of the diagonally adjacent elements above the current element.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            // Allocate space in each row and initialize values as 1
            res.push_back(vector<int>(i+1, 1));
            for(int j = 1; j < i; j++) {
                // Calculate the value of each element as the sum of the diagonally adjacent elements above it
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};