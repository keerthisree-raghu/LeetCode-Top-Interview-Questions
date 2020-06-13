// INTERSECTION OF TWO ARRAYS

/*  PROBLEM:
    Given two arrays, write a function to compute their intersection.

    Possible Constraints:
    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you 
    cannot load all elements into the memory at once?
*/

/*  EXAMPLES:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9] 
*/

/*  APPROACH: Hash Map
    1. Initialize a hash map to store every element of the first array.
    2. Iterate through the second array and compare each element with the element in the map.
    3. If the element is found in the map, add the element to a resultant array.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapping;
        vector<int> result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        // Add every element from the first vector into a map
        for(int i = 0; i < len1; i++) {
            mapping[nums1[i]]++;
        }
        // Iterate through the second vector to check if an element is found in the map
        for(int i = 0; i < len2; i++) {
            if(mapping.find(nums2[i]) != mapping.end() && --mapping[nums2[i]] >= 0) {
                // Append the element to the resultant vector
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};