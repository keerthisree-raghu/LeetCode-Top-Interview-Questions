// MIN STACK

/*  PROBLEM:
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

    Constraints:
    Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

/*  EXAMPLE:

    Input:
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output:
    [null,null,null,null,-3,null,0,-2]

    Explanation:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
*/

/*  APPROACH: Two-Stacks - O(1)
    Initialize two stacks where one holds all of the elements and the other holds only the minimum values.
    
    Push:
    1. Push every element into the first stack.
    2. If the second stack is empty, consider the encountered element to be the minimum value and push it into the second stack.
    3. If the value is less than the existing minimum value, push it into the second stack.

    Pop:
    1. Pop the element from the first stack.
    2. If the element being popped is the minimum element, pop it from the minimum elements stack also.

    Top:
    1. Return the top element of the first stack.

    getMin:
    1. Return the top element of the second stack.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> elements;
    stack<int> min_values;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        // Push every element into the first stack
        elements.push(x);
        // Push the minimum value encountered thus far into the second stack
        if(min_values.empty() || x <= getMin()) {
            min_values.push(x);
        }
    }
    
    void pop() {
        // If the element being popped is the minimum element, pop it from the second stack also
        if(elements.top() == getMin()) {
            min_values.pop();
        }
        // Pop the element from the first stack
        elements.pop();
    }
    
    int top() {
        // Return the top element of the stack with all the elements
        return elements.top();
    }
    
    int getMin() {
        // Return the top element of the stack with the minimum values
        return min_values.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */