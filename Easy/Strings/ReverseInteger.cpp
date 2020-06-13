// REVERSE INTEGER

/*  PROBLEM:
    Given a 32-bit signed integer, reverse digits of an integer.

    Note:
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

/*  EXAMPLES:

    Input: 123
    Output: 321

    Input: -123
    Output: -321

    Input: 120
    Output: 21
*/

/*  APPROACH:
    1. Iteratively remove the digit in the one's place and store it in a variable.
    2. Divide the original integer by 10 to reduce it by one place value.
    3. Check for overflow conditions.
    4. Accumulate the reverse of the integer at every iteration.
    5. Return the reversed integer.

    Consider the integer x = 123.
    Iteration 1: digit = 3, rev = 0 * 10 + 3 = 3, x = 12
    Iteration 2: digit = 2, rev = 3 * 30 + 2 = 32, x = 1
    Iteration 3: digit = 1, rev = 32 * 10 + 1 = 321, x = 0
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0, digit;
        while(x != 0) {
            // Remove each individual digit from the one's place
            digit = x % 10;
            // Divide the integer by 10 to reduce it by one place value
            x /= 10;
            // Positive overflow condition
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && digit > 7)) 
                return 0;
            // Negative overflow condition
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && digit < -8)) 
                return 0;
            // Accumulate the reverse of the integer in every iteration
            rev = rev * 10 + digit;
        }
        return rev;
    }
};