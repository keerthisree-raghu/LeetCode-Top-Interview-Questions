// HAMMING DISTANCE

/*  PROBLEM:
    Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
*/

/*  EXAMPLES:

    Input: 00000000000000000000000000001011
    Output: 3
    Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

    Input: 00000000000000000000000010000000
    Output: 1
    Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

    Input: 11111111111111111111111111111101
    Output: 31
    Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
*/

/*  APPROACH: Bit Manipulation - O(1)
    1. Iterate through each bit of the input value.
    2. Perform and operation with 1 and increment the count.
    3. Exit the loop when the value becomes 0.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int setBits = 0;
        while(n) {
            // Check if each bit is set (1)
            setBits += n & 1;
            // Move to next bit
            n >>= 1;
        }
        return setBits;
    }
};