// IMPLEMENT strStr()

/*  PROBLEM:
    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/*  EXAMPLES:

    Input: haystack = "hello", needle = "ll"
    Output: 2

    Input: haystack = "aaaaa", needle = "bba"
    Output: -1
*/

/*  APPROACH: 
    1. Calculate and store the lengths of the needle and haystack.
    2. Iterate over the haystack and compare the substrings starting at each character.
    3. Check if each character in the needle has been matched consecutively in the haystack.
    4. Return the index of the first occurrence of the needle.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        
        // Base cases
        if(!needleLength)
            return 0;
        if(!haystackLength || (haystackLength < needleLength))
            return -1;
        
        int length = haystackLength - needleLength;

        // Iterate over the haystack and compare substrings starting at each character
        for(int i = 0; i <= length; i++) {
            // Next character in haystack to compare with needle
            int h = i;
            // Next character in needle to compare with haystack
            int n = 0;
            while(h < haystackLength && n < needleLength && haystack[h] == needle[n]) {
                // Move to next letter
                h++;
                n++;
            }
            // Check if each character of needle has been matched
            if(!needle[n])
                // Return index;
                return i;
        }
        // Not found
        return -1;
    } 
};