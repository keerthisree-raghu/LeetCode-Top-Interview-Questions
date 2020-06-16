// REMOVE Nth NODE FROM END OF LIST

/*  PROBLEM:
    Given a linked list, remove the n-th node from the end of list and return its head.

    Note:
    Given n will always be valid.
*/ 

/*  EXAMPLE:

    Input: 1->2->3->4->5, n = 2.
    Output: 1->2->3->5
*/

/*  APPROACH: One-Pass - O(n)
    1. Initialize two pointers:
        a. One pointer is used to calculate the length of the list.
        b. The other pointer is used to keep track of the target node.
    2. Traverse the list such that the first pointer advances the list by n + 1 steps while the second pointer starts from the beginning of the list.
    3. The pointers are separated by a gap of n nodes until the first pointer arrives past the last node.
    4. The second pointer will be pointing at the nth node from the end and we relink the pointer of the node referenced by the second pointer to point to the node's next node.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Linked list definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *check = head, *target = head;
        int length = 0;
        // Traverse till the end of the list to calculate the length
        while(check) {
            check = check->next;
            // If the length is greater than the given value of n, move the target pointer
            if(length > n) {
                target = target->next;
            }
            length++;
        }
        // Once the check pointer has reached the end of the list, check if the length is greater than the value of n
        if(length > n) {
            // The target pointer is next to the node to be deleted, so relink the node to the next node
            target->next = target->next->next;
        }
        else {
            head = head->next;
        }
        return head;
    }
};
