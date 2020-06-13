// TWO SUM

/*  PROBLEM:
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

/*  EXAMPLE:

    Input: [2, 7, 11, 15], target = 9
    Output: [0, 1]
    Explanation: nums[0] + nums[1] = 2 + 7 = 9
*/

/*  APPROACH: 
    1. Initialize a map to store the array values along with their indices (<value, index>).
    2. Calculate the difference between the target value and each array value.
    3. If this calculated value is present in the map, these two values can be considered as a pair, so we return their indices.
    4. If the value is not present in the map, continue storing each array element in the map.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        for(int i = 0; i < nums.size(); i++) {
            // Store the difference between the target and the array element in a variable
            int x = target - nums[i];
            // Check if the value is found in the map
            if(mapping.find(x) != mapping.end()) {
                // Return the value and the index values of both elements
                return {mapping.find(x)->second, i};
            }
            else {
                // Store the array element as <value, index>
                mapping[nums[i]] = i;
            }
        }
        return {};
    }
};