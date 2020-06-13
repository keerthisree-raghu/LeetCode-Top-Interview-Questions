// PLUS ONE

/*  PROBLEM:
    Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
    The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
    You may assume the integer does not contain any leading zero, except the number 0 itself.
*/

/*  EXAMPLES:
    
    Input: [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.

    Input: [4,3,2,9]
    Output: [4,3,3,0]
    Explanation: The array represents the integer 4329.
*/

/*  APPROACH:
    1. Iterate through the array, starting from the end and add 1 to each digit.
    2. If the value of any element becomes 10, make that digit 0 and move to the next element.
    3. If the last digit is 9, when 1 is added to it, it will become 10, so insert 1 at position 0.
*/

//  SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Initialize i as the size of the array
        int i = digits.size() - 1;
        while(i >= 0) {
            // Add one to each of the digits
            digits[i] += 1;
            // If the value of any digit becomes 10, it must be carried over
            if(digits[i] == 10) {
                // Make that digit 0
                digits[i] = 0;
                // Move to the next element
                i--;
            }
            else {
                break;
            }
        }
        // If the last digit is 9, we insert 1 at the beginning of the array (index 0)
        // 9 + 1 = 10 -> The one is carried over to index 0
        if(i == -1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};