// VALID ANAGRAM

/*  PROBLEM:
    Given two strings s and t , write a function to determine if t is an anagram of s.

    Note: 
    You may assume the string contains only lowercase alphabets.
*/

/*  EXAMPLES:

    Input: s = "anagram", t = "nagaram"
    Output: true

    Input: s = "rat", t = "car"
    Output: false
*/

/*  APPROACH: Hashing - O(n)
    1. Check if the lengths of the string are equal.
    2. To hash the characters, create a counter array of size 26, capable of storing 26 English letters.
    3. Iterate through the first string and increment the counter for each letter that is encountered.
    4. Iterate through the second string.
        a. Every time a letter is encountered, decrement the count in the counter array.
           If the counter reaches 0, there is an equal number of each letter in both arrays, so they are anagrams.
        b. If the counter becomes less than 0, that means the second string has an extra letter that is not found in the first string.
           The strings are not anagrams if there is a different number of letters, so return false.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Two strings of different lengths cannot be anagrams
        if(s.size() != t.size()) {
            return false;
        }
        // Initialize a counter to store the count of each character (26 possible letters)
        int count[26] = {0};
        // Iterate through string s and increment the counter for each encountered letter
        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        // Iterate through string t
        for(int i = 0; i < t.size(); i++) {
            // For each occurrence of a letter in string t, decrement the count in the counter
            // If the counter for each letter reaches 0, then the same letters are in both strings
            count[t[i] - 'a']--;
            // If the counter for some letter in t becomes less than 0, t has an extra letter that is not in s
            if(count[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};