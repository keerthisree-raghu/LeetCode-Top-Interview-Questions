// BEST TIME TO BUY AND SELL STOCK

/*  PROBLEM:
    Say you have an array for which the ith element is the price of a given stock on day i.
    If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

    Note that you cannot sell a stock before you buy one.
*/

/*  EXAMPLES:

    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                 Not 7-1 = 6, as selling price needs to be larger than buying price.

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*  APPROACH: One Pass - O(n)
    1. Initialize a variable to store the minimum price among the given prices.
    2. Initialize a variable to store the maximum profit that can be obtained by subtracting the selling price and minimum price so far.
    3. Iterate through all of the prices and calculate the minimum possible price.
    4. Calculate the maximum profit that is possible and return this value.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // minPrice corresponds to the lowest price so far
        int minPrice = 99999;
        // maxprofit = selling price - minPrice
        int maxProfit = 0;
        // Iterate through all of the prices to find the maximum profit that can be generated
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            } 
        }
        return maxProfit;
    }
};