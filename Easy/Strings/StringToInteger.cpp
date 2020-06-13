// STRING TO INTEGER (atoi)

/*  PROBLEM:
    Implement atoi which converts a string to an integer.
    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
    Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as 
    possible, and interprets them as a numerical value. The string can contain additional characters after those that form the 
    integral number, which are ignored and have no effect on the behavior of this function. If the first sequence of non-whitespace 
    characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only 
    whitespace characters, no conversion is performed. If no valid conversion could be performed, a zero value is returned.

    Note:
    1. Only the space character ' ' is considered as whitespace character.
    2. Assume we are dealing with an environment which could only store integers within 
       the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out 
       of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/

/*  EXAMPLES:

    Input: "42"
    Output: 42

    Input: "   -42"
    Output: -42
    Explanation: 
    The first non-whitespace character is '-', which is the minus sign. 
    Then take as many numerical digits as possible, which gets 42.

    Input: "4193 with words"
    Output: 4193
    Explanation: 
    Conversion stops at digit '3' as the next character is not a numerical digit.

    Input: "words and 987"
    Output: 0
    Explanation: 
    The first non-whitespace character is 'w', which is not a numerical 
    digit or a +/- sign. Therefore no valid conversion could be performed.

    Input: "-91283472332"
    Output: -2147483648
    Explanation: 
    The number "-91283472332" is out of the range of a 32-bit signed integer.
    Thefore INT_MIN (−231) is returned.
*/

/*  APPROACH: Iterative
    1. Find the first non-space character in the string.
    2. Check if the character is a '+' or '-' and determine the sign of the integer accordingly.
    3. Iterate through the string and convert every character to its integer equivalent as long as it is between 0 and 9.
    4. Check for overflow and underflow conditions.
    5. Multiply the resulting integer value with the sign and return it.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long integer = 0, sign = 1;
        for(int i = 0; i < str.size(); i++) {
            // Store the index of the first non-space character in i
            i = str.find_first_not_of(' ');
            // Find the sign of the integer
            if(str[i] == '-' || str[i] == '+') {
                sign = (str[i++] == '-') ? -1 : 1;
            }
            // Check if the range of the characters is between 0 and 9
            while('0' <= str[i] && str[i] <= '9') {
                // Convert the characters into integers
                integer = integer * 10 + (str[i++] - '0');
                // Check for overflow
                if(integer * sign >= INT_MAX) {
                    return INT_MAX;
                }
                // Check for underflow
                if(integer *sign <= INT_MIN) {
                    return INT_MIN;
                }
            }
        }
        // Multiply the integer with the sign and return
        return integer * sign;
    }
};