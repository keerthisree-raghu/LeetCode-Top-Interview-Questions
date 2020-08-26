// SHUFFLE AN ARRAY

/*  PROBLEM:
    Shuffle a set of numbers without duplicates.
*/

/*  EXAMPLES:

    // Init an array with set 1, 2, and 3.
    int[] nums = {1,2,3};
    Solution solution = new Solution(nums);

    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
    solution.shuffle();

    // Resets the array back to its original configuration [1,2,3].
    solution.reset();

    // Returns the random shuffling of array [1,2,3].
    solution.shuffle();
*/

/*  APPROACH: Fisher-Yates Algorithm - O(n)
    Store the array in another vector called "original".

    Reset:
    1. Return the original array.
    
    Shuffle:
    1. Generate a random index value between the current index and last index of the array.
    2. Swap the elements at the current index and the new index.
    
    NOTE: 
    The next range from which we select a random index will not include the most recently processed one. 
    One small, yet important detail is that it is possible to swap an element with itself - otherwise, some array permutations would be more likely than others.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled_array(original);
        for (int i = 0; i < shuffled_array.size(); i++) {
            // Generate a random index value between the current index and last index of the array
            int pos = rand() % (shuffled_array.size() - i);
            // Swap the elements at the current index and new index
            swap(shuffled_array[i + pos], shuffled_array[i]);
        }
        return shuffled_array;
    }
};