// COUNT PRIMES

/*  PROBLEM:
    Count the number of prime numbers less than a non-negative number, n.
*/

/*  EXAMPLE:

    Input: 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

/*  APPROACH: Sieve of Eratosthenes - O(n log(log n))
    1. Create an array to store boolean values of elements marked as prime or non-prime.
    2. Initially mark all elements as prime.
    3. Check if every prime number is a factor of a number in the given range.
    4. Mark the elements which satisfy the condition as false (non-prime).
    5. Iterate through the array and count the number of elements whose boolean value is true.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // Initialize an array to store boolean values
        bool isPrime[n+1];
        // Initialize all elements with the value true
        for(int i = 2; i < n; i++) {
            isPrime[i] = true;
        }
        // Check if every prime number is a factor of a number in the given range
        for(int i = 2; i < sqrt(n); i++) {
            if(!isPrime[i]) {
                continue;
            }
            for(int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        // Count the number of elements which are prime
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};