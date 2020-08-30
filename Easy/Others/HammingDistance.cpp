// HAMMING DISTANCE

/*  PROBLEM:
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    Given two integers x and y, calculate the Hamming distance.
    
    Note:
    0 ≤ x, y < 231.
*/

/*  EXAMPLES:

    Input: x = 1, y = 4
    Output: 2
    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑
    The above arrows point to positions where the corresponding bits are different.
*/

/*  APPROACH: Bit Manipulation - O(n)
    When XOR is performed between two numbers, only the corresponding bits which are different are set.
    
    Example:
    1  ->   0 0 0 1 
    4  -> ^ 0 1 0 0
           ---------
            0 1 0 1
    
    If we count the number of set bits, we can return the number of different corresponding bits between the two numbers.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        // Calculate the xor value of the two numbers 
        int val = x xor y;
        int setBits = 0;
        while(val) {
            // Check if each bit is set (1)
            setBits += val & 1;
            // Move to next bit
            val >>= 1;
        }
        return setBits;
    }
};