// POWER OF THREE

/*  PROBLEM:
    Given an integer, write a function to determine if it is a power of three.
*/

/*  EXAMPLES:

    Input: 27
    Output: true
    Example 2:

    Input: 0
    Output: false
    Example 3:

    Input: 9
    Output: true
    Example 4:

    Input: 45
    Output: false
*/

/*  APPROACH: Loop Iteration - O(logn)
    1. Iteratively divide the given input by 3 as long as the new value is evenly divisible by 3.
    2. If the final remainder is 1, return true and otherwise return false.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Value less than 1 cannot be a power of 3
        if(n < 1) {
            return false;
        }
        // Repeatedly divide the value by three as long as the value is evenly divisible by 3
        while(n % 3 == 0) {
            n /= 3;
        }
        // If the final remainder is 1, return true
        // Else, return false
        return n == 1;
    }
};