// LINKED LIST CYCLE

/*  PROBLEM:
    Given a linked list, determine if it has a cycle in it.
    To represent a cycle in the given linked list, we use an 
    integer pos which represents the position (0-indexed) in 
    the linked list where tail connects to. 
    If pos is -1, then there is no cycle in the linked list.
*/ 

/*  EXAMPLE:

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where tail connects to the second node.

    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where tail connects to the first node.

    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.    
*/

/*  APPROACH: 
    1. Check if the list is empty or if the pointer to the next node does not point to the head if there is only one element.
    2. Initialize a pointer which traverses the list one node at a time and another pointer which traverses the list twice as fast.
    3. If the fast pointer reaches the end of the list without encountering a loop, return false.
    4. Move the pointers according to their speed.
    5. If the while loop exits, then there is a loop in the list.
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
    bool hasCycle(ListNode *head) {
        // If the list is empty or the pointer to the next node does not point to the head when there is only one element, return false
        if(head == NULL || head->next == NULL) {
            return false;
        }
        // First pointer is a slow pointer which moves one node at a time
        // Second pointer is a fast pointer which moves two nodes at a time
        struct ListNode *slow = head, *fast = head->next;
        while(slow != fast) {
            // If the fast pointer reaches the end of the list without a loop, return false
            if(fast == NULL || fast->next == NULL) {
                return false;
            }
            // Move the pointers according to their speed
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
