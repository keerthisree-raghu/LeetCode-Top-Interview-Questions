// REVERSE BITS

/*  PROBLEM:
    Reverse bits of a given 32 bits unsigned integer.
*/

/*  EXAMPLES:

    Input: 00000010100101000001111010011100
    Output: 00111001011110000010100101000000
    Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

    Input: 11111111111111111111111111111101
    Output: 10111111111111111111111111111111
    Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
*/

/*  APPROACH: Bit Manipulation - O(1)
    A bit at position i must be shifted to position (31 - i).
    1. Initialize a power value to be 31.
    2. Retrieve the right-most bit of the given bit string by applying AND operation.
    3. Accumulate the reversed bit in each iteration.
    4. Iterate through the bit string from right to left by right-shifting.
    5. Decrement the value of the power.
    6. Exit the loop when the value of the input bit string becomes 0.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // A bit at position i must be shifted to position (31 - i)
        int reversed = 0, power = 31;
        while(n) {
            // Retrieve the right-most bit of the bit string by applying AND operation
            // Accumulate the reversed bit
            reversed += (n & 1) << power;
            // Iterate through the bit string from right to left
            n >>= 1;
            // Decrement the value of the power
            power--;
        }
        return reversed;
    }
};