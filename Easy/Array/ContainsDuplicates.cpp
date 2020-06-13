// CONTAINS DUPLICATES

/*  PROBLEM:
    Given an array of integers, find if the array contains any duplicates.
    Your function should return true if any value appears at least twice in the array, 
    and it should return false if every element is distinct.
*/

/*  EXAMPLES:

    Input: [1,2,3,1]
    Output: true

    Input: [1,2,3,4]
    Output: false

    Input: [1,1,1,3,3,4,3,2,4,2]
    Output: true
*/

/*  APPROACH: Sets - O(n)
    1. Create a new set to store the distinct values from the input array.
    2. Iterate through the array and check if the number is already found in the set.
        a. If the number exists in the set, it means that a duplicate exists, so return true.
        b. If the number does not exist in the set, it is a distinct value, so insert it into the set.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create a new set to store unique values from the input array
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            // If the number is already found in the set, return true (duplicates exist)
            if(s.find(nums[i]) != s.end()) {
                return true;
            }
            // If the number has not been found, insert it into the set (unique number)
            else {
                s.insert(nums[i]);
            }
        }
        return false;
    }
};