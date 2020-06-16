// MERGE SORTED ARRAY

/*  PROBLEM:
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*/ 

/*  EXAMPLE:

    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3
    
    Output: [1,2,2,3,5,6]
*/

/*  APPROACH: Iterative - O(n)
    1. Initialize a new vector to merge the sorted elements from both arrays. 
    2. Iterate through the elements in both arrays to find the smallest element among both arrays.
    3. Push the element into the new vector.
    4. If elements still remain in either of the input arrays, add those elements to the resultant vector.
    5. Assign all the elements in the resultant vector to the original vector.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        // Initialize a new vector to store the merged elements
        vector<int> arr;
        // Iterate through each element of each array and push the smallest element into arr
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i++]);
            }
            else {
                arr.push_back(nums2[j++]);
            }
        }
        // If elements remain in nums1, add it to the vector
        while(i < m) {
            arr.push_back(nums1[i++]);
        }
        // If elements remain in nums2, add it to the vector
        while(j < n) {
            arr.push_back(nums2[j++]);
        }
        // Assign all elements in arr to nums1
        nums1 = arr;
    }
};