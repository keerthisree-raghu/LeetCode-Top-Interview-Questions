// FIRST UNIQUE CHARACTER IN A STRING

/*  PROBLEM:
    Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

    Note: 
    You may assume the string contain only lowercase English letters.
*/

/*  EXAMPLES:

    Input: s = "leetcode"
    Output: 0

    Input: s = "loveleetcode"
    Output: 2
*/

/*  APPROACH - O(n+k)
    1. Iterate through every character in the array.
    2. Increment the count of each character in a separate array.
    3. Return the index of the first character in the count array with length 1.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // Initialize an array to count the number of times each character occurs
        int count[256] = {0};
        // Iterate through every character in s and accumulate the count
        for(char i : s) {
            count[i]++;
        }
        // Return the index of the first character with length 1
        for(int i = 0; i < s.length(); i++) {
            if(count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};