// REMOVE DUPLICATES FROM SORTED ARRAY

/*  PROBLEM:
    Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

    Clarification:
    // nums is passed in by reference. (i.e., without making a copy)
    int len = removeDuplicates(nums);

    // any modification to nums in your function would be known by the caller.
    // using the length returned by your function, it prints the first len elements.
    for (int i = 0; i < len; i++) {
        print(nums[i]);
    }
*/

/*  EXAMPLES:

    Input: nums = [1,1,2]
    Output: 2
    Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5
    Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.   
*/

/*  APPROACH: Two Pointer Approach - O(n)
    1. Initialize two pointers i and j.
    2. Traverse through the array.
        a. Pointer j traverses through the array and increments as long as duplicate elements exist.
        b. Pointer i increments only when a unique element has been encountered.
        c. Set the value of nums[i] to be the next unique element.
    3. Return the length of the array containing only unique elements.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        // Initialize two pointers where j increments as long as duplicates exist (nums[i] == nums[j])
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                // Increment i when a unique element has been encountered
                i++;
                // Update the value of nums[i] to be the next unique element
                nums[i] = nums[j];
            }
        }
        // Return the length of the array containing only unique elements
        return i + 1;
    }
};