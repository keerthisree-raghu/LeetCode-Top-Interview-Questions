// COUNT AND SAY

/*  PROBLEM:
    The count-and-say sequence is the sequence of integers with the first five terms as following:
    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221

    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.

    Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. 
    You can do so recursively, in other words from the previous member read off the digits, 
    counting the number of digits in groups of the same digit.

    Note: Each term of the sequence of integers will be represented as a string.
*/

/*  EXAMPLES:

    Input: 1
    Output: "1"
    Explanation: This is the base case.

    Input: 4
    Output: "1211"
    Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", 
    "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", 
    so the answer is the concatenation of "12" and "11" which is "1211".
*/

/*  APPROACH: Two Strings
    1. Intialize a string to store the current string, with a base value of '1' when n = 1.
    2. Perform n iterations when n > 1.
    3. Initialize a buffer string to store the count of the sub-strings of repeating integers.
    4. Iterate through the current string and count the occurrence of each number.
    5. Increment the count if consecutive repeating numbers are found.
    6. Convert the count from an integer to a character by adding '0' and add it to the buffer.
    7. Add the value of the integer to the buffer.
    8. Copy the buffer string to the current string and return it.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string current;
        // Base string when n = 1
        current += '1';
        // Iterate n times when n > 1
        for(int i = 0; i < n - 1; i++) {
            string buffer;
            int j = 0;
            // Iterate through the current string
            for(j = 0; j < current.size(); j++) {
                // Count the occurrence of each number
                int count = 1;
                // Find consecutive repeating numbers 
                while(j + 1 < current.size() && current[j + 1] == current[j]) {
                    j++;
                    count++;
                }
                // Convert the integer to character and add the count to the buffer
                buffer.push_back(count + '0');
                // Add the value of the integer
                buffer.push_back(current[j]);
            }
            // Copy the buffer to the current string
            current = buffer;
        }
        return current;
    }
};