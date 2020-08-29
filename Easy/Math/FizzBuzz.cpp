// FIZZ BUZZ

/*  PROBLEM:
    Write a program that outputs the string representation of numbers from 1 to n.

    But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
    For numbers which are multiples of both three and five output “FizzBuzz”.
*/

/*  EXAMPLE:

    Input: n = 15
    Output:
    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]
*/

/*  APPROACH: Math - O(n)
    1. Initialize a resultant vector to store the output of each computation.
    2. Iterate through every integer from 1 to n.
    3. If the integer is divisible by 3, append "Fizz" to the string at that index.
    4. If the integer is divisible by 5, append "Buzz" to the string at that index.
    5. If the value is not divisible by 3 or 5, convert the value to a string and append it to the string at that index.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for(int i = 1; i <= n; i++) {
            // Add "Fizz" to the string if the number is divisible by 3
            if(i % 3 == 0) {
                result[i-1] += "Fizz";
            }
            // Add "Buzz" to the string if the number is divisible by 5
            if(i % 5 == 0) {
                result[i-1] += "Buzz";
            }
            // If the number is neither divisible by 3 nor 5, convert the number to a string and add it to the result vector
            if(result[i-1].empty()) {
                result[i-1] = to_string(i);
            }
        }
        return result;
    }
};