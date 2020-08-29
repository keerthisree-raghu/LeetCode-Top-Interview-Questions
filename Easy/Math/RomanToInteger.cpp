// ROMAN TO INTEGER

/*  PROBLEM:
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I            1
    V            5
    X            10
    L            50
    C            100
    D            500
    M            1000

    For example, two is written as II in Roman numeral, just two one's added together. 
    Twelve is written as, XII, which is simply X + II. The number twenty seven is written 
    as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the 
    numeral for four is not IIII. Instead, the number four is written as IV. Because the one 
    is before the five we subtract it making four. The same principle applies to the number 
    nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

    Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
*/

/*  EXAMPLES:

    Input: "III"
    Output: 3
    Example 2:

    Input: "IV"
    Output: 4
    Example 3:

    Input: "IX"
    Output: 9
    Example 4:

    Input: "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.
    Example 5:

    Input: "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*  APPROACH: Iterative - O(n)
    1. Map each unique roman numeral symbol to its respective value.
    2. Iterate through each character in the input string.
    3. If the subsequent character has a greater value than the current character:
        a. Subtract the curent character's value from the next character's value.
        b. Append the value to the resultant string.
    4. If the subsequent character is less than the current character:
        a. Find the value of the current character.
        b. Append the value to the resultant string.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        // Map each unique roman numeral symbol to its equivalent value
        map<char, int> romanNumeral;
        romanNumeral['M'] = 1000;
        romanNumeral['D'] = 500;
        romanNumeral['C'] = 100;
        romanNumeral['L'] = 50;
        romanNumeral['X'] = 10;
        romanNumeral['V'] = 5;
        romanNumeral['I'] = 1;
        // Iterate through each character in the input string
        for(int i = 0; i < s.length(); i++) {
            // If the next character is greater than the current character
            // (I < V -> IV = 5 - 1 = 4)
            if(i + 1 < s.length() and romanNumeral[s[i+1]] > romanNumeral[s[i]]) {
                // Subtract the current character's value from the next character's value
                value += romanNumeral[s[i+1]] - romanNumeral[s[i]];
                i++;
            }
            // If the next character is less than the current character
            else{
                // Add only the current character's value
                value += romanNumeral[s[i]];
            }
        }
        return value;
    }
};