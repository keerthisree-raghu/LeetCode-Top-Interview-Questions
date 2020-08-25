// CLIMBING STAIRS

/*  PROBLEM:
    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*  EXAMPLE:

    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Input: 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
*/

/*  APPROACH 1: Dynamic Programming - O(n)
    1. Initialize a dp table with the first and second values as 0 and 1 respectively.
    2. At each index, store the sum of the previous two index values.
    3. Return the value at index position n + 1.
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[1000];
        // Build the dp table based on the sum of previous values
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n + 1; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n+1];
    }
};

/*  APPROACH 2: Fibonacci Series - O(n)
    1. Initialize two variables with the values 1 and 2 respectively.
    2. Store the value of the sum of the previous two elements in a new variable.
    3. Return the value of the nth number in this series.
*/

// SOLUTION 2:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        // Find the nth Fibonacci number
        int first = 1;
        int second = 2;
        int third;
        for (int i = 3; i <= n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};