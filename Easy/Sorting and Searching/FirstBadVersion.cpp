// FIRST BAD VERSION

/*  PROBLEM:

    You are a product manager and currently leading a team to develop a new product. 
    Unfortunately, the latest version of your product fails the quality check. 
    Since each version is developed based on the previous version, all the versions 
    after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
    which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which will return whether version is bad. 
    Implement a function to find the first bad version. You should minimize the number of 
    calls to the API.
*/

/*  EXAMPLE:

    Given n = 5, and version = 4 is the first bad version.

    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true

    Then 4 is the first bad version. 
*/

/*  APPROACH: Binary Search - O(logn)
    1. Initialize left and right pointers to point to either extreme of the array of versions.
    2. Traverse the array while the left pointer index is less than the right pointer index.
    3. Calculate the mid value from the current index values of the left and right pointers.
    4. Call the isBadVersion() function and check if the mid value is the bad version.
        a. If the function call returns as false, we know that all versions preceding and including the mid value are good.
           The new search space must start from the value next to mid, so set mid = left + 1.
           G G G G G B B B B
           l       m       r
        b. If the function call returns as true, mid may or may not be the first bad version, but we know that the bad versions can only be in the right half.
           The new search space must end at the mid index (inclusive).
           G G G B B B B B B
           l       m       r
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Pre-defined API which returns whether the version is bad or not
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};