// LONGEST COMMON PREFIX

/*  PROBLEM:
    Write a function to find the longest common prefix string amongst an array of strings.
*/

/*  EXAMPLES:

    Input: ["flower","flow","flight"]
    Output: "fl"

    Input: ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
*/

/*  APPROACH: 
    1. If the vector is empty, return an empty string.
    2. Iterate through the vector and calculate the length of the shortest string. 
    3. Initialize an empty string to store the resultant substring.
    4. Compare the first minLength letters in the first substring with the letters in the other substrings.
    5. If the letters match, append it to the resultant string. Otherwise, return the resultant string.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Helper function to return minimum length
    int min(int a, int b) {
        return a > b ? a : b;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        // Base case
        if(!length) {
            return "";
        }
        
        // Initialize the minimum length as the length of the first string
        int minLength = strs[0].length();
        
        // Iterate through the vector to find the shortest string by comparison
        for(int i = 0; i < length; i++) {
            minLength = min(strs[i].length(), minLength);
        }
        
        // Initialize an empty resultant string
        string result = "";
        int i = 0;
        while(i < minLength) {
            // Store the first minLength letters in the first substring
            char ch = strs[0][i];
            // Iterate through the other strings to see if the letters match the letters in the stored substring
            for(int j = 1; j < length; j++) {
                if(strs[j][i] != ch) {
                    return result;
                }
            }
            // Append the substring to the result
            result += ch;
            i++;
        }
        return result;
    }
};