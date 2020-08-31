// VALID PARENTHESES

/*  PROBLEM:
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
*/

/*  EXAMPLES:

    Input: s = "()"
    Output: true

    Input: s = "()[]{}"
    Output: true

    Input: s = "(]"
    Output: false

    Input: s = "([)]"
    Output: false

    Input: s = "{[]}"
    Output: true
*/

/*  APPROACH: Stack - O(n)
    1. Initialize a stack.
    2. Process each bracket of the expression one at a time.
    3. If an opening bracket is encountered, push it onto the stack.
    4. If a closing bracket is encountered, then we check the element on top of the stack. 
        a. If the element at the top of the stack is an opening bracket of the same type, then pop it off the stack and continue processing. 
        b. Else, return false as this is an invalid expression.
    5. If the stack still contains elements, it is invalid. If it is empty, it is valid.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for(char ch : s) {
            // Push each opening parenthesis into the stack
            if(ch == '(' || ch == '[' || ch == '{') {
                parentheses.push(ch);
            }
            else {
                // Check if the parenthesis is empty or if the closing parenthesis does not match the opening parenthesis
                if(parentheses.empty() || (ch == ')' && parentheses.top() != '(') || (ch == ']' && parentheses.top() != '[') || (ch == '}' && parentheses.top() != '{')) {
                    return false;
                }
                // Remove each parenthesis from the top
                parentheses.pop();
            }
        }
        // If the stack is empty, return true
        // If the stack is not empty, return false
        return parentheses.empty();
    }
};