// MAXIMUM SUBARRAY

/*  PROBLEM:
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*/

/*  EXAMPLE:

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/*  APPROACH: Kadane's Algorithm - O(n)
    1. Initialize two variables to keep track of the current sum and best sum.
    2. Iterate through each value in the array and add the values to the cumulative sum.
    3. Compare the current sum with the best sum to obtain the maximum sum value.
    4. If the sum becomes negative, reset the value to 0.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        // Iterate through each element and add it to the cumulative sum
        for(int num : nums) {
            sum += num;
            // Find the maximum sum value
            maxSum = max(maxSum, sum);
            // If the sum becomes negative, reset the value to 0
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxSum;        
    }
};