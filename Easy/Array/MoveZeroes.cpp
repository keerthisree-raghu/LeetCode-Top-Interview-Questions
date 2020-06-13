// CONTAINS DUPLICATES

/*  PROBLEM:
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

/*  EXAMPLE:

    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/

/*  APPROACH: 
    1. Initialize a pointer to track the non-zero elements.
    2. If the currently processed element is non-zero, we must append it behind the last non-zero element.
    3. After the elements in the array have been processed according to the condition, the non-zero elements are at the front of the array.
    4. Iterate from the location of the last non-zero element till the end of the array and fill the positions with 0.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int lastNonZeroIndex = 0;
        // If the current element is not 0, then append it behind the last non-zero element.
        for(int i = 0; i < len; i++) {
            if(nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];                
            }
        }
        // After the array elements have been processed, all the non-zero elements are at the beginning of the array.
        // We must fill the remaining portion of the array with 0's.
        for(int i = lastNonZeroIndex; i < len; i++) {
            nums[i] = 0;
        }
    }
};