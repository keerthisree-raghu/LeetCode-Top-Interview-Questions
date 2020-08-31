// MISSING NUMBER

/*  PROBLEM:
    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
*/

/*  EXAMPLES:

    Input: [3,0,1]
    Output: 2

    Input: [9,6,4,2,3,5,7,0,1]
    Output: 8
*/

/*  APPROACH: Gauss Formula - O(n)
    1. Calculate the sum of n numbers i.e. the expected sum, by taking n as the length of the array.
    2. Find the actual sum of the elements in the array.
    3. Find the difference between the expected sum and actual sum.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        // Calculate the sum of n numbers, where n is the length of the array
        int expectedSum = (len) * (len + 1) / 2;
        int actualSum = 0;
        // Find the sum of the elements in the array
        for(int num : nums) {
            actualSum += num;
        }
        // Return the difference between the expected sum and actual sum
        return expectedSum - actualSum;
    }
};