// BEST TIME TO BUY AND SELL STOCK II

/*  PROBLEM:
    Say you have an array for which the ith element is the price of a given stock on day i.
    Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
    (i.e., buy one and sell one share of the stock multiple times).

    Note:
    You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

/*  EXAMPLES:

    Input: [7,1,5,3,6,4]
    Output: 7
    Explanation: 
    Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

    Input: [1,2,3,4,5]
    Output: 4
    Explanation: 
    Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
    engaging multiple transactions at the same time. You must sell before buying again.

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: 
    In this case, no transaction is done, i.e. max profit = 0.   
*/

/*  APPROACH: One Pass - O(n)
    1. Initialize a variable to store the maximum profit.
    2. Iterate through the array and check if each value is greater than the previous value.
    3. If a pair of values is found such that the current value is greater than the previous value,
        a. Find the difference between the current value (peak) and the previous value (valley).
        b. Add the difference betweeen these values to the variable tracking the maximum profit value.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize a variable to store the maximum profit value
        int maxProfitValue = 0;
        // Iterate through the array to find consecutive peaks and valleys
        for(int i = 1; i < prices.size(); i++) {
            // Check if the previous value is less than the current value (valley followed by peak)
            if(prices[i] > prices[i - 1]) {
                // Accumulate the maximum profit by finding the difference between the peak and valley
                maxProfitValue += prices[i] - prices[i - 1];
            }
        }
        return maxProfitValue;
    }
};