// VALID PALINDROME

/*  PROBLEM:
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Note: 
    For the purpose of this problem, we define empty string as valid palindrome.
*/

/*  EXAMPLES:

    Input: "A man, a plan, a canal: Panama"
    Output: true

    Input: "race a car"
    Output: false
*/

/*  APPROACH: Hashing - O(n)
    1. Intialize two pointers to point to the extreme ends of the string.
    2. Iterate through the string while incrementing the left pointer and decrementing the right pointer until the condition (left < right) breaks.
    3. If a non-alphabet character is encountered, move the respective pointers to the next index.
    4. Convert each alphabet character at both pointer indices to lowercase and compare the value with each other.
        a. If the characters are equal, return true.
        b. If the characters are not equal, return false.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize a left and right pointer
        int l = 0, r = s.size() - 1;
        while(l < r) {
            // If the character at the left pointer position is not an alphabet, move to the next index
            while(l < r && !isalnum(s[l])) {
                l++;
            }
            // If the character at the right pointer position is not an alphabet, move to the next index
            while(l < r && !isalnum(s[r])) {
                r--;
            }
            // Check if each character at the left and right pointers, in their lowercase form, are equal
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            // Move pointers to next index
            l++;
            r--;
        }
        return true;
    }
};