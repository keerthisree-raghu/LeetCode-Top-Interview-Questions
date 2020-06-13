// SINGLE NUMBER

/*  PROBLEM:
    Given a non-empty array of integers, every element appears twice except for one. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*  EXAMPLES:

    Input: [2,2,1]
    Output: 1

    Input: [4,1,2,1,2]
    Output: 4
*/

/*  APPROACH: Bit Manipulation - O(n)
    If we take XOR of a bit and 0, it returns that bit.
    num ^ 0 = num
    If we take XOR of two equal bits, it returns 0.
    num ^ num = 0
    If we XOR all bits together, then the only bit that will remain will be the unique bit.
    a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // XOR all bits together to find the unique number
        for(int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};