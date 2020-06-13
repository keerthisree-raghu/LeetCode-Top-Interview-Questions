// ROTATE ARRAY

/*  PROBLEM:
    Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

/*  EXAMPLES:

    Input: [1,2,3,4,5,6,7] and k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Input: [-1,-100,3,99] and k = 2
    Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
*/

/*  APPROACH: Extra Space - O(n)
    1. Initialize a new array of the same size as the input array.
    2. Insert each element into the new array at position ((i + k) % size of array).
    3. Copy the new array to the original array.

    Consider an array [1, 2, 3, 4, 5, 6, 7], with k = 3.
    If we take the element at index 0 from the input array, we place it at position 3 in the output array because
    Index 0 -> (0 + 3) % 7 = 3 -> New Index = 3
    Similarly, we can perform the same operation for every element in the array.
    The output array would be [5, 6, 7, 1, 2, 3 ,4]
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        // Initialize a new array of the same size as the input array
        int res[len];
        // Place each element in the input array into the new array at position:
        // (i + k) % size
        for(int i = 0; i < len; i++) {
            res[(i + k) % len] = nums[i];
        }
        // Copy the elements in the new array into the old array
        for(int i = 0; i < len; i++) {
            nums[i] = res[i];
        }
    }
};