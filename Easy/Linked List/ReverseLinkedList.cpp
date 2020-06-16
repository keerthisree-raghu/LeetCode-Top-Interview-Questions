// REVERSE A SINGLY LINKED LIST

/*  PROBLEM:
    Reverse a singly linked list.
*/ 

/*  EXAMPLE:

    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL
*/

/*  APPROACH: Iterative - O(n)
    1. Initialize two pointers to keep track of the previous node and current node.
    2. Move the pointer of the current node to the previous node, after storing a reference to the node next to the current node.
    3. Move the current and previous node pointers to their respective next positions.
    4. When the current node reaches the end of the list, return the previous node as the new head.
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
    ListNode* reverseList(ListNode* head) {
        // Initialise a pointer for the previous node and a pointer for the current node
        struct ListNode *prev = NULL, *curr = head;
        // Exit the loop when the current node reaches null
        while(curr) {
            // Store the address of the node next to current since a node does not have reference to previous nodes
            struct ListNode *temp = curr->next;
            // Change the current node's pointer to point to the previous node
            curr->next = prev;
            // Move the previous node to the next element
            prev = curr;
            // Move the current node to the node after the next element
            curr = temp;
        }
        return prev;
    }
};
